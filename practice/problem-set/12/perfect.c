//12) Write a program to check whether the given number is a perfect number or not.
// Example
// 6 =>  3, 2, 1 (proper divisors)
// 1 + 2 + 3 = 6 

#include <stdio.h>

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
int main(void) {
    int test_value = 6;
    int proper_divisors[256];
    int len = 0;

    get_proper_divisors(test_value, proper_divisors, &len);
    
    for (int i = 0; i < len; i++) {
        printf("%d, ", proper_divisors[i]);
    }

    return 0;
}

