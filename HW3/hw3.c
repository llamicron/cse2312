#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

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




int main(void) {
    printf("-- HW3 --\n");
    q2a();
}