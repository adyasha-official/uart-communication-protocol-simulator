#include "ring_buffer.h"

void ring_buffer_init(RingBuffer *rb)
{
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

bool ring_buffer_is_full(const RingBuffer *rb)
{
    return rb->count == BUFFER_SIZE;
}

bool ring_buffer_is_empty(const RingBuffer *rb)
{
    return rb->count == 0;
}

uint16_t ring_buffer_size(const RingBuffer *rb)
{
    return rb->count;
}

uint16_t ring_buffer_capacity(void)
{
    return BUFFER_SIZE;
}

bool ring_buffer_write(RingBuffer *rb, uint8_t data)
{
    if (ring_buffer_is_full(rb))
    {
        return false;
    }

    rb->buffer[rb->head] = data;

    rb->head = (rb->head + 1) % BUFFER_SIZE;

    rb->count++;

    return true;
}

bool ring_buffer_read(RingBuffer *rb, uint8_t *data)
{
    if (ring_buffer_is_empty(rb))
    {
        return false;
    }

    *data = rb->buffer[rb->tail];

    rb->tail = (rb->tail + 1) % BUFFER_SIZE;

    rb->count--;

    return true;
}