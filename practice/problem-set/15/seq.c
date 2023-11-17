//15. Write a program to calculate the result of the series accurate up to the 7th digit:
// ```
// x + (x^3)/3! + (x^5)/5! + ...
// ```
// Maybe intended as a McClaurin Expansion for sin(x)?

#include <stdio.h>

int factorial(int argument)
{
    int delta;
    if (argument == 0) {
        return 1;
    } else if (argument < 0 ) {
        delta = -1;
        argument *= -1;
    } else {
        delta = 1;
    }

    int result = argument;

    for (int i = 1; i < argument; i++) {
        result *= i;
    }

    if (delta == -1) {
        result *= -1;
    }

    return result;
}

int main(void)
{    
    int fact;
    for (int i = -10; i < 11; i++) {
        fact = factorial(i);
        printf("i! = %d\n", fact);
    }
    
    return 0;
}
