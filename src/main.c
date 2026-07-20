#include <stdio.h>
#include <stdint.h>
#include "ring_buffer.h"

int main(void)
{
    RingBuffer rb;

    uint8_t data;

    ring_buffer_init(&rb);

    printf("Writing data...\n\n");

    for (uint8_t i = 1; i <= 8; i++)
    {
        if (ring_buffer_write(&rb, i * 10))
        {
            printf("Written : %d\n", i * 10);
        }
        else
        {
            printf("Buffer Full\n");
        }
    }

    printf("\n");

    printf("Reading data...\n\n");

    while (!ring_buffer_is_empty(&rb))
    {
        ring_buffer_read(&rb, &data);

        printf("Read : %d\n", data);
    }

    return 0;
}