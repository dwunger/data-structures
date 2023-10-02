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
int main()
{
    char my_str[] = "         Doggo     ";
    int len = sizeof(my_str) / sizeof(my_str[0]);
    // printf("length(): %d\nSizeof(): %d\n", length(my_str), len);
    // if (startswith(my_str, "Dog")){
    //     printf("%s starts with %s", my_str, "Dog");
    // }
    puts(my_str);
    printf("strlen : %d\n", len);
    strip(my_str);

    puts(my_str);
    len = strlen(my_str) + 1;
    printf("strlen : %d\n", len);
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