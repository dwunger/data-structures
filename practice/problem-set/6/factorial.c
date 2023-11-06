// 6) Write a program to calculate the factorial of a given number.
// To improve:
// Supply format specifier to handle int overflow
#include <stdio.h>
int factorial(const int *value);

int main(void)
{
    printf("Enter operand:\n");
    int value = 0;
    scanf("%d", &value);
    int *ptr = &value;
    
    int result = factorial(ptr);
    if (result == -1) {
        return 1;
    }
    
    printf("%d! = %d", value, result);
    
    return 0;

}

int factorial(const int *value)
{
    if (value == NULL || *value < 0) {
        puts("Factorial received uninitialized pointer");
        return -1;
    }
    if (*value == 0) {
        return 1;
    }
    int result = *value;
    
    for (int i = 1; i < *value; i++) {
        result *= i;
    }
    return result;
}
