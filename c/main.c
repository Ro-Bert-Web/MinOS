#include "common.h"
#include "utils.h"
#include "gpio.h"
#include "uart.h"
#include "mem.h"
#include "el.h"
#include "kernel.h"
#include "sys_regs.h"

void kernel_main() {
/*    uart_init();

    uart_putstr("Hello World.\n");
    u32 el = get_el();
    uart_putnum(el);

    delay(1000);*/

    set_sctlr(1, SCTLR_RESERVED);
    set_hcr(2, HCR_RW);
    set_scr(3, SCR_RESERVED | SCR_RW | SCR_NS);
    set_spsr(3, SPSR_MASK_ALL | SPSR_EL1h);
    load_elr(3, (ptr)el1_entry);
}

void main() {
    uart_init();

    uart_putstr("Hello World.\n");
    u32 el = get_el();
    uart_putnum(el);
}
