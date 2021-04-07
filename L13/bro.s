.global uint32ToBinary
.global bro32

.text

@ void uint32ToBinary(char str[], uint32_t x);
@ str[0] = R0, value in R1 
uint32ToBinary:
    @ We'll start with a bitmask
    MOV R2, #0x80000000     @ mask with bit 31 set = 1
utb_loop:
    TST R1, R2              @ see if bit in mask is set in x
    MOVNE R3, #'1'          @ if bit = 1, set R3 = '1'
    MOVEQ R3, #'0'          @ otherwise, R3 = '0'
    STRB R3, [R0], #1       @ store the string byte in R0, post increment by 1
    MOVS R2, R2, LSR #1     @ shift mask to the right by 1
    BNE utb_loop            @ keep looping until mask is 0
    MOV R3, #0              @ set null terminator
    STRB R3, [R0]           @ Store null terminator at end of string
    BX LR                   @ return



@ uint32_t bro32(uint32_t x);
bro32:
    MOV R1, R0              @ R1 = x
    MOV R0, #0              @ R0 = 0
    MOV R2, #0x80000000     @ mask with bit 31 set = 1
    MOV R3, #0x00000001     @ mask with bit 0 set
bro32_loop:
    @ The R2 mask will read bits from left to right. The R3 mask will set from right to left
    @ if bit 31 = 1 from the number, then write bit 0 in the new number
    @ if bit 30 = 1 from the number, then write bit 1 in the new number, etc.
    @   ------------------------------
    @   |   0y00 0000 .... 0000 00y0 |
    @   |    ^                    ^  |
    @   |    R2                  R3  |
    @   ------------------------------
    TST R1, R2              @ is the bit in the R2 mask set?
    ORRNE R0, R0, R3        @ if yes, set bit in R3 mask in R0
    MOVS R2, R2, LSR #1     @ shift R2 mask to the right, update flags
    MOV R3, R3, LSL #1      @ shift R3 mask to the left
    BNE bro32_loop          @ If R2 mask not zero, continue
    BX LR
