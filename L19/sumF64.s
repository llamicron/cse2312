.global sumF64

.text

// double sumF64(const double x[], uint32_t count);
sumF64:
    MOV R2, #0          @ this gets us 32 bits of 0
    VMOV D0, R2, R2     @ This gets us 64 bits of 0
sumF64_loop:
    CMP R1, #0          @ Is the count 0?
    BEQ sumF64_end

    VLDR D1, [R0]       @ read next value in array
    ADD R0, R0, #8      @ Increment by size of double (8 bytes)
    VADD.F64 D0, D0, D1 @ Vector add D1 to D0
    SUB R1, R1, #1      @ Subtract count

    @ D0 could store a double, int64_t or uint64_t, so we add the .F64 or .F32
    @ so it knows what it's operating on

    B sumF64_loop
sumF64_end:
    BX LR
