#ifndef UART_FRAME_H
#define UART_FRAME_H

#include <stdint.h>
#include <stdbool.h>

#include "uart_config.h"

/*------------------------------------------------*/
/* UART Frame Structure */
/*------------------------------------------------*/

typedef struct
{
    bool start_bit;

    uint8_t data;

    bool parity_bit;

    uint8_t checksum;

    bool stop_bit;

} UART_Frame;

/*------------------------------------------------*/
/* UART Frame Validation Status */
/*------------------------------------------------*/

typedef enum
{
    UART_FRAME_OK = 0,
    UART_FRAME_START_ERROR,
    UART_FRAME_STOP_ERROR,
    UART_FRAME_PARITY_ERROR,
    UART_FRAME_CHECKSUM_ERROR

} UART_FrameStatus;

/*------------------------------------------------*/
/* Function Prototypes */
/*------------------------------------------------*/

UART_Frame uart_pack_frame(uint8_t data,
                           const UART_Config *config);

uint8_t uart_unpack_frame(const UART_Frame *frame);

UART_FrameStatus uart_validate_frame(const UART_Frame *frame,
                                     const UART_Config *config);

bool uart_calculate_parity(uint8_t data);

void uart_print_frame(const UART_Frame *frame,
                      const UART_Config *config);

#endif