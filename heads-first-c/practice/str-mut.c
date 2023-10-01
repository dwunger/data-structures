#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int startswith(const char * str, const char * sub_str);
int length(const char * str);

int main()
{
    char my_str[] = "  Doggo";
    int len = sizeof(my_str) / sizeof(my_str[0]);
    // printf("length(): %d\nSizeof(): %d\n", length(my_str), len);
    // if (startswith(my_str, "Dog")){
    //     printf("%s starts with %s", my_str, "Dog");
    // }
    my_str = lstrip(my_str);
    puts(my_str);
    return 0;
}
int length(const char * str)
{
    /*
    int len = 0;
    while (*str != '\0'){
        str++;
        len++;
    }
    */
    //+1 null terminator
    //read the docs
    int len = strlen(str);
    return len + 1;
}
int startswith(const char * str, const char * sub_str)
{
    int len = length(sub_str) - 1;
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
char * lstrip(char * str)
{
    int len = strlen(str) + 1;
    int removed = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            //re-terminate the string
            for (int j = len - removed; j < len; j++)
            {
                str[j] = '\0';
            }
            break;
        }
        if (str[i] == ' ')
        {
            removed++;
            str[i] = str[i+1];
        }
    }
    return str;
}