#include "common.h"

#include "el.h"
#include "sys_regs.h"
#include "kernel.h"
#include "timer.h"
#include "interrupts.h"

#include "procs.h"
#include "print.h"


extern int fib_main();

void setup_cpu() {
    set_sctlr(1, SCTLR_RESERVED);
    set_hcr(2, HCR_RW);
    set_scr(3, SCR_RESERVED | SCR_RW | SCR_NS);
    set_spsr(3, SPSR_MASK_ALL | SPSR_EL1h);
    load_elr(3, (ptr)el1_entry);
}

void main() {
    init_print();
    print("MinOS\n");

    vtable_init();
    init_timer(200000);
    enable_timer_interrupt();
    enable_irq();

    init_procs();
    exec((ptr)fib_main);

    while (1) {}
}
