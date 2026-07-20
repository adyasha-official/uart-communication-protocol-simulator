#ifndef FRAME_QUEUE_H
#define FRAME_QUEUE_H

#include <stdbool.h>

#include "uart_frame.h"

#define FRAME_QUEUE_SIZE 8

typedef struct
{
    UART_Frame buffer[FRAME_QUEUE_SIZE];

    unsigned int head;
    unsigned int tail;
    unsigned int count;

} FrameQueue;

void frame_queue_init(FrameQueue *queue);

bool frame_queue_push(FrameQueue *queue,
                      const UART_Frame *frame);

bool frame_queue_pop(FrameQueue *queue,
                     UART_Frame *frame);

bool frame_queue_is_empty(const FrameQueue *queue);

bool frame_queue_is_full(const FrameQueue *queue);

#endif