//14) Program to calculate lucky number.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


int rand_range(int LIMIT) {
    int i = 0;
   
    struct timeval tv; 
    gettimeofday(&tv, NULL);
    srand((unsigned int)tv.tv_usec); 
    int random_int = rand(); 
    while (1) {
        i++;
        random_int = rand() % LIMIT;
        if (time(NULL) % 2 == 1 || i < 10) {     
            //printf("%d\n", random_int);
            break;
        }
    }
    return random_int;
}

int main(void)
{
    int limit = 100;
    int rand_int = rand_range(limit);
    for (int i = 0; i < 100; i++) {
        rand_int = rand_range(limit);
        printf("random: %d\n", rand_int);
    }
    return 0;
}

