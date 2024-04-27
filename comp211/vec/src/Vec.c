#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "Guards.h"
#include "Vec.h"

static void _ensure_capacity(Vec *self, size_t n);
    
/* Constructor / Destructor */

Vec Vec_value(size_t capacity, size_t item_size)
{
    Vec vec = {
        item_size,
        0,
        capacity,
        calloc(capacity, item_size)
    };
    OOM_GUARD(vec.buffer, __FILE__, __LINE__);
    return vec;
}

void Vec_drop(Vec *self)
{
    free(self->buffer);
    self->buffer = NULL;
    self->capacity = 0;
    self->length = 0;
}

/* Accessors */

size_t Vec_length(const Vec *self)
{
    return self->length;
}

const void* Vec_items(const Vec *self)
{
    return self->buffer;
}

/* Operations */

void* Vec_ref(const Vec *self, size_t index)
{
    
    return self->buffer + (index * self->item_size);
}

void Vec_get(const Vec *self, size_t index, void *out)
{
    memcpy(out, Vec_ref(self, index), self->item_size); 
}

void Vec_set(Vec *self, size_t index, const void *value)
{
    // Since buffer has not been casted to the correct type, incrementing
    // the address will add 1 byte rather than the item_size.
    // As the type information is not known at runtime, casting cannot
    // be performed for automatic pointer arithmetic
    memcpy((char *)self->buffer + index * self->item_size, value, self->item_size);
    
    if (index + 1 > self->length) {
        self->length = index + 1;
    }

    
}

/* Helpers */

static void _ensure_capacity(Vec *self, size_t n) 
{
    if (n > self->capacity) {
        size_t new_capacity = n * 2;
        self->buffer = realloc(self->buffer, new_capacity * self->item_size);
        OOM_GUARD(self->buffer, __FILE__, __LINE__);
        self->capacity = new_capacity;
    }
}
