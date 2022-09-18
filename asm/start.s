.section ".text.boot"
.global _start

.equ GPIOBASE, 0x3f200000
.equ GPIOFSEL0, 0x8
.equ GPIOSET0, 0x1c
.equ GPIOCLR0, 0x28

.equ DELAY1, 0x100000
.equ DELAY2, 0x200000
.equ DELAY3, 0x400000
.equ DELAY4, 0x800000

_start:
    ldr sp, =stack
    ldr fp, =stack
    bl ledInit
loop1:
    bl ledOn
    bl hold
    ldr r0, =main
    blx r0
    bl ledOff
    bl hold
    b loop1


ledInit:
    ldr r0, =GPIOBASE
    mov r1, #0x8
    str r1, [r0, #GPIOFSEL0]
    bx lr

ledOn:
    ldr r3, =GPIOBASE
    mov r4, #0x200000
    str r4, [r3, #GPIOSET0]
    bx lr

ledOff:
    ldr r3, =GPIOBASE
    mov r4, #0x200000
    str r4, [r3, #GPIOCLR0]
    bx lr

hold:
    ldr r0, =DELAY2
    and r1, r1, #0
loop2:
    sub r0, r0, #1
    cmp r0, r1
    bne loop2
    bx lr


halt:
    wfe
    b halt

.section ".data"
.balign 4
encodeRet: .word 0x0
blinkRet: .word 0x0

.skip 400
stack:
