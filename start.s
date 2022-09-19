.section ".text.boot"
.global _start

_start:
    ldr sp, =stack
    ldr fp, =stack
    ldr r0, =main
    blx r0

halt:
    wfe
    b halt

.section ".data"
.balign 4
.skip 400
stack:
