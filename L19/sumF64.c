#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

extern double sumF64(const double x[], uint32_t count);

#define COUNT 3
int main(void) {
    double x[COUNT] = {1.1, 2.2, 3.3};
    double sum = sumF64(x, COUNT);
    printf("Sum of elements in x is %lf\n", sum);

    return EXIT_SUCCESS;
}
