#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

// Question 2a
extern bool isStrEqual(const char str1[], const char str2[]);
void q2a() {
    printf("2a) testing isStrEqual\t\t");

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
    printf("2b) testing strConcatenate\t");

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
    printf("2c) testing sumS32\t\t");
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
    printf("2d) testing countAboveLimit\t");

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
    printf("2e) testing leftString\t\t");

    char* str = "beastly";
    // There needs to be enough space
    char* buffer = malloc(255);

    leftString(buffer, str, 5);
    assert(strcmp(buffer, "beast") == 0);
    leftString(buffer, str, 20);
    assert(strcmp(buffer, str) == 0);

    printf("passed.\n");
}


int main(void) {
    printf("-- HW3 --\n");
    q2a();
    q2b();
    q2c();
    q2d();
    q2e();
}
