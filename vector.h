#ifndef __VECTOR_H__
#define __VECTOR_H__

#define VECTOR_INITIAL_CAPACITY 10

typedef struct {
  unsigned int size;        // slots used so far
  unsigned int capacity;    // total available slots
  void **data;              // array of pointers
} Vector;

void vector_init(Vector *vector);

void vector_append(Vector *vector, void *ptr);

void *vector_get(Vector *vector, int index);

int vector_has(Vector *vector, void *ptr);

void vector_set(Vector *vector, int index, void *ptr);

void vector_double_capacity_if_full(Vector *vector);

void vector_free(Vector *vector);

void vector_print(Vector *vector);

#endif
