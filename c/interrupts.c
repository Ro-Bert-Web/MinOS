#include "interrupts.h"
#include "mem.h"
#include "timer.h"
#include "print.h"

void enable_timer_interrupt() {
    write(SYSTEM_TIMER_IRQ_1, ENABLE_IRQS_1);
}


void invalid_interrupt(u64 type, u64 esr, u64 elr) {
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
            init_timer(200000);
            write(TIMER_CS_M1, TIMER_CS);
            print("Timer Interrupt\n");
            break;
        default:
            print("Unknown IRQ\n");
    }
}
