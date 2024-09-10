ENTRY(start)
 
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
    bss_start = .;
    .bss : {
        bss = .;
        *(.bss)
    }
    bss_end = .;
    bss_size = bss_end - bss_start;
    end = .;
    stack = 0x40000;
}
