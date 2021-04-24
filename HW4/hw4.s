@ Luke Sweeney
@ 1001764631
@ April 23, 2021
@ CSE 2312 - Losh
@ Homework 4
.global sumF32
.global prodF64
.global dotpF64
.global maxF32

.text


@ Returns the sum of the elements in an array (x) containing (count) entries
@ float sumF32(const float x[], uint32_t count);
@ x[0] -> R0
@ count -> R1
@ Return in S0
sumF32:
    MOV R2, #0
    VMOV S0, R2             @ Move sum = 0 into S0
sumF32_loop:
    CMP R1, #0              @ Compare count with 0
    BEQ sumF32_end          @ If it's 0, then quit

    VLDR S1, [R0]           @ Load float from x[i] into S1

    VADD.F32 S0, S0, S1     @ Add S1 to sum S0
    ADD R0, R0, #4          @ Increment R0
    SUB R1, R1, #1          @ Decrement count

    B sumF32_loop           @ Repeat
sumF32_end:
    BX LR




@ Returns the product of the elements in an array (x) containing (count) entries
@ double prodF64(const double x[], uint32_t count);
prodF64:
    CMP R1, #0
    BEQ prodF64_end     @ If there aren't any values, end

    VLDR D0, [R0]       @ otherwise, load the first value so we're not multiplying by 0
    SUB R1, R1, #1      @ Decrement count
    ADD R0, R0, #8      @ Increment index
prodF64_loop:
    CMP R1, #0          @ Is the count 0?
    BEQ prodF64_end     @ If so then end

    VLDR D1, [R0]       @ read next value in array
    ADD R0, R0, #8      @ Increment by size of double (8 bytes)
    VMUL.F64 D0, D0, D1 @ Vector add D1 to D0
    SUB R1, R1, #1      @ Subtract count

    B prodF64_loop
prodF64_end:
    BX LR

@ Returns the dot product of two arrays (x and y) containing (count) entries
@ double dotpF64(const double x[], const double y[], uint32_t count);
@ D0 = return value
@ D1 = x[i]
@ D2 = y[i]
@ R0 = x[0]
@ R1 = y[0]
@ R2 = count
dotpF64:
    MOV R3, #0              @ Load a 0
    VMOV D0, R3, R3         @ Store a 0 into D0
dotpF64_loop:
    CMP R2, #0              @ Compare count to 0
    BEQ dotpF64_end         @ If it's 0, we're done

    VLDR D1, [R0]           @ Load x[i] into D1
    VLDR D2, [R1]           @ Load y[i] into D2

    VMUL.F64 D1, D1, D2     @ Multiply both and store in D1
    VADD.F64 D0, D0, D1     @ Add D1 to D0

    ADD R0, R0, #8          @ Increment both
    ADD R1, R1, #8

    SUB R2, R2, #1          @ Decrement count

    B dotpF64_loop          @ Loop again
dotpF64_end:
    BX LR

@ Returns the maximum value in the array (x) containing (count) entries
@ float maxF32(const float x[], uint32_t count);
@ R0 = x[0]
@ R1 = count
@ S0 = max
@ S1 = current
maxF32:
    CMP R1, #0              @ If the count is 0, quit
    BEQ maxF32_end
    VLDR S0, [R0]           @ Load x[0] in S0
maxF32_loop:
    CMP R1, #0              @ If the count is 0, quit
    BEQ maxF32_end

    VLDR S1, [R0]           @ Load x[i] in S1
    VCMP.F32 S0, S1         @ Compare S0 - S1
    VMRS APSR_nzcv, FPSCR   @ I have no idea why this is necessary but it is
    VMOVMI S0, S1           @ If S0 is smaller, move S1 into S0

    SUB R1, R1, #1          @ Decrement count
    ADD R0, R0, #4          @ Increment R0

    B maxF32_loop
maxF32_end:
    BX LR
