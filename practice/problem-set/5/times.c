/*

5) Write a program to print the multiplication table in the following format.
  1 2 3 4 5
1 1 2 3 4 5
2 2 4 6 8 10
3 3 6 9 12 15
4 4 8 12 16 20
5 5 10 15 20 25

*/

#include <stdio.h>
#define RANGE 10

int main(void)
{

    printf("%2s", "");
    // CREATE TABLE HEADER
    //   1 2 3 4 5 ... RANGE
    for (int i = 1; i < RANGE; i++)
    {
        printf("%5d", (i));
    }
    
    for (int y = 1; y < RANGE; y++)
    {
        // ADD LEADING DIGIT WITHOUT TRAILING SPACE 
        // 1
        // ...
        // RANGE
        printf("\n%2d", y);
        
        for (int x = 1; x < RANGE; x++)
        {
            // APPEND LEFT PADDED DIGIT TO ROW
            printf("%5d", (x * y));
        }
        
         
    }

    return 0;

}
