#include <stdio.h>

#include "uart_frame.h"
#include "checksum.h"

/*------------------------------------------------*/
/* Calculate Parity */
/*------------------------------------------------*/

bool uart_calculate_parity(uint8_t data)
{
    bool parity = false;

    while (data)
    {
        parity ^= (data & 1);
        data >>= 1;
    }

    return parity;
}

/*------------------------------------------------*/
/* Pack UART Frame */
/*------------------------------------------------*/

UART_Frame uart_pack_frame(uint8_t data,
                           const UART_Config *config)
{
    UART_Frame frame;

    frame.start_bit = 0;
    frame.data = data;
    frame.stop_bit = 1;

    switch (config->parity)
    {
    case UART_PARITY_NONE:
        frame.parity_bit = 0;
        break;

    case UART_PARITY_EVEN:
        frame.parity_bit = uart_calculate_parity(data);
        break;

    case UART_PARITY_ODD:
        frame.parity_bit = !uart_calculate_parity(data);
        break;

    default:
        frame.parity_bit = 0;
        break;
    }

    /* Generate checksum */
    frame.checksum = checksum_generate(frame.data);

    return frame;
}

/*------------------------------------------------*/
/* Unpack UART Frame */
/*------------------------------------------------*/

uint8_t uart_unpack_frame(const UART_Frame *frame)
{
    return frame->data;
}

/*------------------------------------------------*/
/* Validate UART Frame */
/*------------------------------------------------*/

UART_FrameStatus uart_validate_frame(const UART_Frame *frame,
                                     const UART_Config *config)
{
    bool expected_parity;

    /* Validate start bit */
    if (frame->start_bit != 0)
    {
        return UART_FRAME_START_ERROR;
    }

    /* Validate stop bit */
    if (frame->stop_bit != 1)
    {
        return UART_FRAME_STOP_ERROR;
    }

    /* Validate parity */
    switch (config->parity)
    {
    case UART_PARITY_NONE:
        break;

    case UART_PARITY_EVEN:
        expected_parity = uart_calculate_parity(frame->data);

        if (expected_parity != frame->parity_bit)
        {
            return UART_FRAME_PARITY_ERROR;
        }

        break;

    case UART_PARITY_ODD:
        expected_parity = !uart_calculate_parity(frame->data);

        if (expected_parity != frame->parity_bit)
        {
            return UART_FRAME_PARITY_ERROR;
        }

        break;

    default:
        return UART_FRAME_PARITY_ERROR;
    }

    /* Validate checksum */
    if (frame->checksum != checksum_generate(frame->data))
    {
        return UART_FRAME_CHECKSUM_ERROR;
    }

    return UART_FRAME_OK;
}

/*------------------------------------------------*/
/* Print UART Frame */
/*------------------------------------------------*/

void uart_print_frame(const UART_Frame *frame,
                      const UART_Config *config)
{
    printf("\nUART Frame\n");
    printf("----------------------\n");

    printf("Start Bit : %d\n", frame->start_bit);

    printf("Data      : %u (0x%02X)\n",
           frame->data,
           frame->data);

    if (config->parity == UART_PARITY_NONE)
    {
        printf("Parity    : Disabled\n");
    }
    else
    {
        printf("Parity    : %d\n", frame->parity_bit);
    }

    printf("Checksum  : 0x%02X\n", frame->checksum);

    printf("Stop Bit  : %d\n", frame->stop_bit);
}