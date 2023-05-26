#include "head.h"

/**
 * simples - function to simplify the string
 * @buff: buffer
 * @d: delimiters
 * Return: each part of string inputed
 */

char **simples(char *buff, char *d)
{
	char **parts = malloc(sizeof(char *) * 1024); /* each token of string */
	char *p = strtok(buff, d);
	int i = 0, j, k;
	char *next;

	while (p != NULL)
	{
		parts[i] = p;
		p = strtok(NULL, d); /* to continue strtok func */
		i++;
	}
	parts[i] = NULL;
	for (j = 0; j < i - 1; j++)
	{
		for (k = j + 1; k < i; k++)
		{
			if (strcmp(parts[j], parts[k]) > 0)
			{
				next = parts[j];
				parts[j] = parts[k];
				parts[k] = next;
			}
		}
	}
	return (parts);
	free(parts);
}
