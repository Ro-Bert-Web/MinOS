#include "led.h"
#include "memory.h"
#include "BCM2837.h"

void initLED() {
    write(0x8, (void*)BCM2837_GPFSEL2);
}
void turnLEDOn() {
    write(1 << 21, (void*)BCM2837_GPSET0);
}
void turnLEDOff() {
    write(1 << 21, (void*)BCM2837_GPCLR0);
}
