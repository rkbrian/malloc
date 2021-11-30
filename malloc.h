#ifndef MALLOC_H
#define MALLOC_H

#include <unistd.h>
#include <string.h>

void *naive_malloc(size_t size);
void *_malloc(size_t size);
void _free(void *ptr);
/* my functions */
size_t aligner(size_t size);
void *fit_chunk(size_t csize, void *ret_ptr);

#endif /* MALLOC_H */
