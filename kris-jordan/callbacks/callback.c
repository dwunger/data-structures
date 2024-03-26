#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_array_i(int * arr, int len);
int square(int n);
int cube(int n);
void applyOperation(int *arr, int size, int (*operation)(int));
void cp_array(int *dest, int size, int *src);

int main(void) 
{
    int array[5] = {1, 2, 3, 4, 5};
    int ref_array[5] = {1, 2, 3, 4, 5};

    // Print initial array
    puts("Base array:");
    print_array_i(array, 5);
    
    // Apply square operation and print
    puts("Squared array:");
    applyOperation(array, 5, square);
    print_array_i(array, 5);
    
    // Reset array
    cp_array(array, 5, ref_array);
    
    // Apply cube operation and print
    puts("Cubed array:");
    applyOperation(array, 5, cube);
    print_array_i(array, 5);
    
    return 0;
}

void applyOperation(int *arr, int size, int (*operation)(int)) {
    for (int i = 0; i < size; i++) {
        arr[i] = operation(arr[i]);
    }
}

void print_array_i(int * arr, int len)
{
    if (len > 512) {
        fprintf(stderr, "print_array_i supports maximum array length of 512");
        exit(1);
    }
    // Buffer size rationale
    // +11 for signed digit
    // +1 for comma
    // +1 for space
    // +12 for formatting print and null terminator
    char buf[512*13 + 12]; 
    buf[0] = '\0'; 
    strcat(buf, "array = { ");
    for (int i = 0; i < len - 1; i++) {
        sprintf(buf + strlen(buf), "%d, ", arr[i]); 
    }
    sprintf(buf + strlen(buf), "%d }\n\n", arr[len - 1]);
    printf("%s", buf);
}

int square(int n) {
    return n * n;
}

int cube(int n) {
    return n * n * n;
}

void cp_array(int *dest, int size, int *src) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }    
}
