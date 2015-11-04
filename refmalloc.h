#ifndef __REFMALLOC_H__
#define __REFMALLOC_H__

#include "vector.h"

void *refmalloc(Vector *refVector, size_t size);

void reffree(Vector *refVector, void *ptr);

#endif
