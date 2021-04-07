#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// why is this called bro??


// Fills a string with the binary representation of a uint32_t
extern void uint32ToBinary(char str[], uint32_t x);

// I think this reverses all the bits in the number
extern uint32_t bro32(uint32_t x);

int main(void) {
    uint32_t a, b, c;
    char str[33]; // 32 bytes + null
    a = 0x12345678;
    uint32ToBinary(str, a);
    printf("a = 0x%08x = %s (base 2)\n", a, str);

    
    b = bro32(a);
    uint32ToBinary(str, b);
    printf("b = 0x%08x = %s (base 2)\n", b, str);


    return EXIT_SUCCESS;
}