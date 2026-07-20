#ifndef UART_FRAME_H
#define UART_FRAME_H

#include <stdint.h>
#include <stdbool.h>

#include "uart_config.h"

typedef struct
{
    bool start_bit;

    uint8_t data;

    bool parity_bit;

    bool stop_bit;

} UART_Frame;

/* Function Prototypes */

UART_Frame uart_pack_frame(uint8_t data,
                           const UART_Config *config);

uint8_t uart_unpack_frame(const UART_Frame *frame);
bool uart_validate_frame(const UART_Frame *frame,
                         const UART_Config *config);
bool uart_calculate_parity(uint8_t data);

void uart_print_frame(const UART_Frame *frame,
                      const UART_Config *config);

#endif