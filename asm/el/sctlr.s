.section ".text"
.global set_sctlr_el1
.global set_sctlr_el2
.global set_sctlr_el3

set_sctlr_el1:
    msr sctlr_el1, x0
    ret
set_sctlr_el2:
    msr sctlr_el2, x0
    ret
set_sctlr_el3:
    msr sctlr_el3, x0
    ret
