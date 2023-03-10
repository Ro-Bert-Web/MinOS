#include "common.h"

#include "utils.h"

#include "gpio.h"
#include "uart.h"

#include "el.h"
#include "sys_regs.h"
#include "kernel.h"

#include "timer.h"
#include "interrupts.h"


void setup_cpu() {
    set_sctlr(1, SCTLR_RESERVED);
    set_hcr(2, HCR_RW);
    set_scr(3, SCR_RESERVED | SCR_RW | SCR_NS);
    set_spsr(3, SPSR_MASK_ALL | SPSR_EL1h);
    load_elr(3, (ptr)el1_entry);
}

void main() {
    uart_init();
    uart_putstr("MinOS\n");
    u32 el = get_el();
    uart_putnum(el);
    uart_putstr("\n");

    vtable_init();
    init_timer(200000);
    enable_timer_interrupt();
    enable_irq();

    while (1) {
        uart_putstr("line\n");
        delay(300000);
    }
}
