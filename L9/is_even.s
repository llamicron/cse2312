.global is_even

.text

is_even:
    // This will bitshift with 1, leaving the result in R0
    // This will leave a 1 in R0 if the number is odd
    AND R0, R0, #1
    // We use this to switch from 0-1 or vice versa
    RSB R0, R0, #1
    // Note: You can also use exclusive or (EOR) to flip the bit
    //      EOR R0, R0, #1
    BX LR
