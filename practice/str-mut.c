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
char **split(const char *str, char delimiter);

int main()
{
    char **result;
    const char *test_string = "This,is,a,test,string";
    char delimiter = ',';

    result = split(test_string, delimiter);

    int i = 0;
    while (result[i] != NULL) {
        printf("Segment %d: %s\n", i, result[i]);
        i++;
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
    int len = strlen(str);
    // Initial pass to collect some details for memory allocation
    // max_len -> malloc space for the length of the longest substring
    // count -> total count of resulting substrings 
    // sub_len -> temporary variable to track len of substrings
    int substr_count = 0;
    int substr_len = 0;
    int max_len = 0;
    for (int i = 0; i < len; i++)
    {   
        if (str[i] == delimiter || str[i] == '\0') 
        {
            substr_count++; 
            if (substr_len > max_len) {
                max_len = substr_len;
            }
            substr_len = 0;
        } else {
            substr_len++;
        }
    }

    // get a pointer to each item and deposit in 2D array of count rows
    // need to malloc space on heap
    // char split_strings = malloc(sizeof(char[substr_count][max_len]));
    // Allocating memory for 2D array
    char **split_strings = malloc(substr_count * sizeof(char *));
    for(int i = 0; i < substr_count; i++) {
        split_strings[i] = malloc(max_len * sizeof(char));
    }
    // Set the last pointer to NULL
    split_strings[substr_count] = NULL;

    int characters_tested = 0;
    
    for (int i = 0; i < substr_count; i++) {
        if (characters_tested == len) {
            return split_strings;
        }

        for (int j = 0; j < max_len; j++) { 
            // deposit & break on delimiter or sentinel value
            if (str[characters_tested] == delimiter || str[characters_tested] == '\0') {
                split_strings[i][j] = '\0';  // Null-terminate the current substring
                characters_tested++; 
                break;
            } else {
                split_strings[i][j] = str[characters_tested];
                characters_tested++;
            }
        }
    }
}