#include "BCM2837.h"

typedef unsigned int uint;


void write(int value, void *addr) {
    *(uint*)addr = value;
}
int read(void *addr) {
    return *(uint*)addr;
}


void ledInit() {
    write(0x8, (void*)BCM2837_GPFSEL2);
}
void ledOn() {
    write(1 << 21, (void*)BCM2837_GPSET0);
}
void ledOff() {
    write(1 << 21, (void*)BCM2837_GPCLR0);
}


void delay(int d) {
    while (d > 0) {
        d--;
    }
}


void main() {
    ledInit();
    while (1) {
        ledOn();
        delay(1000000);
        ledOff();
        delay(1000000);
    }
}
