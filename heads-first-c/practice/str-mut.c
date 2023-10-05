#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*
This is intended to handle naive implementations of some useful built-in functions from Python.
I have no expectation to optimize any of these (wasteful) solutions, but will instead use these to 
get a handle on basics syntax and strategies before moving on to more optimal data structures
*/

int startswith(const char * str, const char * sub_str);
void lstrip(char * str);
void rstrip(char * str);
void strip(char * str);
bool containsAnyChar(const char *str, const char *char_set);
int main()
{
    // char my_str[] = "         Doggo     ";
    // int len = sizeof(my_str) / sizeof(my_str[0]);
    // printf("length(): %d\nSizeof(): %d\n", length(my_str), len);
    // if (startswith(my_str, "Dog")){
    //     printf("%s starts with %s", my_str, "Dog");
    // }
    // puts(my_str);
    // printf("strlen : %d\n", len);
    // strip(my_str);

    // puts(my_str);
    // len = strlen(my_str) + 1;
    // printf("strlen : %d\n", len);
    struct test {
        const char *str;
        const char *char_set;
        bool expected;
    };

    struct test tests[] = {
        {"hello", "world", true}, // 'o' and 'l' are common characters
        {"apple", "banana", true}, // 'a' is a common character
        {"apple", "xyz", false},   // no common characters
        {"apple", "", false},      // empty char_set, no common characters
        {"", "banana", false},     // empty str, no common characters
        {"", "", false},           // both strings are empty
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        bool result = containsAnyChar(tests[i].str, tests[i].char_set);
        printf("Test %zu - str: \"%s\", char_set: \"%s\"\n", i + 1, tests[i].str, tests[i].char_set);
        printf("Expected: %d, Actual: %d\n", tests[i].expected, result);
        printf("--------------------------------\n");
    }

    return 0;
}

int startswith(const char * str, const char * sub_str)
{
    int len = strlen(sub_str);
    //Order of base conditions is important
    //Base condition: an empty substring should always produce a match
    if (len == 0){
        return true;
    }
    //Base condition: checking a null string should not produce a match
    if (str[0] == '\0'){
        return false;
    }

    for (int i = 0; i < len; i++){
        // 
        if (str[i] != sub_str[i]){
            return false;
        }
    }
    return true;       

}
void lstrip(char * str)
{
    if (str == NULL || *str == '\0') {
        // If string is NULL or empty, do nothing
        return;
    }
    int len = strlen(str);
    int leading_spaces = 0;

    // determine number of spaces to remove
    char *temp = str; // Use a temporary pointer to keep the original address of str intact
    while (*temp == ' ') {
        temp++; //str++ interferes with array indexing
        leading_spaces++;
    }
    //early return if no leading spaces
    if (leading_spaces == 0) {
        return;
    }
    //shift items in array
    for (int i = 0; i < (len - leading_spaces); i++) {
        str[i] = str[i + leading_spaces];
        char let = str[i + leading_spaces];
    }
    for (int i = 0; i < (leading_spaces); i++) {
        str[len - leading_spaces + i] = '\0';
    }
}
void rstrip(char * str)
{
    if (str == NULL || *str == '\0') {
        return;
    }
    int len = strlen(str);
    int trailing_spaces = 0;
    for (int i = 0; i < len; i++) {
        if (str[len - i - 1] != ' ') {
            break;
        }
        else {
            trailing_spaces++;
        }
    }
    if (trailing_spaces == 0) {
        return;
    }
    for (int i = 0; i < trailing_spaces; i++) {
        str[len - i - 1] = '\0';
    }
}
void strip(char * str) {
    lstrip(str);
    rstrip(str);
}
bool containsAnyChar(const char *str, const char *char_set)
{
    // one-liner: if (strpbrk(str, char_set) != NULL) {. . .}
    char *match = strpbrk(str, char_set);
    if (match != NULL) {
        return true;
    } else {
        return false;
    }
}

int chcount(const char *str, char character)
{
    int len = strlen(str);
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == character){
            count++;
        }
    }
    return count;
}
int chcountn(const char *str, char character, int len)
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == character){
            count++;
        }
    }
    return count;
}
char **split(const char *str, char delimiter)
{
    // Initial pass to collect some details for memory allocation
    // max -> malloc space for the length of the longest substring
    // count -> total count of resulting substrings 
    // sub_len -> temporary variable to track len of substrings
    int count = 0;
    int substr_len = 0;
    int max = 0;
    for (int i = 0; i < len; i++)
    {   
        if (str[i] == character){
            count++; 
            if (sub_len > max) {
                max = substr_len;
            }
            sub_len = 0;
        } else {
            substr_len++;
        }
    }
    int len = strlen(str);
    //count instances of delimiter in str
    //int count = chcountn(str, delimiter, len);
    //get a pointer to each item and deposit in 2D array of count rows
    //need to malloc space on heap
    arr = malloc(sizeof(char[ROWS][COLS]));
    for (int i = 0; i < count; i++)
    {
        for (int i = 0; i < len; i++)
        {
            //deposit & break on delimiter or sentinal value
        }
    }
}