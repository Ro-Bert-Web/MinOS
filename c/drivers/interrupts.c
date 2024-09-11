#include "drivers/interrupts.h"
#include "kernel.h"
#include "drivers/mem.h"
#include "drivers/timer.h"

#include "libraries/print.h"

void save_stack(ptr stack) {
}

ptr restore_stack() {
    return 0;
}

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
    u32 irq = read(IRQ_PENDING_1);
    switch(irq) {
        case SYSTEM_TIMER_IRQ_1:
            print("Timer");
            //init_timer(100);
            //write(TIMER_CS_M1, TIMER_CS);
            break;
        default:
            print("Unknown IRQ\n");
            halt();
    }
}
