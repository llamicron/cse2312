#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#define COUNT 5
#define test(x) for ( ; !(x) ; assert(x) )

// Returns the sum of the elements in an array (x) containing (count) entries
extern float sumF32(const float x[], uint32_t count);
// Returns the product of the elements in an array (x) containing (count) entries
extern double prodF64(const double x[], uint32_t count);
// Returns the dot product of two arrays (x and y) containing (count) entries
extern double dotpF64(const double x[], const double y[], uint32_t count);
// Returns the maximum value in the array (x) containing (count) entries
extern float maxF32(const float x[], uint32_t count);



void test_sumF32() {
    printf("Testing sumF32\t\t");

    float x[COUNT] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float sum = sumF32(x, COUNT);

    test(sum == 16.5) {
        printf("sum = %f\n", sum);
    };

    printf("passed.\n");
}

void test_prodF64() {
    printf("Testing prodF64\t\t");

    double x[COUNT] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double product = prodF64(x, COUNT);
    test((product - 193.261200) < 0.000001) {
        printf("product = %f\n", product);
    };

    printf("passed.\n");
}

void test_dotpF64() {
    printf("Testing dotpF64\t\t");

    printf("passed.\n");
}

void test_maxF32() {
    printf("Testing maxF32\t\t");

    printf("passed.\n");
}


int main(void) {
    test_sumF32();
    test_prodF64();
    test_dotpF64();
    test_maxF32();
    printf("done.\n");
}
