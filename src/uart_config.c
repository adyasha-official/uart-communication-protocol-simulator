#include <stdio.h>
#include "uart_config.h"

void uart_config_default(UART_Config *config)
{
    config->baud_rate = 9600;
    config->data_bits = 8;
    config->parity = UART_PARITY_EVEN;
    config->stop_bits = 1;
}

void uart_print_config(const UART_Config *config)
{
    printf("UART Configuration\n");
    printf("----------------------------\n");
    printf("Baud Rate : %u\n", config->baud_rate);
    printf("Data Bits : %u\n", config->data_bits);

    printf("Parity    : ");

    switch(config->parity)
    {
        case UART_PARITY_NONE:
            printf("None\n");
            break;

        case UART_PARITY_EVEN:
            printf("Even\n");
            break;

        case UART_PARITY_ODD:
            printf("Odd\n");
            break;
    }

    printf("Stop Bits : %u\n", config->stop_bits);
}