.global sumU32

.text


@ uint32_t sumU32(const uint32_t x[], uint32_t count)
@ addr of x[0] is in R0
@ count in passed in R1
@ we want to return the sum in R0
sumU32:
    MOV R2, R0 @ R2 = &x[0], R2 has the address of x[0]
    MOV R0, #0 // R0 is the sum, starts at 0

@ Question: how does the program enter here?
@ I think because sumU32 doesn't return, it just continues to the next instruction
sumU32_loop:
    @ first case, is count 0?
    CMP R1, #0
    @ Then we should immediately end
    BEQ sumU32_end

    @ otherwise
    LDR R3, [R2] @ loads x[?] into R3. This will loop with an increment here
    ADD R2, R2, #4 @ move pointer to next array value, increments by sizeof(uint32_t)

    @ Note: the need to load a register then increment like the 2 lines above is very common, so
    @ there's a shorthand:
    @   LDR R3, [R2], #4
    @ This is equivalent to the 2 lines above.
    @ it loads R2's value into R3, then increments R2 by #4 (sizeof(uint32_t))
    @ This is more efficient, not just in terms of LOC.

    ADD R0, R0, R3 @ add value to sum
    SUB R1, R1, #1 @ decremenent count
    B sumU32_loop @ branch back to sumU32_loop

sumU32_end:
    BX LR
