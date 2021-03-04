@ Luke Sweeney
@ UTA ID: 1001764631
@ March 4, 2021
.global addS64
.global convertS16toS32
.global convertU8toS32
.global greaterS16
.global smallerU32
.global isLessThanS8
.global isLessThanU16
.global shiftLeftS32
.global shiftU32

.text

addS64:
    @ Add, with flags
    ADDS R0, R0, R2
    @ Add with carry
    ADC R1, R1, R3
    @ Return
    BX LR

@ Are these correct?
@ C handles the type casting, we just have to return
convertS16toS32:
    BX LR

convertU8toS32:
    BX LR

greaterS16:
    @ If N is set, then R1 is bigger
    @ If Z is set, then they are equal
    CMP R0, R1

    @ These two are redundant, keeping for clarity and sanity
    @ We'll return the first number if they're equal
    MOVEQ R0, R0
    @ If R0 is bigger, keep it
    MOVPL R0, R0

    @ If R1 is bigger (N set)
    MOVMI R0, R1
    BX LR


smallerU32:
    @ Same case as above
    @ if N is set, then R1 is bigger
    @ if Z is set, they are equal
    CMP R0, R1

    MOVEQ R0, R0
    MOVPL R0, R1
    MOVMI R0, R0

    BX LR


isLessThanS8:
    @ Sets Z if they're equal (we return false)
    @ Sets N if R0 < R1 => x < y
    CMP R0, R1
    @ Move false into register 0
    MOV R0, #0
    @ Only return true if R0 < R1
    MOVMI R0, #1
    BX LR


isLessThanU16:
    @ This is pretty much the same as the S8 case above
    @ We can't have negatives here, but it's really the same.

    @ Sets Z if they're equal (we return false)
    @ Sets N if R0 < R1 => x < y
    CMP R0, R1
    MOV R0, #0
    MOVMI R0, #1
    BX LR


shiftLeftS32:
    MOV R0, R0, LSL R1
    BX LR

shiftU32:
    @ Determine if we need to left or right shift
    CMP R1, #0

    @ If p = 0, we can just keep the same number
    @ This move is redundant, but i'll keep it for clarity
    MOVEQ R0, R0

    @ This means p is negative (i think)
    @ Shift right by p
    SUB R2, R1, #0
    MOVMI R0, R0, LSR R2

    @ Otherwise shift left by p
    MOVPL R0, R0, LSL R1

    BX LR
