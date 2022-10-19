#include "gpio.h"
#include "uart.h"

#include "mem.h"
#include "BCM2837.h"

void main() {
    uart_init();

    gpio_fsel(21, OUT);

    while (1) {
        uart_putstr("\nMinOS>");
        u32 pulled = uart_pullc();

        if (pulled != ~0) {
            gpio_set(21);
            uart_putc((char)pulled);
            uart_putc(' ');
            while (pulled != 0) {
                if (pulled & 0x1) {
                    uart_putc('1');
                } else {
                    uart_putc('0');
                }
                pulled >>= 1;
            }
            uart_putc('|');
        }

        for (u32 i = 0; i < 2000000; i++) {}
        gpio_clr(21);
        for (u32 i = 0; i < 2000000; i++) {}
    }
}
