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
	if (chunk_hdr <= local_max)
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
	ret_ptr = *((size_t *)(ret_ptr)) |= 1; /* need to touble check later */
	headptr = (void *)((char *)(ret_ptr) + sizeof(ret_ptr));
	new_alloc = new_alloc - page_size;
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

size_t local_max = 0;

/**
 * fit_chunk - find the best fit of heap chunk for allocation 
 * @csize: chunk size to fit into the heap
 * @ret_ptr: ptr to the allocated memory, to be returned in main malloc func
 * Return: pointer to the best fit, which is >= the given chunk size
 */
void *fit_chunk(size_t csize, void *ret_ptr)
{
	size_t fitflag = 0, ptr_size = (*((size_t *)(ret_ptr)) >> 1) << 1, next_size;
	static size_t max_size;
	void *next_ptr = NULL;

	if ((*((size_t *)(ret_ptr)) & 1) == NULL && (csize <= ptr_size))
	{
		if (local_max == ptr_size)
			fitflag = 1;
		max_size = ptr_size, memcpy(ptr_size, &csize, sizeof(csize));
		ret_ptr = *((size_t *)(ret_ptr)) |= 1;
		if (csize < max_size && (max_size - csize) > 8)
		{
			next_ptr = (void *)((char *)(ret_ptr) + sizeof(ret_ptr)), max_size -= csize;
			memcpy(next_ptr, &max_size, sizeof(max_size));
		}
		if (fitflag)
		{
			if (next_ptr)
				max_size = (*((size_t *)(next_ptr)) >> 1) << 1;
			else
				max_size = 0;
			next_ptr = (void *)((char *)(ret_ptr) + sizeof(ret_ptr));
			next_size = (*((size_t *)(next_ptr)) & 1);
			while (next_size)
			{
				if (!(*((size_t *)(next_ptr)) & 1) && next_size > max_size)
					max_size = next_size;
				next_ptr = (void *)((char *)(ret_ptr) + sizeof(ret_ptr));
				next_size = (*((size_t *)(next_ptr)) & 1);
			}
			local_max = max_size;
		}
		max_size = 0;
		return ((void *)((char *)(ret_ptr) + aligner(sizeof(size_t))));
	}
	if (!(*((size_t *)(ret_ptr)) & 1) && ptr_size > max_size)
		max_size = ptr_size;
	return (fit_chunk(csize, (void *)((char *)(ret_ptr) + sizeof(ret_ptr))));
}
