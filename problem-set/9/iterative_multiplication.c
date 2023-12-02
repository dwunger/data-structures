// Write a program to calculate mn value using do-while loop.

#include <stdio.h>
#include <assert.h>

int iter_mult(const int m, const int n);

int main(void) 
{
    int m, n, r;
    for (int i = 0; i < 256; i++) {
        m = 0 - i;
        n = 0 + i;
        r = iter_mult(m, n);
        printf("%d * %d = %d\n", m, n, r);
        assert(r == (m * n));
    }
    return 0;
}


int iter_mult(const int m, const int n)
{
    int result = 0;
    do {
        result += m;    
    } while (result != (m*n));
    return result;
}
