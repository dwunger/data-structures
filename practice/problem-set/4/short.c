//4) Write a program to illustrate short hand operators used in C.

#include <stdio.h>

int main(void)
{
    char * delimiter = "============";
    int x = 1;
    int y = 2;
    
    puts("\nResults will not carry between operations\nShorthand operators:");
    puts(delimiter);

    puts("ADDITION");
    puts(delimiter);

    printf("x = %d, y = %d\n", x, y);
     
    puts(delimiter);
    
    printf("x = x + y;\nx = %d;\n", (x + y));
    
    puts(delimiter);
    
    printf("x += y;\nx = %d;\n", (x += y));
    
    x = 1;
    
    puts(delimiter);
 
    puts("Bitwise Left");

    puts(delimiter);
    
    printf("x = x << y;\nx = %d\n", (x <<y));

    puts(delimiter);

    printf("x <<= y;\nx = %d;", (x <<= y));

    return 0;
}

