.global isPositiveU32
.global isPositiveS32

.text

@ I don't have access to my PI at the moment so this is untested.
@ Pretty sure it's right though.

@ Return true (1) if positive, false (0) otherwise
@ Becuse this accepts an unsigned number, it really just checks if
@ the number is zero or nonzero
isPositiveU32:
    @ This sets the zero flag = 1 if R0 is a 0
    @ if (R0 = 0) set Z = 1
    CMP R0, #0
    @ So now, if Z = 1, the argument R0 is 0
    @ If Z = 0, the number is not 0, therefore positive
    @ becuase it's an unsigned.

    @ This moves a 1 (true) into R0 only if Z clear (Z = 0)
    MOVNE R0, #1
    @ this moves a 0 (false) into R0 only if Z set (Z = 1)
    MOVEQ R0, #0
    BX LR


isPositiveS32:
    CMP R0, #0
    @ Default case is positive (return true)
    MOV R0, #1
    @ Return 0 (false) if the number == 0
    MOVEQ R0, #0
    @ return 0 (false) if MI is set
    MOVMI R0, #0
