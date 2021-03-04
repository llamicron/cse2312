#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

extern int32_t addS32(int32_t x, int32_t y);
extern uint32_t addU32(uint32_t x, uint32_t y);

int main() {
    int32_t a, b, c;
    a = 100;
    b = -200;
    c = addS32(a, b);
    printf("a + b = %d + %d = %d\n", a, b, c);

    uint32_t d, e, f;
    d = 100;
    e = 200;
    f = addU32(d, e);
    printf("d + e = %d + %d = %d\n", d, e, f);
    
    return EXIT_SUCCESS;
}