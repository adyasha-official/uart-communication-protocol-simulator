#include <stdio.h>

#include "frame_queue.h"
#include "uart_config.h"
#include "uart_frame.h"

int main(void)
{
    FrameQueue queue;
    UART_Config config;

    UART_Frame tx_frame;
    UART_Frame rx_frame;

    uart_config_default(&config);

    frame_queue_init(&queue);

    tx_frame = uart_pack_frame('A', &config);
    frame_queue_push(&queue, &tx_frame);

    tx_frame = uart_pack_frame('B', &config);
    frame_queue_push(&queue, &tx_frame);

    tx_frame = uart_pack_frame('C', &config);
    frame_queue_push(&queue, &tx_frame);

    printf("Receiving Frames\n\n");

    while (frame_queue_pop(&queue, &rx_frame))
    {
        uart_print_frame(&rx_frame, &config);
    }

    return 0;
}