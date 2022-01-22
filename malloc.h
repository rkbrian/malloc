#ifndef MALLOC_H
#define MALLOC_H

#include <unistd.h>
#include <string.h>

/**
 * struct sizet_ctrler - something
 * @left: start of size
 * @right: end of size
 */
typedef struct sizet_ctrler
{
	size_t left;
	size_t right;
} ctrl_t;

void *naive_malloc(size_t size);
void *_malloc(size_t size);
void _free(void *ptr);
/* my functions */
size_t aligner(size_t size);
void *fit_chunk(size_t csize, void *ret_ptr);

#endif /* MALLOC_H */
