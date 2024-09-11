#include "drivers/uart.h"
#include "drivers/gpio.h"
#include "drivers/mem.h"

void uart_init() {
    gpio_fsel(14, ALT5);
    gpio_fsel(15, ALT5);

    gpio_enable(14);
    gpio_enable(15);

    write(1, BCM2837_AUX_ENABLES);
    write(0, BCM2837_AUX_MU_CNTL_REG);
    write(0, BCM2837_AUX_MU_IER_REG);
    write(3, BCM2837_AUX_MU_LCR_REG);
    write(0, BCM2837_AUX_MU_MCR_REG);
    write(270, BCM2837_AUX_MU_BAUD_REG);
    write(3, BCM2837_AUX_MU_CNTL_REG);
}


void uart_putstr(char *str) {
    while (*str != '\0') {
        if (*str == '\n')
            uart_putc('\r');
        uart_putc(*str);
        str++;
    }
}



void uart_putc(char c) {
    u32 ready;
    do {
        ready = read(BCM2837_AUX_MU_LSR_REG) & 0x20;
    } while (!ready);

    write((u32)c, BCM2837_AUX_MU_IO_REG);
}

char uart_getc() {
    u32 ready;
    do {
        ready = read(BCM2837_AUX_MU_LSR_REG) & 0x1;
    } while (!ready);

    char c = read(BCM2837_AUX_MU_IO_REG) & 0xff;
    return c;
}


u32 uart_pullc() {
    if (read(BCM2837_AUX_MU_LSR_REG) & 0x1) {
        return read(BCM2837_AUX_MU_IO_REG) & 0xff;
    } else {
        return ~0;
    }
}
