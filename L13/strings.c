#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Returns position of first isntance of character in string
// or -1 if not found
extern int32_t strFind(const char str[], char c);

extern uint32_t strLength(const char str[]);

// Returns position of nth instance of character in string or -1
extern int32_t strFindN(const char str[], char c, uint32_t n);

int main(void) {
    char str[] = "Hello world";
    uint32_t length = strLength(str);
    char match = 'o';
    uint32_t n = 2;

    int result;

    printf("str = %s\n", str);
    printf("len = %d\n", length);
    printf("n   = %d\n", n);

    result = strFind(str, match);
    if (result != -1) {
        printf("strFind(\"%s\", \'%c\') = %d\n", str, match, result);
    }
    else {
        printf("Char %c not found in str %s\n", match, str);
    }

    result = strFindN(str, match, n);
    if (result != -1) {
        printf("strFindN(\"%s\", \'%c\', %d) = %d\n", str, match, n, result);
    }
    else {
        printf("Char %c not found in str %s\n", match, str);
    }

}
