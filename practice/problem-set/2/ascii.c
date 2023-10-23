// 2) Write a program to print all the alphabets and their equivalent 
// ASCII values.

#include <stdio.h>

int main(void) {
    puts("ASCII table:");
    for (int i = 0; i < 256; i++) {
        printf("%d: %c\n", i, i); 
    }
    return 0;
}

