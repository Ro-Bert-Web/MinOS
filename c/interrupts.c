#include "interrupts.h"
#include "kernel.h"
#include "procs.h"
#include "mem.h"
#include "timer.h"
#include "utils.h"
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

void handle_irq(ptr stack, u32 esr, u32 elr) {
    stacks[curr_pid] = stack;

    u32 irq = read(IRQ_PENDING_1);
    switch(irq) {
        case SYSTEM_TIMER_IRQ_1:
            init_timer(FRAME_LENGTH);
            write(TIMER_CS_M1, TIMER_CS);
            break;
        default:
            print("Unknown IRQ\n");
            halt();
    }
}
