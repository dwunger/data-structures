#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char *str_salad(const char char_set[], int count)
{
    int len = strlen(char_set);
    char *str = malloc(sizeof(char) * (count + 1));

    // Seed the random number generator with the current time
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int random_number = rand() % len;
        str[i] = char_set[random_number];
    }
    str[count] = '\0';  // Add the null terminator
    return str;
}


int main() 
{
    //char char_set[] = "%%*()[]{}';:\"\\<>&^=+-_";
    char char_set[] = "()[]{}";
    char *generated_string = str_salad(char_set, 100);
    puts(generated_string);
    free(generated_string);
    return 0;
}

