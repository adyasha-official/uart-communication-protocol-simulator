#include "frame_queue.h"

void frame_queue_init(FrameQueue *queue)
{
    queue->head = 0;
    queue->tail = 0;
    queue->count = 0;
}

bool frame_queue_is_empty(const FrameQueue *queue)
{
    return (queue->count == 0);
}

bool frame_queue_is_full(const FrameQueue *queue)
{
    return (queue->count == FRAME_QUEUE_SIZE);
}

bool frame_queue_push(FrameQueue *queue,
                      const UART_Frame *frame)
{
    if (frame_queue_is_full(queue))
    {
        return false;
    }

    queue->buffer[queue->tail] = *frame;

    queue->tail = (queue->tail + 1) % FRAME_QUEUE_SIZE;

    queue->count++;

    return true;
}

bool frame_queue_pop(FrameQueue *queue,
                     UART_Frame *frame)
{
    if (frame_queue_is_empty(queue))
    {
        return false;
    }

    *frame = queue->buffer[queue->head];

    queue->head = (queue->head + 1) % FRAME_QUEUE_SIZE;

    queue->count--;

    return true;
}