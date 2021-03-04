.global addU64

.text

// uint64_t addU64(uint64_t x, uint64_t y);
// x in R1:R0 (bits 63-32 are in R1, bits 31-0 are in R0)
// Same case for y, in R3, R2
// Results are returned in R1:R0, just how x is passed in.
addU64:
    ADDS R0, R0, R2      // Add with flags
    ADC R1, R1, R3       // Adds with carry
    BX LR
