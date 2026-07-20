#ifndef STATISTICS_H
#define STATISTICS_H

#include <stdint.h>

/*------------------------------------------------*/
/* UART Statistics Structure */
/*------------------------------------------------*/

typedef struct
{
    uint32_t bytes_transmitted;
    uint32_t bytes_received;

    uint32_t parity_errors;
    uint32_t checksum_errors;

    uint32_t frames_dropped;

} UART_Statistics;

/*------------------------------------------------*/
/* Function Prototypes */
/*------------------------------------------------*/

void statistics_init(void);

void statistics_increment_tx(void);
void statistics_increment_rx(void);

void statistics_increment_parity_error(void);
void statistics_increment_checksum_error(void);

void statistics_increment_frame_drop(void);

UART_Statistics statistics_get(void);

void statistics_print(void);

#endif