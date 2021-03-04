#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

extern int64_t addS64(int64_t x, int64_t y);
extern int32_t convertS16toS32(int16_t x);
extern int32_t convertU8toS32(uint8_t x);
extern int16_t greaterS16(int16_t x, int16_t y);
extern uint32_t smallerU32(uint32_t x, uint32_t y);
extern bool isLessThanS8(int8_t x, int8_t y);
extern bool isLessThanU16(uint16_t x, uint16_t y);
extern uint32_t shiftLeftS32(int32_t x, uint8_t p);
extern uint32_t shiftU32(uint32_t x, int8_t p);


void test_addS64()
{
    printf("Testing addS64...");
    int64_t a, b, c;
    a = 3;
    b = 2;
    c = addS64(a,b);
    assert(c == 5);
    printf("done.\n");
}

void test_convertS16toS32()
{
    printf("Testing convertS16toS32...");

    int16_t a = 45;
    int16_t b = -34;
    int16_t c = 3;
    int16_t d = -1;

    int32_t a_new = convertS16toS32(a);
    int32_t b_new = convertS16toS32(b);
    int32_t c_new = convertS16toS32(c);
    int32_t d_new = convertS16toS32(d);

    assert(a == a_new);
    assert(b == b_new);
    assert(c == c_new);
    assert(d == d_new);

    printf("done.\n");
}

void test_convertU8toS32()
{
    printf("Testing convertU8toS32...");

    uint8_t a = 45;
    uint8_t b = 0;
    uint8_t c = 3;

    int32_t a_new = convertU8toS32(a);
    int32_t b_new = convertU8toS32(b);
    int32_t c_new = convertU8toS32(c);

    assert(a == a_new);
    assert(b == b_new);
    assert(c == c_new);

    printf("done.\n");
}

void test_greaterS16()
{
    printf("Testing greaterS16...");

    int16_t a, b, c;
    a = 45;
    b = 32;
    c = greaterS16(a, b);

    int16_t a2, b2, c2;
    a2 = -45;
    b2 = -15;
    c2 = greaterS16(a2, b2);

    assert(c2 == -15);

    printf("done.\n");
}

void test_smallerU32()
{
    printf("Testing smallerU32...");

    uint32_t a, b, c;
    a = 50;
    b = 32;
    c = smallerU32(a, b);

    assert(c == 32);

    printf("done.\n");
}

void test_isLessThanS8()
{
    printf("Testing isLessThanS8...");
    int8_t a, b;
    a = 4;
    b = 5;

    bool c = isLessThanS8(a, b);
    assert(c);

    assert(isLessThanS8(-3, -2));
    assert(!isLessThanS8(-3, -7));
    assert(!isLessThanS8(7, 2));
    assert(!isLessThanS8(4, 4));
    printf("done.\n");
}

void test_isLessThanU16()
{
    printf("Testing isLessThanU16...");
    uint16_t a, b;
    a = 4;
    b = 5;

    bool c = isLessThanU16(a, b);
    assert(c);

    assert(!isLessThanU16(7, 2));
    assert(!isLessThanU16(4, 4));
    printf("done.\n");
}

void test_shiftLeftS32()
{
    printf("Testing shiftLeftS32...");
    int32_t a = 1;
    assert(shiftLeftS32(a, 1) == 2);
    assert(shiftLeftS32(a, 2) == 4);
    assert(shiftLeftS32(a, 3) == 8);
    assert(shiftLeftS32(a, 4) == 16);
    assert(shiftLeftS32(a, 5) == 32);
    assert(shiftLeftS32(a, 15) == 32768);
    printf("done.\n");
}

void test_shiftU32()
{
    printf("Testing shiftU32...");
    // Left shifts, positive p
    uint32_t x = 1;
    assert(shiftU32(x, 1) == 2);
    assert(shiftU32(x, 2) == 4);
    assert(shiftU32(x, 3) == 8);
    assert(shiftU32(x, 4) == 16);
    assert(shiftU32(x, 5) == 32);

    // Right shifts, negative p
    uint32_t y = 256;
    assert(shiftU32(y, 0) == 256);
    uint32_t result = shiftU32(y, -1);
    printf("result: %d\n", result);
    assert(shiftU32(y, -1) == 128);
    assert(shiftU32(y, -2) == 64);
    assert(shiftU32(y, -3) == 32);
    assert(shiftU32(y, -4) == 16);
    assert(shiftU32(y, -5) == 8);
    assert(shiftU32(y, -6) == 4);
    assert(shiftU32(y, -7) == 2);
    assert(shiftU32(y, -8) == 1);
    assert(shiftU32(y, -9) == 0);
    assert(shiftU32(y, -10) == 0);

    printf("done.\n");
}

int main(void)
{
    // test_addS64();
    // test_convertS16toS32();
    // test_convertU8toS32();
    // test_greaterS16();
    // test_smallerU32();
    // test_isLessThanS8();
    // test_isLessThanU16();
    // test_shiftLeftS32();
    test_shiftU32();
    return EXIT_SUCCESS;
}
