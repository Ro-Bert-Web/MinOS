.section ".text.boot"
.global _start
.global getsp
.global stack

_start:
    ldr sp, =stack
    ldr fp, =stack
    ldr r0, =main
    blx r0

getsp:
    mov r0, sp
    bx lr

halt:
    wfe
    b halt

.section ".data"
.balign 4
stack:
.skip 400
