#include <stdio.h>
#include <stdlib.h>

// 1. Using malloc on a 1D Array
// Problem: Create a function that receives an integer n and returns an array of size n where each element is its index squared.

// Example:

// Input: n = 5
// Output: {0, 1, 4, 9, 16}

int* sqrange( int length )
{
    int array[] = malloc((1 + length * sizeof(int)));
    for (int i = 0; (i < (length + 1)); i++)
    {
        array[i] = (i * i);
    }
    return array;
}



int main(void) 
{
    int length = 10;
    int arr_ptr[] = sqrange(length);
    for (int i = 0; i < length; i++)
    {
        printf("%d", array_ptr[i]);
    }
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

