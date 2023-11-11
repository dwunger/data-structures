//11) Write a program to check whether the given number is an Amstrong number or not
//
// 371 => 3^3 + 7^3 + 1^3 = 371
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_armstrong(int number);

void print_hyphenated_ranges(int arr[], int len) {
    // start/end of current range
    int start = arr[0]; 
    int end; 

    for (int i = 1; i < len; i++) {
        if (arr[i] == arr[i - 1] + 1) {
            end = arr[i];
        } else {
            if (start == arr[i - 1]) {
                printf("%d, ", start);
            } else {
                printf("%d-%d, ", start, arr[i - 1]);
            }
            start = arr[i];
        }
    }

    if (start == arr[len - 1]) {
        printf("%d\n", start);
    } else {
        printf("%d-%d\n", start, arr[len - 1]);
    }
}

int main(void) 
{
    // Created temp indices to avoid making an append function or linked list
    int armstrongs[1000];
    int a_idx = 0;
    int armstrongs_len = 0;

    int non_armstrongs[1000] = {0};
    int n_idx = 0;
    int non_armstrongs_len = 0;

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

        printf("%d : %d\n", i, result);
    }

    armstrongs_len = a_idx;
    non_armstrongs_len = n_idx;

    printf("Non-Armstrongs\n");
    print_hyphenated_ranges(non_armstrongs, non_armstrongs_len);    
    printf("Armstrongs\n");
    print_hyphenated_ranges(armstrongs, armstrongs_len);

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

