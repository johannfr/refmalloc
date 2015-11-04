#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_init(Vector *vector) {
    // initialize size and capacity
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;
    vector->data = malloc(sizeof(void*) * vector->capacity);
}

void vector_append(Vector *vector, void *ptr) {
    // make sure there's room to expand into
    vector_double_capacity_if_full(vector);

    vector->data[vector->size++] = ptr;
}

void *vector_get(Vector *vector, int index) {
    if (index >= vector->size || index < 0) {
        printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
        exit(1);
    }
    return vector->data[index];
}

int vector_has(Vector *vector, void *ptr)
{
    int i = 0;
    for (i = 0; i < vector->size ; i++)
    {
        if (vector->data[i] == ptr)
        {
            return i;
        }
    }
    return -1;
}

void vector_set(Vector *vector, int index, void *ptr) {
    // zero fill the vector up to the desired index
    while (index >= vector->size) {
        vector_append(vector, 0);
    }

    vector->data[index] = ptr;
}

void vector_double_capacity_if_full(Vector *vector) {
    if (vector->size >= vector->capacity) {
        // double vector->capacity and resize the allocated memory accordingly
        vector->capacity *= 2;
        vector->data = realloc(vector->data, sizeof(void*) * vector->capacity);
    }
}

void vector_free(Vector *vector) {
    free(vector->data);
}

// This is actually only for debugging.
void vector_print(Vector *vector)
{
    int i = 0;
    for (i = 0 ; i < vector->size ; i++)
    {
        if (vector->data[i] != NULL)
        {
            printf("%p\n", vector->data[i]);
        }
    }
}
