.global writeU32
.global readU32

.text


// extern void writeU32(uint32_t* p, uint32_t x);
// pointer is in R0, value is in R1
writeU32:
    STR R1, [R0]
    BX LR

// extern uint32_t readU32(uint32_t* p);
// Pointer is in R0
readU32:
    LDR R0, [R0]
    BX LR
