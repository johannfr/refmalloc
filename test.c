#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

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

int main()
{
    // Some basic initialization
    Vector ptrVector;
    vector_init(&ptrVector);


    // Here we use the awesome refmalloc define!
    char *foo = refmalloc(&ptrVector, sizeof(char)*20);


    // And intead of free() we use reffree!
    reffree(&ptrVector, foo);
    reffree(&ptrVector, foo);


    return 0;
}
