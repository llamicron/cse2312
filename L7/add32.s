.global addS32
.global addU32

.text

// R0 = x, R1 = y, return x+y in R0
addU32:
    ADD R0, R0, R1  // R0 <= R0 + R1
    BX LR           // return to caller

// R0 = x, R1 = y, return x+y in R0
addS32:
    ADD R0, R0, R1  // R0 <= R0 + R1
    BX LR           // return to caller

