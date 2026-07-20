#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

/* Buffer Capacity */
#define BUFFER_SIZE 8

/* Ring Buffer Structure */
typedef struct
{
    uint8_t buffer[BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
    uint16_t count;

} RingBuffer;

/* Function Prototypes */

void ring_buffer_init(RingBuffer *rb);

bool ring_buffer_write(RingBuffer *rb, uint8_t data);

bool ring_buffer_read(RingBuffer *rb, uint8_t *data);

bool ring_buffer_is_full(const RingBuffer *rb);

bool ring_buffer_is_empty(const RingBuffer *rb);

uint16_t ring_buffer_size(const RingBuffer *rb);

uint16_t ring_buffer_capacity(void);

#endif