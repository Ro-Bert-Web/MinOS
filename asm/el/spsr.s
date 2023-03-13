.section ".text"
.global set_spsr_el1
.global set_spsr_el2
.global set_spsr_el3

set_spsr_el1:
    msr spsr_el1, x0
    ret
set_spsr_el2:
    msr spsr_el2, x0
    ret
set_spsr_el3:
    msr spsr_el3, x0
    ret
