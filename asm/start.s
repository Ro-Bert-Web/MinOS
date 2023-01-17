.section ".text.boot"
.global _start
.global el1_entry

_start:
    mrs x0, mpidr_el1
    and x0, x0, #0xff
    cbz x0, launch
    b halt

launch:
    ldr x0, =4096
    mov sp, x0
    mov fp, x0

    bl kernel_main
    b halt

el1_entry:
    ldr x0, =4096
    mov sp, x0
    mov fp, x0

    bl main
    b halt

halt:
    wfe
    b halt
