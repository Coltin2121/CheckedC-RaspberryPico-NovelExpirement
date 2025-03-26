@ Required
.thumb_func
.global main
@ Required

main:
    BL	    stdio_init_all  @ Required to start USB communication
    LDR     R2, =addend1
    LDR     R3, =addend2
    LDRB    R4, [R2]
    B       main

data:
    addend1:    .hword  2
    addend2:    .byte   3
    output:     .asciz  "%s\n"