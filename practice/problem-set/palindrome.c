//Write a program to check whether the given number is a palindrome or not.

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

int is_palindrome(const char *str);
int is_palindrome_slow(const char *str);

int main (void)
{
    char example_palindrome[] = "racecar";
    char false_palindrome[] = "palindrome";
    int test = -1;
    
    test = is_palindrome(example_palindrome);
    
    assert(test == true);
    
     
    test = is_palindrome(false_palindrome);
    
    assert(test == false);
     
    
    return 0;
}

int is_palindrome(const char *str)
{

    int len = strlen(str);
    
    for (int i = 0; i <= len; i++) {
        if (str[])
    }
}
int is_palindrome_slow(const char *str);
