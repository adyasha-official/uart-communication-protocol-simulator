#include "uart_channel.h"
#include "frame_queue.h"

static FrameQueue channel_queue;
static bool initialized = false;

static void uart_channel_init(void)
{
    if (!initialized)
    {
        frame_queue_init(&channel_queue);
        initialized = true;
    }
}

bool uart_channel_send(const UART_Frame *frame)
{
    uart_channel_init();

    return frame_queue_push(&channel_queue, frame);
}

bool uart_channel_receive(UART_Frame *frame)
{
    uart_channel_init();

    return frame_queue_pop(&channel_queue, frame);
}