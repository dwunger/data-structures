// 2) Write a program to print all the alphabets and their equivalent 
// ASCII values.

#include <stdio.h>

int main(void) {
    puts("ASCII table:");
    for (int i = 65; i <= 122; i++) {
        if ((i <= 90) || (i >= 97)) {
            printf("%c: %d\n", i, i);
        }
    }
    //printf("a: %d, A: %d, z: %d, Z: %d\n", 'a', 'A', 'z', 'Z');

    return 0;
}

