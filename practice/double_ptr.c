#include <stdio.h>
#include <stdlib.h>

void ptr_swap(int ** number1, int ** number2)
{
    // swap the pointer address reference
    if (!number1 || !number2) {
        printf("Received Null pointer");
        return;
    }

    int * temp_ptr = *number1;
    *number1 = *number2;
    *number2 = temp_ptr;
}

void int_swap(int * number1, int * number2)
{
    if (!number1 || !number2) {
        fprintf(stderr, "Dereferenced null pointer\n");
    }
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

int main(void) 
{
    puts("======INTEGER======");
    int num1 = 1;
    int num2 = 2;
    
    int *ptr_num1 = &num1;
    int *ptr_num2 = &num2;

    printf("Number 1: %d\nNumber 2: %d\n", *ptr_num1, *ptr_num2);

    ptr_swap(&ptr_num1, &ptr_num2);
    puts("ptr_swap(&ptr_num1, &ptr_num2);");

    printf("Number 1: %d\nNumber 2: %d\n", *ptr_num1, *ptr_num2);
    
    int_swap(&num1, &num2); 
    puts("int_swap(&num1, &num2);");

    printf("Number 1: %d\nNumber 2: %d\n", *ptr_num1, *ptr_num2);
    
    puts("======STRINGS======");

    return 0;
}
