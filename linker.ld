ENTRY(_start)
 
SECTIONS {
    .text : {
        KEEP(*(.text.boot))
        *(.text)
    }
    .rodata : {
        *(.rodata)
    }
    .data : {
        *(.data)
    }
    . = ALIGN(0x8);
    __bss_start = .;
    .bss : {
        bss = .;
        *(.bss)
    }
    __bss_end = .;
    __bss_size = __bss_end - __bss_start;
    __end = .;
}
