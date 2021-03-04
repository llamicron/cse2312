#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


// This will pass x -> R1, R0
//                y -> R3, R2
extern uint64_t addU64(uint64_t x, uint64_t y);

int main()
{
    uint64_t x, y, z;
    x = 3; // 20 billion
    y = 2; // 30 billion
    // This won't fit in a uint64_t
    z = addU64(x, y);
    printf("x = %llu\n", x); // llu -> long long unsigned...
    printf("y = %llu\n", y); // just a format specifier
    printf("z = x + y = %llu\n", z);
    return EXIT_SUCCESS;
}
