// April 8, 2021
// Lecture 18
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define COUNT 5

void uint32ToBinaryString(char str[], uint32_t x) {
    uint32_t index;
    uint32_t mask = 0x400000;
    for (index = 0; index < 23; index++) {
        if (x & mask)
            str[index] = '1';
        else
            str[index] = '0';
        mask >>= 1;
    }

    str[23] = '\0';
}

// This will show the S, E, F values of encoded floating point numbers
int main() {
    int i;
    uint32_t value;
    uint32_t s;
    uint32_t e;
    uint32_t f;
    char str[24];

    float x[COUNT] = {0.125, -15.5625, 0.3333333333, 251.2578125, 2048.0000001};

    printf("Float Value\t\t\tHex\t\tS\tE\tF\n");
    for (i = 0; i < COUNT; i++)
    {
        value = *((uint32_t*) &x[i]);
        s = value >> 31;
        e = (value >> 23) & 0xFF;
        f = value & 0x7FFFFF;
        uint32ToBinaryString(str, f);
        printf("%20.10f\t\t0x%08x\t%1d\t%3d\t%s\n", x[i], value, s, e, str);
    }

    return EXIT_SUCCESS;

}

