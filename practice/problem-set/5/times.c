/*

5) Write a program to print the multiplication table in the following format.
1 2 3 4 5
1 1 2 3 4 5
2 2 4 6 8 10
3 3 6 9 12 15
4 4 8 12 16 20
5 5 10 15 20 25

*/

include <stdio.h>
#define RANGE 5

int main(void) 
{
    int x = 1;
    int y = 1;
    puts("  1 2 3 4 5");

    for (int i = 0; i < RANGE; i++)
    {
        printf("%d", (i + 1));
i       printf(" %d", (x +
    }

}


