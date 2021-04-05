.global strLength

.text

@ extern uint32_t strLength(const char str[]);
@ addr of str[0] is in R0, return length in R0
strLength:
    MOV R1, R0 // R1 = &str[0] (address)
    MOV R0, #0 // length, starts at 0

strLength_loop:
    @ Because there's no count this time, we'll stop when
    @ we reach the null character, '\0'.

    @ we use LDRSB to load a char
    LDRSB R2, [R1], #1 @ C-ish: R2 = *(R1++);

    @ now we need to check if it's a null terminator
    CMP R2, #0
    @ if it is a null terminator, then end
    BEQ strLength_end

    @ Otherwise, increment length
    ADD R0, R0, #1

    B strLength_loop
strLength_end:
    BX LR
