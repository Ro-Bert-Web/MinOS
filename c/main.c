#include "kernel.h"
#include "drivers/el.h"
#include "drivers/interrupts.h"
#include "drivers/timer.h"

#include "drivers/gpio.h"
#include "libraries/print.h"
#include "utils.h"
#include "libraries/time.h"

void setup_cpu() {
    set_sctlr(1, SCTLR_RESERVED);
    set_hcr(2, HCR_RW);
    set_scr(3, SCR_RESERVED | SCR_RW | SCR_NS);
    set_spsr(3, SPSR_MASK_ALL | SPSR_EL1h);
    load_elr(3, (ptr)el1_entry);
}

void kernel_main() {
    gpio_fsel(21, OUT);
    init_print();

    vtable_init();
    enable_irq();
    init_timer(250000);
    enable_timer_interrupt();

    print("MinOS\n");
    print("Press ctrl+a,d to exit screen\n");

    int i = 1;
    int j = 1;
    while (1) {
        int k = i + j;
        i = j;
        j = k;
        print_num(i);
        print_endl();
        sleep(1000);
    }
}
