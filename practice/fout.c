#include <stdio.h>

int main(void) 
{
    FILE *file;
    file = fopen("file.txt", "w");

    if (file == NULL)
    {
        fprintf(stderr, "Unable to open file.\n");
        return 1;       
    }
    fprintf(file, "123456789\n");

    fclose(file);

    return 0;
}