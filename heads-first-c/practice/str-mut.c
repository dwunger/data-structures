#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int startswith(const char * str, const char * sub_str);
void lstrip(char * str);
int main()
{
    char my_str[] = "  Doggo";
    int len = sizeof(my_str) / sizeof(my_str[0]);
    // printf("length(): %d\nSizeof(): %d\n", length(my_str), len);
    // if (startswith(my_str, "Dog")){
    //     printf("%s starts with %s", my_str, "Dog");
    // }
    lstrip(my_str);
    puts(my_str);
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
    int offset = sizeof(str[0]);
    for (int i = 0; i < (len - leading_spaces); i++) {
        str[i] = str[i + leading_spaces];
        char let = str[i + leading_spaces];
        printf("%c", let);
    }
    for (int i = 0; i < (leading_spaces); i++) {
        str[len - leading_spaces + i] = '\0';
    }
    puts("");
}