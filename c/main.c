#include "gpio.h"

void delay(int d) {
    while (d > 0) {
        d--;
    }
}

void main() {
    gpio_fsel(21, OUT);
    while (1) {
        gpio_set(21);
        delay(1000000);
        gpio_clr(21);
        delay(1000000);
    }
}
