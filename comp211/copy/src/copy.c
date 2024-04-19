#include "Guards.h"
#include "copy.h"

void* copy(void *destination, const void *source, size_t num)
{
    OOM_GUARD(destination);
    OOM_GUARD(source);
    
    char *dst_ptr = destination;
    char *src_ptr = source;

    for (size_t i = 0; i < num; ++i) {
        *dst_ptr = *src_ptr;
        dst_ptr++;
        src_ptr++;
    }
    return destination;

}
