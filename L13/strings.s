.global strLength
.global strFind
.global strFindN

.text

@ extern uint32_t strLength(const char str[]);
@ addr of str[0] is in R0, return length in R0
strLength:
    MOV R1, R0 // R1 = &str[0] (address)
    MOV R0, #0 // length, starts at 0

strLength_loop:
    @ Because there's no count this time, we'll stop when
    @ we reach the null character, '\0'.

    @ we use LDRSB to load a char
    LDRSB R2, [R1], #1 @ C-ish: R2 = *(R1++);

    @ now we need to check if it's a null terminator
    CMP R2, #0
    @ if it is a null terminator, then end
    BEQ strLength_end

    @ Otherwise, increment length
    ADD R0, R0, #1

    B strLength_loop
strLength_end:
    BX LR


@ int32_t strFind(const char str[], char c);
@ pointer to first char is in R0
@ char to find is R1
@ return index in R0
strFind:
    @ Move address of first char to R2 so we can use R0
    MOV R2, R0
    MOV R0, #0
strFind_loop:
    @ Load the current character into R3
    LDRSB R3, [R2, R0]
    @ compare character to find to R3
    CMP R1, R3
    @ If they're equal, quit
    BEQ strFind_end
    # If they're not equal, then add 1 to the index
    ADD R0, R0, #1
    @ Compare to 0, null character, end of the string
    CMP R3, #0
    @ If we've reached the end of the string, the character doesn't exist
    @ Move 0-1 into R0 and end
    MOVEQ R0, #-1
    BEQ strFind_end
    # branch back to the loop
    B strFind_loop

strFind_end:
    BX LR

@ Important note: Every function can use R0-3. R4-11 must be preserved between function calls
@ to allow for depth. If you change R4-11, you must restore them before exiting the function.

@                               R0        R1          R2
@ int32_t strFindN(const char str[], char c, uint32_t n);
strFindN:
    @ Before anything, PUSH R4 onto the stack
    @ Now we can write to R4. At the end we'll pop
    PUSH {R4} 
    @ move string into R3
    MOV R3, R0
    @ move 0 into R0, index
    MOV R0, #0
strFindN_loop:
    @ Load char at [start + i] into R4
    LDRSB R4, [R3, R0]
    
    @ First check for the needle
    @ Compare loaded char to the needle
    CMP R4, R1
    @ If it's a match, branch to 
    BEQ strFindN_found

    @ next check for end of string
    CMP R4, #0
    MOVEQ R0, #-1
    BEQ strFindN_end

    @ if it's not a match then increment index and try again
    ADD R0, R0, #1
    B strFindN_loop
strFindN_found:
    @ This means a match was found, might not be the nth though

    @ compare n to 1
    CMP R2, #1
    @ if it's equal, end
    BEQ strFindN_end
    @ otherwise subtract 1 from n and start again
    SUB R2, R2, #1
    ADD R0, R0, #1
    B strFindN_loop
strFindN_end:
    POP {R4}
    BX LR

