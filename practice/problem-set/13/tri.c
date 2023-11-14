//13) Write a program to print the following format.
//*
//* *
//* * *
//* * * *
//* * * * *
#include <stdio.h>
void print_triangle(int rows) 
{

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < i + 1; j++) 
        {
            printf("* ");
        }
        printf("\n");
    }
}


int main(void)
{
    print_triangle(5);    
    return 0;
}
