#include "common.h"
#include "utils.h"
#include "uart.h"
#include "gpio.h"
#include "el.h"
#include "kernel.h"
#include "sys_regs.h"

#include "el_priv.h"

void main() {
    uart_init();

    uart_putstr("Hello House.\n");
    u32 el = get_el();
    uart_putnum(el);
    uart_putstr("\n");
}

void kernel_main() {
    /*uart_init();

    uart_putstr("Hello World.\n");
    u32 el = get_el();
    uart_putnum(el);
    uart_putstr("\n");

    set_sctlr(1, SCTLR_RESERVED);
    set_hcr(2, HCR_RW);
    set_scr(3, SCR_RESERVED | SCR_RW | SCR_NS);
    set_spsr(3, SPSR_MASK_ALL | SPSR_EL1h);
    load_elr(3, (ptr)el1_entry);*/

    set_sctlr_el1(SCTLR_RESERVED);
    set_hcr_el2(HCR_RW);
    set_scr_el3(SCR_RESERVED | SCR_RW | SCR_NS);
    set_spsr_el3(SPSR_MASK_ALL | SPSR_EL1h);
    load_elr_el3((ptr)el1_entry);
}
