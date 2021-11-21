#include "malloc.h"

/**
 * _free - my own free function that frees a memory space
 * @ptr: a pointer to the memory space to be freed
 */
void _free(void *ptr)
{
	void *headptr;

	if (ptr)
	{
		headptr = (void *)((char *)(ptr) - aligner(sizeof(size_t)));
		headptr = (void *)((long int)headptr & ~1L); /* bitmask to clear all bits */
	}
}
