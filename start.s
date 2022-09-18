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
    bl ledInit

loop:
    sub r0, sp, r15
    ldr r0, =#0x12
    bl ledEncode

    ldr r0, =0x1000000
hold:
    sub r0, r0, #1
    cmp r0, #0
    bne hold
    b loop


ledInit:
    ldr r0, =GPIOBASE
    mov r1, #0x8
    str r1, [r0, #GPIOFSEL0]
    bx lr


ledEncode:
    ldr r1, =encodeRet
    str lr, [r1]

encodeLoop:
    cmp r0, #0
    beq encodeEnd

    and r1, r0, #0x1
    cmp r1, #0x1
    bne short
    ldr r1, =DELAY1
    ldr r2, =DELAY3
    bl ledBlink
short:
    ldr r1, =DELAY1
    ldr r1, =DELAY4
    bl ledBlink

    lsr r0, r0, #1
    b encodeLoop

encodeEnd:
    ldr r1, =encodeRet
    ldr lr, [r1]
    bx lr


ledBlink:
    ldr r3, =blinkRet
    str lr, [r3]

    bl ledOn
    blinkLoop1:
        sub r1, r1, #1
        cmp r1, #0
        bgt blinkLoop1
    bl ledOff
    blinkLoop2:
        sub r2, r2, #1
        cmp r2, #0
        bgt blinkLoop2

    ldr r3, =blinkRet
    ldr lr, [r3]
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


halt:
    wfe
    b halt

.section ".data"
encodeRet: .word 0x0
blinkRet: .word 0x0
