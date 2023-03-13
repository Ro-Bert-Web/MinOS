.section ".text"
.global load_elr_el1
.global load_elr_el2
.global load_elr_el3

load_elr_el1:
    msr elr_el1, x0
    eret
load_elr_el2:
    msr elr_el2, x0
    eret
load_elr_el3:
    msr elr_el3, x0
    eret
