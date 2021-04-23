.global sumF64

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
dotpF64:
    BX LR

@ Returns the maximum value in the array (x) containing (count) entries
@ float maxF32(const float x[], uint32_t count);
maxF32:
    BX LR