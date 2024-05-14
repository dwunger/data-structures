#ifndef VEC_H
#define VEC_H
    
typedef struct Vec {
    const size_t item_size;
    size_t length;
    size_t capacity;
    void *buffer;
} Vec;


#endif

