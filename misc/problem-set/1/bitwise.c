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
    for (int i = 31; i >= 0; i--)
    {
        // Shift the integer to the left by i bits and check if the most significant bit is set
        if ((integer & (1 << i)) != 0)
            printf("1");
        else
            printf("0");

        if (i % 8 == 0) printf(" ");
    }
}
