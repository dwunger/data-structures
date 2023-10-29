#include <stdio.h>
#include <stdlib.h>

void swap_d(int ** number1, int ** number2)
{
    if (!number1 || !number2) {
        printf("Received Null pointer");
        return;
    }

    int * temp_ptr = *number1;
    *number1 = *number2;
    *number2 = temp_ptr;
}

int main(void) 
{
    int num1 = 1;
    int num2 = 2;
    
    int *ptr_num1 = &num1;
    int *ptr_num2 = &num2;

    printf("Number 1: %d\nNumber 2: %d\n", *ptr_num1, *ptr_num2);

    swap_d(&ptr_num1, &ptr_num2);

    printf("Number 1: %d\nNumber 2: %d\n", *ptr_num1, *ptr_num2);

    return 0;
}
