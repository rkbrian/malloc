#ifndef MALLOC_H
#define MALLOC_H

#include <unistd.h>

/**
 *
 */
void *naive_malloc(size_t size);
void *_malloc(size_t size);
void _free(void *ptr);

#endif /* MALLOC_H */
