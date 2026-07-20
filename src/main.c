#include <stdio.h>

#include "uart_config.h"
#include "uart_frame.h"

int main(void)
{
    UART_Config config;

    uart_config_default(&config);

    UART_Frame frame = uart_pack_frame('A',
                                       &config);

    uart_print_frame(&frame,
                     &config);

    printf("\nRecovered Character : %c\n",
            uart_unpack_frame(&frame));

    return 0;
}