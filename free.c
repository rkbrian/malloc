#include "malloc.h"

/**
 * _free - my own free function that frees a memory space
 * @ptr: a pointer to the memory space to be freed
 */
void _free(void *ptr)
{
	char *headptr;
	ctrl_t *controller;

	if (ptr)
	{
		headptr = (char *)ptr - sizeof(ctrl_t);
		controller = (ctrl_t *)headptr;
		controller->right = 0;
	}
}
