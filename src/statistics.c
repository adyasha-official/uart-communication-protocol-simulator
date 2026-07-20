#include <stdio.h>

#include "statistics.h"

/*------------------------------------------------*/
/* Private Statistics Variable */
/*------------------------------------------------*/

static UART_Statistics stats;

/*------------------------------------------------*/

void statistics_init(void)
{
    stats.bytes_transmitted = 0;
    stats.bytes_received = 0;

    stats.parity_errors = 0;
    stats.checksum_errors = 0;

    stats.frames_dropped = 0;
}

/*------------------------------------------------*/

void statistics_increment_tx(void)
{
    stats.bytes_transmitted++;
}

/*------------------------------------------------*/

void statistics_increment_rx(void)
{
    stats.bytes_received++;
}

/*------------------------------------------------*/

void statistics_increment_parity_error(void)
{
    stats.parity_errors++;
}

/*------------------------------------------------*/

void statistics_increment_checksum_error(void)
{
    stats.checksum_errors++;
}

/*------------------------------------------------*/

void statistics_increment_frame_drop(void)
{
    stats.frames_dropped++;
}

/*------------------------------------------------*/

UART_Statistics statistics_get(void)
{
    return stats;
}

/*------------------------------------------------*/

void statistics_print(void)
{
    printf("\n===== UART Statistics =====\n");

    printf("Bytes Transmitted : %u\n", stats.bytes_transmitted);
    printf("Bytes Received    : %u\n", stats.bytes_received);

    printf("Parity Errors     : %u\n", stats.parity_errors);
    printf("Checksum Errors   : %u\n", stats.checksum_errors);

    printf("Frames Dropped    : %u\n", stats.frames_dropped);
}