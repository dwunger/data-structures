//Write a program to check whether the given number is a palindrome or not.

#include <stdio.h>
#include <assert.h>
#include <string.h>

int is_palindrome(const char *str);

int main(void)
{
    char example_palindrome[] = "racecar";
    char false_palindrome[] = "palindrome";
    int test = -1;
    
    test = is_palindrome(example_palindrome);
    
    assert(test == 1);
    
    test = is_palindrome(false_palindrome);
    
    assert(test == 0);
    puts("All tests passing!");
    return 0;
}

int is_palindrome(const char *str)
{
    if (!str) {
        fprintf(stderr, "Received unitialized pointer");
    }
    int len = strlen(str);
    // a palindrome must have a non-zero count of characters
    if (len == 0) {
        return 0;
    }
    // checking full length of string is redundant
    for (int i = 0; i < len/2; i++) {
        //printf("%c != %c\n", str[i], str[len -1 - i]);
        if (str[i] != str[len - 1 - i]) return 0;
    }
    return 1;
    
}
