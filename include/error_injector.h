#ifndef ERROR_INJECTOR_H
#define ERROR_INJECTOR_H

#include <stdbool.h>

#include "uart_frame.h"

void error_injector_enable(bool enable);

bool error_injector_is_enabled(void);

void error_inject_frame(UART_Frame *frame);

#endif