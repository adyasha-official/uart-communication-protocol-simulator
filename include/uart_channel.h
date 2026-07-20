#ifndef UART_CHANNEL_H
#define UART_CHANNEL_H

#include <stdbool.h>

#include "uart_frame.h"

bool uart_channel_send(const UART_Frame *frame);

bool uart_channel_receive(UART_Frame *frame);

#endif