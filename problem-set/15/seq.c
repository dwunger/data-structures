//15. Write a program to calculate the result of the series accurate up to the 7th digit:
// ```
// x + (x^3)/3! + (x^5)/5! + ...
// ```
// Maybe intended as a McClaurin Expansion for sin(x)?

#include <stdio.h>
#include <math.h>

long long factorial(long long argument)
{
    long long delta;
    if (argument == 0) {
        return 1;
    } else if (argument < 0 ) {
        delta = -1;
        argument *= -1;
    } else {
        delta = 1;
    }

    long long result = argument;

    for (long long i = 1; i < argument; i++) {
        result *= i;
    }

    if (delta == -1) {
        result *= -1;
    }

    return result;
}
void expand_series(double angle, int sigfigs)
{
    angle = angle * (M_PI / 180.0);

    double power = 0; int fact = 0; double y = 0;
    // y = x + (x^3)/3! + (x^5)/5! + ...
    int par = 0;
    for (int x = 1; x < sigfigs; x+=2) {
        power = pow(angle, x);
        fact = factorial(x);
        
        if (par) {
            y += power/(double)fact;
        } else {
            y -= power/(double)fact;
        }

        par = ~par;
        }
    printf("Series: %g\n", (double)y);

}

int main(void)
{    
    long long fact;
    for (int i = 19; i < 20; i++) {
        fact = factorial(i);
        printf("%d! = %lld\n", i, fact);
    }
    printf("sizeof(long long): %d\nsizeof(int): %d\n", sizeof(long long), sizeof(int));    
    
    expand_series(90,15);
    return 0;
}
