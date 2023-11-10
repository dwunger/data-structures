//11) Write a program to check whether the given number is an Amstrong number or not.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_armstrong(int number);


int main(void) 
{
    int result = 0;
    int number = 371;
    result = is_armstrong(number);
    printf("%d", result);
    
    return 0;
}


int is_armstrong(int number)
{
    char buffer[11];
    int base = 10;
    itoa(number, buffer, base);
    
    int len = strlen(buffer);
    int digit;
    int sum = 0;
    int power = 0;
    for (int i = 0; i < len; i++) {
        digit = (int)buffer[i] - 0x30; // 0x30 -> 48
        power = pow(digit, len);
        sum += power;
    }
    return (sum == number);

}

