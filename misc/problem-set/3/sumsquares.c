//3) Write a program to calculate the sum of squares of first n natural 
//numbers using while loop.

#include <stdio.h>

int main(void)
{
    int i = 0;
    int range = 0;
    scanf("%d", &range);
    int sum = 0;
    while (i <= range)
    {
        printf("%d + %d ^ 2 = %d + %d = %d\n", sum, i, sum, (i*i), (sum + (i*i)));

        sum += (i * i);
        i++;
    }
    printf("Result = %d", sum);
    return 0;
}

