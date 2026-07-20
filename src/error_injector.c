#include "error_injector.h"

static bool injector_enabled = false;

void error_injector_enable(bool enable)
{
    injector_enabled = enable;
}

bool error_injector_is_enabled(void)
{
    return injector_enabled;
}

void error_inject_frame(UART_Frame *frame)
{
    if (!injector_enabled)
    {
        return;
    }

    /* Flip bit 0 of the data byte */
    frame->data ^= (1 << 0);
}