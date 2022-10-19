#include "gpio.h"
#include "mem.h"
#include "BCM2837.h"

ptr get_fselN(u32 n) {
    return BCM2837_GPFSEL0 + n * 4;
}

void gpio_fsel(u32 port, FSEL mode) {
    u32 fsel = port / 10;
    u32 bitOff = (port % 10) * 3;

    ptr addr = get_fselN(fsel);
    u32 value = read(addr);

    value &= ~(7 << bitOff);
    value |= (mode & 7) << bitOff;

    write(value, addr);
}


void gpio_set(u32 port) {
    write(1 << port, BCM2837_GPSET0);
}

void gpio_clr(u32 port) {
    write(1 << port, BCM2837_GPCLR0);
}

void gpio_enable(u32 port) {
    write(0, BCM2837_GPPUD);
    for (u32 i = 0; i < 150; i++) {}
    write(1 << port, BCM2837_GPPUDCLK0);
    for (u32 i = 0; i < 150; i++) {}
    write(0, BCM2837_GPPUD);
    write(0, BCM2837_GPPUDCLK0);
}
