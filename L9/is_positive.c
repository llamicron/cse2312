#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

extern bool isPositiveU32(uint32_t x);
// extern bool isPositiveS32(int32_t x);

void checkU32(int x)
{
    if (isPositiveU32(x))
        printf("%d is positive\n", x);
    else
        printf("%d is not positive\n", x);
}

// void checkS32(int x)
// {
//     if (isPositiveS32(x))
//         printf("%d is positive\n", x);
//     else
//         printf("%d is not positive\n", x);
// }


int main()
{
    uint32_t x = 8;
    checkU32(x);

    uint32_t y = 0;
    checkU32(y);


    // int32_t x = 8;
    // checkS32(x);

    // int32_t x = -4;
    // checkS32(x);



}
