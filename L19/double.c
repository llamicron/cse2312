#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define COUNT 5

void uint52ToBinaryString(char str[], uint64_t x)
{
    uint32_t index;
    uint64_t mask = 0x8000000000000;
    for (index = 0; index < 52; index++)
    {
	if (x & mask)
	    str[index] = '1';
	else
	    str[index] = '0';
	mask >>= 1;
     }
     str[52] = '\0';
}

int main()
{
    int i;
    uint64_t value;
    uint64_t s;
    uint64_t e;
    uint64_t f;
    char str[53];
    double x[COUNT] = {1, -1, 2, -2, -0.640625};
    printf("Float value           Hex                 S  E     F\n");
    for (int i = 0; i < COUNT; i++)
    {
        value = *((uint64_t*)&x[i]);
        s = value >> 63;
        e = (value >> 52) & 0x7FF;
        f = value & 0xFFFFFFFFFFFFF;
        uint52ToBinaryString(str, f);
        printf("%20.10lf  0x%016lx  %1ld  %4ld  %s\n", x[i], value, s, e, str);
    }
    return EXIT_SUCCESS;
}

