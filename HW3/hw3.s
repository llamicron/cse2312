.global isStrEqual
.global strConcatenate


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
@ R2 = temp char
@ R3 = new string
@ No return value
strConcatenate:
    mov  r4, #6
loop1:
    ldrb r3, [r0], #1   @ Copy STRING1 to SRTRING3
    strb r3, [r2], #1
    subs r4, #1
    bne  loop1

    mov  r4, #6
loop2:
    ldrb r3, [r1], #1   @ Copy STRING2 to STRING3
    strb r3, [r2], #1
    subs r4, #1
    bne  loop2

    @ done


