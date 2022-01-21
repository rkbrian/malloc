/* Description: Allocating 100 times 5,000 bytes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "malloc.h"

#define ALLOC_SIZE	5000
#define ALLOC_NB	100

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
	int i;
	void *ptr[ALLOC_NB];

	/* Allocate and initialize memory chunks */
	for (i = 0; i < ALLOC_NB; i++)
	{
		ptr[i] = _malloc(ALLOC_SIZE);
		if ((unsigned long int)ptr[i] % 8 != 0)
		{
			fprintf(stderr, "Address is not correctly aligned\n");
			return (EXIT_FAILURE);
		}
		memset(ptr[i], 'H', ALLOC_SIZE);
	}

	/* Make sure that allocated chunks are left intact */
	for (i = 0; i < ALLOC_NB; i++)
	{
		int j;

		for (j = 0; j < ALLOC_SIZE; j++)
		{
			if (((char *)ptr[i])[j] != 'H')
			{
				fprintf(stderr, "Allocated memory has been overwritten\n");
				return (EXIT_FAILURE);
			}
		}
	}

	printf("OK\n");
	return (EXIT_SUCCESS);
}
