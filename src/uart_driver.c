#include "uart_driver.h"

#include "uart_channel.h"
#include "uart_frame.h"
#include "ring_buffer.h"
#include "error_injector.h"
#include "statistics.h"
#include "logger.h"

/*------------------------------------------------*/
/* Private Driver Variables */
/*------------------------------------------------*/

static UART_Config uart_config;

/*------------------------------------------------*/

bool uart_init(const UART_Config *config)
{
    uart_config = *config;

    return true;
}

/*------------------------------------------------*/

bool uart_transmit(uint8_t data)
{
    UART_Frame frame;

    /* Create UART Frame */
    frame = uart_pack_frame(data, &uart_config);

    /* Display Frame */
    uart_print_frame(&frame, &uart_config);

    /* Inject Error (if enabled) */
    error_inject_frame(&frame);

    /* Send Frame */
    if (uart_channel_send(&frame))
    {
        statistics_increment_tx();
        log_info("Frame transmitted");
        return true;
    }

    log_error("Transmission failed");

    return false;
}

/*------------------------------------------------*/

bool uart_receive(uint8_t *data)
{
    UART_Frame frame;

    while (uart_channel_receive(&frame))
    {
        UART_FrameStatus status;

        status = uart_validate_frame(&frame, &uart_config);

        if (status != UART_FRAME_OK)
        {
            switch (status)
            {
                case UART_FRAME_START_ERROR:
                    log_error("Invalid start bit.");
                    break;

                case UART_FRAME_STOP_ERROR:
                    log_error("Invalid stop bit.");
                    break;

                case UART_FRAME_PARITY_ERROR:
                    statistics_increment_parity_error();
                    log_error("Parity error detected.");
                    break;

                case UART_FRAME_CHECKSUM_ERROR:
                    statistics_increment_checksum_error();
                    log_error("Checksum error detected.");
                    break;

                default:
                    log_error("Unknown frame error.");
                    break;
            }

            statistics_increment_frame_drop();

            continue;
        }

        *data = uart_unpack_frame(&frame);

        statistics_increment_rx();
        log_info("Frame received successfully");

        return true;
    }

    return false;
}