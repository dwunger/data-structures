#include <stdio.h>
#include <stdlib.h>

const void* OOM_GUARD(const void *p){
    if (p == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

