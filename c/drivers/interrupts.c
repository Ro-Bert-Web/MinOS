#include "drivers/interrupts.h"
#include "kernel.h"
#include "drivers/mem.h"
#include "drivers/timer.h"

#include "libraries/print.h"
#include "drivers/gpio.h"

void enable_timer_interrupt() {
    write(SYSTEM_TIMER_IRQ_1, ENABLE_IRQS_1);
}

void invalid_interrupt(u32 type, u32 esr, u32 elr) {
    print("Invalid Interrupt ");
    print_num(type);
    print(" ");
    print_num(esr);
    print(" ");
    print_num(elr);
    print_endl();
}

void handle_irq() {
    static char ledOn = 0;

    u32 irq = read(IRQ_PENDING_1);
    switch(irq) {
        case SYSTEM_TIMER_IRQ_1:
            ledOn = !ledOn;
            if (ledOn) {
                gpio_set(21);
            } else {
                gpio_clr(21);
            }

            init_timer(250000);
            write(TIMER_CS_M1, TIMER_CS);
            break;
        default:
            print("Unknown IRQ\n");
            halt();
    }
}
