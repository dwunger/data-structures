#include <stdio.h>
#include <string.h>
#include <time.h>
void unbuffered_print_int_arr(int * arr, int len);
void print_int_arr(int * arr, int len);


int main()
{
    int arr[4096];
    for (int i = 0; i < 4096; i++)
    {
        arr[i] = i;
    }
    int len = sizeof(arr)/sizeof(arr[0]);

    clock_t start, end, timer1, timer2;

    start = clock();
    unbuffered_print_int_arr(arr, len);
    end = clock();
    timer1 = end - start;  // Time taken for unbuffered_print_int_arr

    start = clock();
    print_int_arr(arr, len);
    end = clock();
    timer2 = end - start;  // Time taken for print_int_arr

    printf("Time taken for unbuffered_print_int_arr: %lf seconds\n", (double)timer1 / CLOCKS_PER_SEC);
    printf("Time taken for print_int_arr: %lf seconds\n", (double)timer2 / CLOCKS_PER_SEC);
    double factor = (double)timer1 / (double)timer2;
    printf("print_int_arr is x%.2lf faster.\n", factor);

    return 0;
}

void print_int_arr(int * arr, int len)
{
    char buffer[4096*11] = "";
    for (int i = 0; i < len; i++)
    {
        char num[13];
        sprintf(num, "%d", arr[i]);
        strcat(buffer, num);
        strcat(buffer, "\n");
    }
    printf(buffer);
    
}
void unbuffered_print_int_arr(int * arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d", arr[i]);
        puts("");
    }
}
