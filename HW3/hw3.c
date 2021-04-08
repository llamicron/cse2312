#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

// Question 2a
extern bool isStrEqual(const char str1[], const char str2[]);
void q2a() {
    printf("2a) testing isStrEqual\t\t\t");

    char str1[] = "something";
    char str2[] = "something";
    char str3[] = "something else";

    assert(isStrEqual(str1, str2));
    assert(!isStrEqual(str1, str3));
    assert(isStrEqual("", ""));
    assert(!isStrEqual("", "    "));
    assert(!isStrEqual("aaa", ""));

    printf("passed.\n");
}

// Question 2b
extern void strConcatenate(char strTo[], const char strFrom[]);
void q2b() {
    // char str1[4] = "abc";
    // char str2[] = "whatever";
    // char* result = strConcatenate(str1, str2);
    // printf("result = %s\n", result);
    printf("2b) testing strConcatenate\t\t");

    char str1[13] = "first ";
    char str2[] = "second";
    char str3[] = "first second";

    strConcatenate(str1, str2);
    // strcmp returns 0 when the strings are equal!!!!! C sucks sometimes.
    assert(strcmp(str1, str3) == 0);

    char str4[5] = "ab";
    char str5[] = "cd";
    char str6[] = "abcd";

    strConcatenate(str4, str5);
    // strcmp returns 0 when the strings are equal!!!!! C sucks sometimes.
    assert(strcmp(str4, str6) == 0);


    printf("passed.\n");
}

// Question 2c
extern int32_t sumS32(const int32_t x[], uint32_t count);
void q2c() {
    printf("2c) testing sumS32\t\t\t");
    uint32_t length = 5;
    int32_t nums[] = {10, 20, 30, 40, 50};
    int32_t sum = sumS32(nums, length);
    assert(sum == 150);
    printf("passed.\n");
}

// Question 2d
extern uint32_t countAboveLimit(const int32_t x[], int32_t limit, uint32_t count);
// Returns the number of values in the array containing count entires that are > limit
void q2d() {
    printf("2d) testing countAboveLimit\t\t");

    int32_t x[] = {10, 15, 20, 25, 30, 60, 5};
    int32_t limit = 17;
    uint32_t count = 7;

    uint32_t result = countAboveLimit(x, limit, count);
    assert(result == 4);

    printf("passed.\n");
}


// Question 2e
extern void leftString(char* strOut, const char* strIn, uint32_t length);
// Extracts [length] chars from strIn (from the left) and puts them in strOut. 
// This function is pretty useless, not sure why we're implementing it.
// Example
//      'abcdef', length 5 -> 'abcde'
//      'abcdef', length 7 -> 'abcdef'
void q2e() {
    printf("2e) testing leftString\t\t\t");

    char* str = "beastly";
    // There needs to be enough space
    char* buffer = malloc(255);

    leftString(buffer, str, 5);
    assert(strcmp(buffer, "beast") == 0);
    leftString(buffer, str, 20);
    assert(strcmp(buffer, str) == 0);

    printf("passed.\n");
}


bool is_sorted(uint32_t x[], uint32_t count) {
    int i;
    for (i = 0; i < count - 1; i++) {
        if (x[i + 1] < x[i]) {
            return false;
        }
    }
    return true;
}


// Question 2g
extern uint32_t sortAscendingInPlace(uint32_t x[], uint32_t count);
void q2g() {
    printf("2g) testing sortAscendingInPlace\t");

    uint32_t sorted[5] = {1, 2, 3, 4, 5};
    uint32_t not_sorted[5] = {5, 4, 3, 2, 1};

    assert(is_sorted(sorted, 5));
    assert(!is_sorted(not_sorted, 5));

    sortAscendingInPlace(not_sorted, 5);
    // int i;
    // printf("arr = [%d", not_sorted[0]);
    // for (i = 1; i < 5; i++)
    //     printf(", %d", not_sorted[i]);
    // printf("]\n");
    assert(is_sorted(not_sorted, 5));

    printf("passed.\n");
}


// Question 2h
extern int16_t decimalStringToInt16(const char * str);
void q2h() {
    printf("2h) testing decimalStringToInt16\t");

    char str1[3] = "37";
    char str2[5] = "4390";
    char str3[5] = "-150";
    char str4[2] = "0";

    assert(decimalStringToInt16(str1) == 37);
    assert(decimalStringToInt16(str2) == 4390);
    assert(decimalStringToInt16(str3) == -150);
    assert(decimalStringToInt16(str4) == 0);

    printf("passed.\n");
}


// Question 2i
extern uint8_t hexStringToUint8(const char * str);
void q2i() {
    printf("2i) testing hexStringToUint8\t\t");

    char hex1[3] = "FF"; // 255
    char hex2[3] = "07"; // 0
    char hex3[3] = "A4"; // 164
    char hex4[3] = "UH"; // bad: 0

    assert(hexStringToUint8(hex1) == 255);
    assert(hexStringToUint8(hex2) == 7);
    assert(hexStringToUint8(hex3) == 164);
    assert(hexStringToUint8(hex4) == 0);
    
    printf("passed.\n");
}



int main(void) {
    printf("-- HW3 --\n");
    q2a();
    q2b();
    q2c();
    q2d();
    q2e();
    // q2f();
    q2g();
    q2h();
    q2i();
}
