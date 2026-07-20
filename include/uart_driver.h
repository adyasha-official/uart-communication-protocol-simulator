#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include <stdbool.h>
#include <stdint.h>

#include "uart_config.h"

bool uart_init(const UART_Config *config);

bool uart_transmit(uint8_t data);

bool uart_receive(uint8_t *data);

#endif