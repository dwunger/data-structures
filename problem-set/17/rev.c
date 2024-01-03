//17. Write a program to print the elements of an array in reverse order.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int write_array(int *array, int len);
int reverse(int *array);

int main(void) {
    
    int array[] = {1,2,3,4,5};
    int len = sizeof(array)/sizeof(array[0]);

    write_array(array, len);


    return 0;
}


int write_array(int *array, int len){
    char string[len * 12];
    string[0] = '\0';
    char temp[12];
    temp[0] = '\0';

    for (int i = 0; i < len; i++) {    
        sprintf(temp, "%d, ", array[i]);
        strcat(string, temp);

    }
    printf(string);

    return 0;
}


