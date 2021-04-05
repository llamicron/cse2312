#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

extern uint32_t sumU32(const uint32_t x[], uint32_t count);

// C version of the sum function
uint32_t sumU32(const uint32_t x[], uint32_t count)
{
    uint32_t sum = 0;
    while (count > 0)
    {
        // remember that x[] is a pointer to the 0th element
        sum += *(x++);
        count--;
    }
    return sum;
}


#define COUNT 3
int main(void)
{
    uint32_t x[COUNT] = {10, 20, 30};
    uint32_t sum = sumU32(x, COUNT);
    printf("The sum is %d\n", sum);

    return EXIT_SUCCESS;
}
