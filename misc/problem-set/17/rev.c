//17. Write a program to print the elements of an array in reverse order.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int write_array(int *array, int len);
int reverse(int *array, size_t len);

int main(void) {
    
    int array[] = {1,2,3,4,5};
    int len = sizeof(array)/sizeof(array[0]);
    puts("Array:");
    write_array(array, len);

    reverse(array, len);
    
    puts("Reversed:");
    write_array(array, len);
    
    return 0;
}


int write_array(int *array, int len){

    char string[len * 12];
    char temp[12];
    
    string[0] = '\0';
    temp[0] = '\0';
    
    for (int i = 0; i < len - 1; i++) {    
        sprintf(temp, "%d, ", array[i]);
        strcat(string, temp);
    }
    
    sprintf(temp, "%d\n", array[len - 1]);
    strcat(string, temp);   

    printf(string);

    return 0;
}

int reverse(int *array, size_t len) {
    
    if (!array) {
        fprintf(stderr, "array points to null");
        return 0;
    }

    if (len == 0) {
        return 1;
    }

    int temp[len];

    for (int i = 0; i < len; i++) {
        temp[len - i - 1] = array[i];

    }


    for (int i = 0; i < len; i++) {
        array[i] = temp[i];

    }

   return 1;
}
