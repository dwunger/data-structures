//15. Write a program to calculate the result of the series accurate up to the 7th digit:
// ```
// x + (x^3)/3! + (x^5)/5! + ...
// ```
// Maybe intended as a McClaurin Expansion for sin(x)?

#include <stdio.h>

int factorial(int argument)
{
    int increment;
    if (argument == 0) {
        return 1;
    } else if (argument < 0 ) {
        increment = -1;
    } else {
        increment = 1;
    }

    int result = 1;

    for (int i = 0; i != argument; i+=increment) {
        result *= i;
    }
    return result;
}

int main(void)
{
    int fact = factorial(4);    
    printf("%d", fact);
    return 0;
}
