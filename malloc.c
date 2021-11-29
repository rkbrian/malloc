#include "malloc.h"

/**
 * _malloc - my own malloc function that allocates space in the heap
 * @size: the size needed to be allocated for the user
 * Return: a pointer to the allocated memory that is suitably aligned
 *  for any kind of variable
 */
void *_malloc(size_t size)
{
	size_t chunk_hdr = aligner(size + sizeof(size_t));
	static size_t new_alloc;
	void *ret_ptr;
	static void *headptr, *current;
	static long page_size;

	if (!size)
		return (NULL);
	if (chunk_hdr <= )
		return (????);
	while (new_alloc < chunk_hdr)
	{
		if (headptr == NULL)
		{
			page_size = sysconf(_SC_PAGESIZE);
			headptr = sbrk(page_size);
			if (headptr == (void *)-1) /* wrong addr, failed allocation */
			{
				headptr = NULL, current = NULL;
				return (NULL);
			}
			current = headptr;
		}
		else if (sbrk(page_size) == (void *)-1) /* wrong addr of occupied mem */
			return (NULL);
		new_alloc = new_alloc + page_size;
	}
	ret_ptr = headptr;
	memcpy(ret_ptr, &chunk_hdr, sizeof(chunk_hdr));
	headptr = (void *)((char *)(ret_ptr) + chunk_hdr);
	return ((void *)((char *)(ret_ptr) + aligner(sizeof(chunk_hdr))));
}

/**
 * aligner - Linux uses 8-byte alignment
 * @size: size before align
 * Return: aligned value
 */
size_t aligner(size_t size)
{
	/* mask everything before composites of 8 */
	return ((8 - 1 + size) & ~(8 - 1));
}
