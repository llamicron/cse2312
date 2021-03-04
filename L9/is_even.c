#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

extern bool is_even(uint32_t x);

int main(void)
{
    uint32_t x = 24;
    uint32_t y = 23;

    if (is_even(x))
        printf("%d is even\n", x);
    else
        printf("%d is odd\n", x);

    if (is_even(y))
        printf("%d is even\n", y);
    else
        printf("%d is odd\n", y);
}
