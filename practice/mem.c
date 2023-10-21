#include <stdio.h>
#include <stdlib.h>
#define ERR_OUTOFMEM "Failed to allocate memory"
// 1. Using malloc on a 1D Array
// Problem: Create a function that receives an integer n and returns an array of size n where each element is its index squared.

// Example:

// Input: n = 5
// Output: {0, 1, 4, 9, 16}
// modify the return type of the function `sqrange` by casting a type int*

int* sqrange( int length )
{
    // create a variable named `ptr` to hold the address of the first address in a null initialized (containing all '0's) block of memory
    // int* modifies the name `ptr` to interpret the data as of type `int`
    // when successful malloc returns a void pointer and (int*) modifies the pointer of type `void` (having no type) to be of type `int`
    // malloc is supplied a single argument of the number of bytes to initialize on the heap and pass ownership to the caller
    // length is the number of values in an array and the sizeof operator returns a coefficient yielding the expression equaling the number of bytes needed
    int *ptr = malloc((length * sizeof(int)));
    if (ptr == NULL) {
        puts(ERR_OUTOFMEM);
	return NULL;
    }
    for (int i = 0; i < length; i++)
    {
        ptr[i] = (i * i);
    }
    return ptr;
}



int main(void) 
{
    // create a variable on the stack of name `length` which holds an integer `10`
    int length = 10;
    // declare a pointer with the name `ptr` then initialize using the address returned by a call to the function `sqrange`
    int *ptr = sqrange(length);
    if (ptr == NULL) {
	puts(ERR_OUTOFMEM);
	return 1;
    }

    // loop over a frame on the stack 10 times
    for (int i = 0; i < length; i++)
    {
	
        printf("%d, ", *(ptr + i)); 

    }
    free(ptr);
    return 0;
}


// 2. Creating a Static 2D Array
// Problem: Write a function that creates a static 2D array with n rows and n columns, where each element is initialized to the sum of its row index and column index.

// Example:

// Input: n = 3
// Output:

// Copy code
// { {0, 1, 2}, 
//   {1, 2, 3},
//   {2, 3, 4} 

