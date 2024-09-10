.section ".text.boot"
.global start
.global el1_entry
.global halt

start:
    mrs x0, mpidr_el1
    and x0, x0, #0xff
    cbz x0, launch
    b halt

launch:
    adr x0, stack
    mov sp, x0
    mov fp, x0

    bl setup_cpu
    b halt

el1_entry:
    adr x0, stack
    mov sp, x0
    mov fp, x0

    bl kernel_main
    b halt

halt:
    b halt
