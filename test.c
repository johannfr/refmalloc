#include <stdlib.h>
#include "refmalloc.h"

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
