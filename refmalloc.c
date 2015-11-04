#include <stdlib.h>
#include "refmalloc.h"

void *refmalloc(Vector *refVector, size_t size)
{
    void *ptr = malloc(size);
    vector_append(refVector, ptr);
    return ptr;
}

void reffree(Vector *refVector, void *ptr)
{
    int index = vector_has(refVector, ptr);
    if (index > -1)
    {
        free(ptr);
        vector_set(refVector, index, NULL);
    }
}
