#include "common.h"

#include "gpio.h"
#include "uart.h"
#include "mem.h"

void print_num(u32 x) {
    u32 byte = 8;
    while (byte != 0) {
        u32 hex = (x >> (4 * (byte - 1))) & 0xf;
        if (hex < 10) {
            uart_putc(hex + '0');
        } else {
            uart_putc(hex - 10 + 'a');
        }
        byte--;
    }
}

void main() {
    uart_init();
    gpio_fsel(21, OUT);

    uart_putstr("Start: ");
    print_num(_start);
    uart_putstr("\nStack: ");
    print_num(stack);
    uart_putstr("\nStackP: ");
    u32 sp = getsp();
    print_num(sp);
    uart_putstr("\n");

    u32 addr = 0;
    u32 special = 0;
    do {
        if (addr & 0x10000) {
            gpio_set(21);
        } else {
            gpio_clr(21);
        }

        if (addr % 0x40 == 0) {
            uart_putstr("\n");
            print_num(addr);
        }

        u32 val = read(addr);
        uart_putstr(" ");
        if (val == 0x55555555) {
            uart_putstr("|      |");
        } else {
            print_num(val);
        }

        addr += 4;
    } while (addr != 0);
    uart_putstr("\n\nMemory Bottom");
}
