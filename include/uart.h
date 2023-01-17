#pragma once

#include "common.h"

void uart_init();

void uart_putstr(char *str);
void uart_putnum(u32 x);

void uart_putc(char c);
char uart_getc();

u32 uart_pullc();
