#include "common.h"

#include "el.h"
#include "sys_regs.h"
#include "kernel.h"

#include "print.h"
#include "utils.h"


void setup_cpu() {
    set_sctlr(1, SCTLR_RESERVED);
    set_hcr(2, HCR_RW);
    set_scr(3, SCR_RESERVED | SCR_RW | SCR_NS);
    set_spsr(3, SPSR_MASK_ALL | SPSR_EL1h);
    load_elr(3, (ptr)el1_entry);
}

void kernel_main() {
    init_print();
    print("MinOS\n");
    print("Press ctrl+a,d to exit screen\n");

    print("Exception Level: ");
    u32 x = get_el();
    print_num(x);
    print("\n");

    print("Stack Pointer: ");
    print_hex(get_sp());
    print("\n");
}
