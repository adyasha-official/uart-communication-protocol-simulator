#include <stdio.h>
#include <stdint.h>
#include "ring_buffer.h"

int main(void)
{
    RingBuffer rb;
    uint8_t data;

    ring_buffer_init(&rb);

    printf("========== Test 3 : Wrap Around ==========\n\n");

    /* Fill Buffer */
    for (uint8_t i = 1; i <= 8; i++)
    {
        ring_buffer_write(&rb, i * 10);
    }

    printf("Reading First Three Elements\n\n");

    for (int i = 0; i < 3; i++)
    {
        ring_buffer_read(&rb, &data);
        printf("%d\n", data);
    }

    printf("\nWriting New Elements\n\n");

    ring_buffer_write(&rb, 90);
    ring_buffer_write(&rb, 100);
    ring_buffer_write(&rb, 110);

    printf("Reading Remaining Elements\n\n");

    while (!ring_buffer_is_empty(&rb))
    {
        ring_buffer_read(&rb, &data);
        printf("%d\n", data);
    }

    return 0;
}