//8) Write a program to reverse the given number.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reverse decimal integer value
void rdint(int *decimal)
{
    if (!decimal) {
        fprintf(stderr, "Received unitialized pointer");
    }

    char buffer[11];
    int base = 10;
    
    itoa(*decimal, buffer, base); 
    //puts("===ORIGINAL==="); 
    //printf("%s\n", buffer);
    
    strrev(buffer);
    
    //puts("===REVERSE==="); 
    //printf("%s\n", buffer);
    
    *decimal = atoi(buffer);
} 

int main(void)
{ 
    int number;
    for (int i = 0; i < 256; i++)
    {    
        number = i;
        
        puts("===ORIGINAL==="); 
        printf("%d\n", number);
        
        rdint(&number);

        puts("===REVERSE==="); 
        printf("%d\n", number); 
    } 
    return 0;
}

