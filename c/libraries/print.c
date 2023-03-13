#include "print.h"
#include "uart.h"

void init_print() {
    uart_init();
}


void print(char *str) {
    uart_putstr(str);
}

void print_endl() {
    uart_putstr("\n");
}


void print_num(u32 val) {
    u32 tens;
    for (tens = 1; val / tens >= 10; tens *= 10) {}

    while (tens) {
        uart_putc((val / tens) + '0');
        val %= tens;
        tens /= 10;
    }
}

void print_hex(u32 val) {
    u32 byte = 8;
    while (byte != 0) {
        u32 hex = (val >> (4 * (byte - 1))) & 0xf;
        if (hex < 10) {
            uart_putc(hex + '0');
        } else {
            uart_putc(hex - 10 + 'a');
        }
        byte--;
    }
}
