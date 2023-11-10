//11) Write a program to check whether the given number is an Amstrong number or not.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_armstrong(int number);


int main(void) 
{
    // Created temp indices to avoid making an append function or linked list
    int armstrongs[1000];
    int a_idx = 0;

    int non_armstrongs[1000];
    int n_idx = 0;

    int result = 0;
    int number = 371;
    for (int i = 0; i < 1000; i++) {
        result = is_armstrong(i);
        if (result) {
            armstrongs[a_idx] = i;
            a_idx++;
        } else {
            non_armstrongs[n_idx] = i;
            n_idx++;
        }

        //printf("%d : %d\n", i, result);
    }
    printf("Non-Armstrongs\n");
    int last = -1;
    printf("%d ", non_armstrongs[0]);
    for (int i = 1; i < 1000; i++) {
        last = non_armstrongs[i - 1];
        if (last + 1 != non_armstrongs[i]) {
            printf("- %d, ", non_armstrongs[i]);
        } else {
            //printf("", non_armstrongs[i]);
            continue; 
        }
    }


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

