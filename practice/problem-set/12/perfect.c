//12) Write a program to check whether the given number is a perfect number or not.
// Example
// 6 =>  3, 2, 1 (proper divisors)
// 1 + 2 + 3 = 6 

#include <stdio.h>
#include <stdlib.h>
int get_proper_divisors(const int value, int *divisors, int *len) {
    if (!divisors || !len) {
        return -1;
    }
    *len = 0;
    for (int i = 1; i < value; i++) {
        if (value % i == 0) {
            divisors[*len] = i;
            (*len)++;
        }
    } 
}

int is_perfect(const int integer) {
    int *divisors = malloc(1024);
    int len = 0;
    
    get_proper_divisors(integer, divisors, &len);
    
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += divisors[i];
    }

    free(divisors);
    return (sum == integer);
}
int main(void) {
    int test_value = 2147483646;
    int *proper_divisors = malloc(1024);
    int len = 0;
    /*
    get_proper_divisors(test_value, proper_divisors, &len);
    
    for (int i = 0; i < len; i++) {
        printf("%d, ", proper_divisors[i]);
    }
    */

    int result = 0;
    for (int i = 0; i < 100; i++) {
        result = is_perfect(i);
        printf("%3d : %d\n", i, result); 
    }



    free(proper_divisors);    
    return 0;
}

