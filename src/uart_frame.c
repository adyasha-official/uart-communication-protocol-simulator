#include <stdio.h>

#include "uart_frame.h"

bool uart_calculate_parity(uint8_t data)
{
    bool parity = false;

    while(data)
    {
        parity ^= (data & 1);

        data >>= 1;
    }

    return parity;
}

UART_Frame uart_pack_frame(uint8_t data,
                           const UART_Config *config)
{
    UART_Frame frame;

    frame.start_bit = 0;

    frame.data = data;

    frame.stop_bit = 1;

    if(config->parity == UART_PARITY_NONE)
    {
        frame.parity_bit = 0;
    }
    else if(config->parity == UART_PARITY_EVEN)
    {
        frame.parity_bit = uart_calculate_parity(data);
    }
    else
    {
        frame.parity_bit = !uart_calculate_parity(data);
    }

    return frame;
}

uint8_t uart_unpack_frame(const UART_Frame *frame)
{
    return frame->data;
}

void uart_print_frame(const UART_Frame *frame,
                      const UART_Config *config)
{
    printf("\nUART Frame\n");

    printf("----------------------\n");

    printf("Start Bit : %d\n",frame->start_bit);

    printf("Data      : %u (0x%02X)\n",
            frame->data,
            frame->data);

    if(config->parity == UART_PARITY_NONE)
    {
        printf("Parity    : Disabled\n");
    }
    else
    {
        printf("Parity    : %d\n",
                frame->parity_bit);
    }

    printf("Stop Bit  : %d\n",
            frame->stop_bit);
}