//7) Write a program to calculate sum of squares of cubes of first n natural numbers.

#include <stdio.h>
#define RANGE 3 

void power(int *value, const int exponent);

int main(void)
{
    int base = 0;
    int sum = 0;
    for (int i = 0; i < RANGE; i++) {
        // Power of power rule ((a^m)^n) = (a^(m*n))
        base = i;
        power(&base, 6);
        sum += base;
        printf("(%d^(%d*%d)) + ", i, 2, 3);
    }
    printf("0 = %d\n", sum);
    printf("Sum of squares of cubes in range %d = %d\n", RANGE, sum);

    return 0;
}

void power(int *value, const int exponent)
{
    if (!value) {
        fprintf(stderr, "Received unitialized pointer");
        return; 
    }
    // Cannot handle negative exponentiation if value is of type int
    if (*value < 0)
    {
        fprintf(stderr, "Function call cannot implicitly cast type `int` to `float`");
        return; 
    }
    // Zero exponent rule
    if (exponent == 0) {
        *value = 1;
        return;
    }
    int base_number = *value;
    for (int i = 1; i < exponent; i++) {
        *value *= base_number;
    }
}
