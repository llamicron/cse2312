#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

// Question 2a
extern bool isStrEqual(const char str1[], const char str2[]);
void q2a() {
    printf("2a) testing isStrEqual ... \t");

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
    printf("2b) testing strConcatenate ... \t");

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
    printf("2c) testing sumS32 ... \t\t");
    uint32_t length = 5;
    int32_t nums[] = {10, 20, 30, 40, 50};
    int32_t sum = sumS32(nums, length);
    assert(sum == 150);
    printf("passed.\n");
}


int main(void) {
    printf("-- HW3 --\n");
    q2a();
    q2b();
    q2c();
}
