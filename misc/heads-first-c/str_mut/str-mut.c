#include <stdio.h>
#include <stdbool.h>
int iseven(int num)
{
    if (num % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int startswith(const char * str, const char * sub_str,  int len)
{
    for (int i = 0; i < len; i++)
    {
        //will finish later
    }
}
int main()
{
    int number = 5;
    if (iseven(number))
    {
        puts("True!");
    }
    return 0;
}