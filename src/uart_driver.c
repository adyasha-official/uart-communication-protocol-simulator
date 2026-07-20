#include "uart_driver.h"

#include "uart_channel.h"
#include "uart_frame.h"
#include "ring_buffer.h"

/* Private Driver Variables */

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

    frame = uart_pack_frame(data, &uart_config);

    return uart_channel_send(&frame);
}

/*------------------------------------------------*/

bool uart_receive(uint8_t *data)
{
    UART_Frame frame;

    if (!uart_channel_receive(&frame))
    {
        return false;
    }

    if (!uart_validate_frame(&frame, &uart_config))
    {
        return false;
    }

    *data = uart_unpack_frame(&frame);

    return true;
}