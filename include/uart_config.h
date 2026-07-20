#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#include <stdint.h>
#include <stdbool.h>

/* UART Parity Mode */
typedef enum
{
    UART_PARITY_NONE = 0,
    UART_PARITY_EVEN,
    UART_PARITY_ODD

} UART_Parity;

/* UART Configuration Structure */
typedef struct
{
    uint32_t baud_rate;
    uint8_t data_bits;
    UART_Parity parity;
    uint8_t stop_bits;

} UART_Config;

/* Function Prototypes */

void uart_config_default(UART_Config *config);

void uart_print_config(const UART_Config *config);

#endif