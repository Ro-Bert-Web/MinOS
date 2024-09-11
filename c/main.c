#include "kernel.h"
#include "drivers/el.h"
#include "drivers/interrupts.h"
#include "drivers/timer.h"

#include "drivers/gpio.h"
#include "libraries/print.h"
#include "utils.h"


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
    print("MinOS\n");
    print("Press ctrl+a,d to exit screen\n");

    print("Exception Level: ");
    u32 x = get_el();
    print_num(x);
    print("\n");

    delay(10000000);

    print("Stack Pointer: ");
    print_hex(get_sp());
    print("\n");

    vtable_init();
    init_timer(100);
    enable_timer_interrupt();
    //enable_irq(); // enabling this breaks the code

    while (1) {
        gpio_set(21);
        delay(10000000);
        gpio_clr(21);
        delay(10000000);
    }
}
