#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"

/**
 * main - test naive malloc
 * Return: 0
 */
int main()
{
	char *str;

	str = naive_malloc(sizeof(char *));
	if (str == NULL)
	{
		printf("wrong!\n");
		return (0);
	}
	strcpy(str, "naive");
	printf("%s\n", str);
	_free(str);
	if (str == NULL)
		printf("I'm freed!\n");
	return (0);
}
