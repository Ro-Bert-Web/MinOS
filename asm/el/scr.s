.section ".text"
.global set_scr_el3

set_scr_el3:
    msr scr_el3, x0
    ret

