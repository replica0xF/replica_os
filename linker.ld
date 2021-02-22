/* where the start program gonna be */
ENTRY (_start)

SECTIONS 
{
    /* asking to be placed in higher half, a/ka 2mib above 8 in physical mem */
    . = 0xffffffff80200000,

    /* we put the stivalehdr in it's own section, then do KEEP() so it doesn't get discarded */
    .stivale2hdr : 
    {
        KEEP(*(.stivale2hdr))
    }

    .text : {
    *(.text*)
    }
    .rodata :
    {
        *(.rodata*)
    }
    .data : {
        *(.data*)
    }

    .bss :
    {
        *(COMMON)
        *(.bss*)
    }
}
