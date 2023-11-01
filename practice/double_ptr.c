#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ptr_swap(int ** number1, int ** number2);
void int_swap(int * number1, int * number2);
void str_swap(char *str1, char *str2);
void ref_swap(char **str1, char **str2);
size_t nrst_bin_mult(size_t length);
size_t max_bin_mult(size_t *lengths, size_t array_length);

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
    
    char hello_string[512] = "Hello";
    char adios_string[512] = "Goodbye";
    
    printf("Hello String: %s\nAdios String: %s\n", hello_string, adios_string);
    
    str_swap(hello_string, adios_string);

    printf("Hello String: %s\nAdios String: %s\n", hello_string, adios_string);
    

    char * hello_ptr = hello_string;
    char * adios_ptr = adios_string;

    ref_swap(&hello_ptr, &adios_ptr);

    printf("Hello String: %s\nAdios String: %s\n", hello_ptr, adios_ptr);
    
    size_t length_test[9] = {1,2,3,4,5,6,7,8,9};
    
    size_t capacity = max_bin_mult(length_test, 4);

    printf("Maximum square: %ld\n", capacity);

    return 0;
}
size_t nrst_bin_mult(size_t length)
{
    size_t square = 2;
    while (length > square) {
        square <<= 1;
        printf("===\nSquare: %zu\nLength: %zu\n", square, length);
    }
    return square;
}
size_t max_bin_mult(size_t *lengths, size_t array_length)
{
    if (!lengths) {
        fprintf(stderr, "array not initialized");
        return 0;
    }
    puts("if (lengths[i] > max) max = lengths[i];");
   
    size_t max = lengths[0];
    for (size_t i = 0; i < array_length; i++) {
    
        //printf("if (%10ld > %3ld) %3ld = %10ld; (i = %ld)\n", 
        //       lengths[i], max, max, lengths[i], i); 
       
        if (lengths[i] > max) max = lengths[i];
    }
    
    // f(n) = (n + x)^2, where { first x to satisfy: f(n) > n
    size_t capacity = nrst_bin_mult(max);
    printf("capacity: %ld\n", capacity);
    return capacity;
}

void ref_swap(char **str1, char **str2) 
{
    if (!str1 || !str2 ) {
        fprintf(stderr, "Argument contains uninitialized pointer");
        return;
    }
    
    char *temp_address = *str1;
    *str1 = *str2;
    *str2 = temp_address;
      

}



// Provides no protection against buffer overflow
// Good opportunity to improve with dynamic alloc
void str_swap(char *str1, char *str2) 
{
    if (str1 == NULL || str2 == NULL) {
        fprintf(stderr, "str_swap passed null pointer");
        return;
    }
    char temp_str[512] = "";
    strcpy(temp_str, str1);
    strcpy(str1, str2);
    strcpy(str2, temp_str);
}




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


