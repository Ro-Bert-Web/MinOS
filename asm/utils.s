.section ".text"
.global sys_call
.global get_sp
.global get_el
.global delay

sys_call:
    svc #0
    ret

get_sp:
    mov x0, sp
    ret

get_el:
    mrs x0, CurrentEL
    lsr x0, x0, #2
    ret

delay:
    cbz x0, end
    sub x0, x0, #1
    b delay
end:
    ret
