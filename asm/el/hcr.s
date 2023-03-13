.section ".text"
.global set_hcr_el2

set_hcr_el2:
    msr hcr_el2, x0
    ret
