/*

String Allocation

Write a program that reads a string input from the user.
Use malloc to allocate memory for the string.
Print the string and its length.
Free the allocated memory.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 256

int main(void) 
{
    char *input = malloc(MAX_STRING * sizeof(*input));
    
    if (!input) {
        fprintf(stderr, "Failed to allocate memory!");
        return 1;
    }
    
    fgets(input, MAX_STRING * sizeof(*input), stdin);
    int len = strlen(input);
    
    if (len < MAX_STRING) {
        char *temp_ptr = (input + len - 1);
        *temp_ptr = '\0';
    }

    printf("%s\nLength:%d", input, len);
    
    free(input);
    
    return 0;
}
























