#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

extern void writeU32(uint32_t* p, uint32_t x);
extern uint32_t readU32(uint32_t* p);

int main(void) {
    uint32_t a;
    printf("&a = %p\n", &a);
    writeU32(&a, 0x12345678);
    printf("a = 0x%08x\n", readU32(&a));
    return EXIT_SUCCESS;
}