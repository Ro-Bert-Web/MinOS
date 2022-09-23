#include "led.h"
#include "mem.h"
#include "BCM2837.h"
#include "gpio.h"

void initLED() {
    gpio_fsel(21, OUT);
    //write(0x8, BCM2837_GPFSEL2);
}
void turnLEDOn() {
    gpio_set(21);
    //write(1 << 21, BCM2837_GPSET0);
}
void turnLEDOff() {
    gpio_clr(21);
    //write(1 << 21, BCM2837_GPCLR0);
}
