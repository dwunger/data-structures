#include <stdio.h>
#include <math.h>

// Write a program to illustrate bitwise operators.

void binary_print(int integer);

int main() 
{
   int integer = 255;
   binary_print(255);
}


void binary_print(int integer)
{
    
    int index, sum = 0;
    for (int i = 31; i >= 0; i--)
    {
        
        long int power = pow(2, i);
        //printf("power: %ld\nsum: %d\nindex: %d\n", power, sum, i);
        if ((power + sum) <= integer)
        {
            printf("1");
            sum += power;
        }
        else
        {
            printf("0");
        }
        if (i % 8 == 0) printf(" ");
    }
}
