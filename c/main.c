#include "led.h"

void delay(int d) {
    while (d > 0) {
        d--;
    }
}

void main() {
    initLED();
    while (1) {
        turnLEDOn();
        delay(1000000);
        turnLEDOff();
        delay(1000000);
    }
}
