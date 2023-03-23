#include "common.h"

#include "el.h"
#include "sys_regs.h"
#include "kernel.h"
#include "timer.h"
#include "interrupts.h"

#include "procs.h"
#include "print.h"
#include "time.h"


extern void line_main();
extern void square_main();
extern void fib_main();
extern void fact_main();

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
    init_timer(FRAME_LENGTH);
    enable_timer_interrupt();
    enable_irq();

    init_procs();

    while (fork() != 0);

    switch (curr_pid) {
        case 0:
            exec((ptr)line_main);
        case 1:
            sleep(10);
            exec((ptr)square_main);
        case 2:
            sleep(20);
            exec((ptr)fib_main);
        case 3:
            sleep(30);
            exec((ptr)fact_main);
    }
    exit_proc();
}
