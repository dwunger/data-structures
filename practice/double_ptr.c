#include <stdio.h>
#include <stdlib.h>
/*
void swap_arrays(char **str1, char **str2)
{
    if (str1 == NULL || str == NULL) {
        puts("Received invalid pointer");
        return;
    }
    
    char *temp_address = str1;
    str1 = str2;
    str2 = temp_address;  
}
*/
void swap_numbers(int **num1, int **num2)
{
   
    int **num3 = *num1;
    *num1 = *num2;
    *num2 = *num3;
     
}

int main(void) {
    /* 
    char str1[] = "String 1 contents";
    char str2[] = "String 2 contents";
    
    printf("str1: %s\nstr2: %s\n", str1, str2);

    swap_arrays(&str1, &str2);
    
    printf("str1: %s\nstr2: %s\n", str1, str2);
    */

    int number_1 = 1;
    int number_2 = 2;
           
    int *ptr_number_1 = &number_1;
    int *ptr_number_2 = &number_2;
    
    printf("Number 1: %d &%p\nNumber 2: %d &%p\n", 
            number_1, ptr_number_1, number_2, ptr_number_2);
    
    swap_numbers(&ptr_number_1, &ptr_number_2);

    printf("Number 1: %d &%p\nNumber 2: %d &%p\n", 
            number_1, ptr_number_1, number_2, ptr_number_2);

    return 0;
}

