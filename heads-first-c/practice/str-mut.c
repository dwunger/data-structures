#include <stdio.h>
#include <stdbool.h>

int startswith_len(const char * str, const char * sub_str, int len);
int length(const char * str);
int main()
{
    char my_str[] = "Doggo";
    int len = sizeof(my_str) / sizeof(my_str[0]);
    printf("length(): %d\nSizeof(): %d", length(my_str), len);
    if (startswith_len(my_str, "Dog", len))
    {
        printf("my_str starts with %s", "Dog");
    }
    return 0;
}
int length(const char * str)
{
    int len = 0;

    while (*str != '\0')
    {
        str++;
        len++;
    }
    //Includes null terminating character in length
    return len + 1;
}
int startswith_len(const char * str, const char * sub_str, int len)
{
    for (int i = 0; i < len; i++)
    {
        //todo: implement length()
        continue;
    }
    return 0;
}