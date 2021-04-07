.global isStrEqual
.global strConcatenate
.global sumS32
.global countAboveLimit


.text


@ Question 2a -------------------------------------------
@ bool isStrEqual(const char str1[], const char str2[]);
@ Return 1 or 0 (true or false)
@ R0 = result
@ R1 = str1[0]
@ R2 = str2[0]
@ R3 = index
@ R4 = char1
@ R5 = char2
isStrEqual:
    @ Setup
    PUSH {R4-R5}        @ Push registers
    MOV R2, R0          @ Move str2 into R2
    MOV R3, #0          @ R3 is the str index
    MOV R0, #1          @ Assume they're equal until we get a negative case
isStrEqual_loop:
    LDRSB R4, [R1, R3]      @ Load str1[i] into R4
    LDRSB R5, [R2, R3]      @ load str2[i] into R5

    CMP R4, R5          @ Compare chars

    MOVNE R0, #0        @ If the chars aren't equal, return false
    BNE isStrEqual_end

    @ Once we get here, we know that R4 == R5, we can test either one
    CMP R4, #0          @ If R4 = '\0', end
    BEQ isStrEqual_end

    @ If they're equal, go to the next interation
    ADD R3, R3, #1
    B isStrEqual_loop
isStrEqual_end:
    @ Pop registers
    POP {R4-R5}
    @ End
    BX LR


@ Question 2b -----------------------------------------
@ void strConcatenate(char strTo[], const char strFrom[]);
@ R0 = strTo
@ R1 = strFrom
strConcatenate:
    MOV R4, #0
strConcatenate_len:             @ This gets the length of str1 -> R4
    LDRSB R3, [R0, R4]
    CMP R3, #0
    BEQ strConcatenate_loop1
    ADD R4, R4, #1
    B strConcatenate_len
strConcatenate_loop1:
    LDRB R3, [R0], #1           @ Load char into R3, post increment R0 (str1)
    STRB R3, [R2], #1           @ store char into R2 (str3), port increment R2 (str3)
    SUBS R4, #1
    BNE strConcatenate_loop1

strConcatenate_loop2:
    LDRB R3, [R1], #1           @ Load char into R3, post increment R1 (str2)
    STRB R3, [R2], #1           @ store char into R2 (str3), port increment R2 (str3)
    CMP R3, #0                  @ until we reach the end
    BNE strConcatenate_loop2
    BX LR


@ Question 2c -----------------------------
@ int32_t sumS32(const int32_t x[], uint32_t count);
@ R0 = sum
@ R1 = count
@ R2 = x[0]
@ R3 = Loaded num
sumS32:
    MOV R2, R0              @ Move x[0] into R2
    MOV R0, #0              @ move 0 into R0 (sum)
sumS32_loop:
    LDRSB R3, [R2]          @ load x[i] into R3
    ADD R0, R0, R3          @ add R3 to the sum (R0)
    ADD R2, #4              @ Add 4 to x to increment to the next one
    SUB R1, R1, #1          @ Subtract 1 from the remaining count
    CMP R1, #0              @ check if there's any more
    BNE sumS32_loop         @ if so, loop again
    BX LR                   @ otherwise return





@ Question 2d --------------------------------------
@ uint32_t countAboveLimit(const int32_t x[], int32_t limit, uint32_t count);
@ Returns the number of values in the array containing count entires that are > limit
@ R0 = result
@ R1 = limit
@ R2 = count (array length) * 4
@ R3 = x[0]
@ R4 = loaded x[i] value
@ I am a genius
countAboveLimit:
    PUSH {R4}
    MOV R3, R0                  @ Move x[0] into R3
    MOV R0, #0                  @ Move result into R0
    MOV R2, R2, LSL #2          @ This multiplies R2 by 2^2 (4) so we can use it as an index
countAboveLimit_loop:
    SUB R2, R2, #4              @ Subtract 4 (sizeof(int32_t)) from the index
    LDRSB R4, [R3, R2]          @ Load (right to left) the numbers in x[]
    CMP R4, R1                  @ Compare to the limit
    ADDPL R0, R0, #1            @ If it's above, then add 1 to R0
    CMP R2, #0                  @ Compare the index to 0
    BNE countAboveLimit_loop    @ If there's still more, loop again 
countAboveLimit_end:            @ Otherwise return
    POP {R4}
    BX LR
