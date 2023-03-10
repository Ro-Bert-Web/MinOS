#include "interrupts.h"
#include "mem.h"
#include "timer.h"
#include "uart.h"

void enable_timer_interrupt() {
    write(SYSTEM_TIMER_IRQ_1, ENABLE_IRQS_1);
}


void invalid_interrupt(u64 type, u64 esr, u64 elr) {
    uart_putstr("Invalid Interrupt ");
    uart_putnum(type);
    uart_putc(' ');
    uart_putnum(esr);
    uart_putc(' ');
    uart_putnum(elr);
    uart_putstr("\n");
}

void handle_irq() {
    u32 irq = read(IRQ_PENDING_1);
    switch(irq) {
        case SYSTEM_TIMER_IRQ_1:
            init_timer(200000);
            write(TIMER_CS_M1, TIMER_CS);
            uart_putstr("Timer Interrupt\n");
            break;
        default:
            uart_putstr("Unknown IRQ\n");
    }
}
