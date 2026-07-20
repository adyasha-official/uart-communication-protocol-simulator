#include <stdio.h>

#include "uart_driver.h"
#include "uart_config.h"

int main(void)
{
    UART_Config config;
    uint8_t data;

    uart_config_default(&config);

    uart_init(&config);

    uart_transmit('H');
uart_transmit('e');
uart_transmit('l');
uart_transmit('l');
uart_transmit('o');

    printf("Receiving...\n\n");

    while (uart_receive(&data))
    {
        printf("%c ", data);
    }

    printf("\n");

    return 0;
}