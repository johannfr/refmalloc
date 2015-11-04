#include "vector.h"

void *refmalloc(Vector *refVector, size_t size);

void reffree(Vector *refVector, void *ptr);
