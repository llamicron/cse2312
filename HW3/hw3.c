#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

// Question 2a
extern bool isStrEqual(const char str1[], const char str2[]);
int q2a() {
    printf("2a) testing isStrEqual ... ");

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
extern char* strConcatenate(char strTo[], const char strFrom[]);
int q2b() {
    // char str1[4] = "abc";
    // char str2[] = "whatever";
    // char* result = strConcatenate(str1, str2);
    // printf("result = %s\n", result);
    printf("2b) testing strConcatenate ... ");

    char str1[13] = "first ";
    char str2[] = "second";
    char str3[] = "first second";

    strConcatenate(str1, str2);
    printf("str1 = %s\n", str1);
    assert(strcmp(str1, str3));

    printf("passed.\n");
}




int main(void) {
    printf("-- HW3 --\n");
    q2a();
    q2b();
}