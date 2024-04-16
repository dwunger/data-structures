#include <stdio.h>
#include <stdlib.h>

void* OOM_GUARD(void *p){
    if (p == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

