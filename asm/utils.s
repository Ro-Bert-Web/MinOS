.section ".text"
.global get_el
.global delay

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
