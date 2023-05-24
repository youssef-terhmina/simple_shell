#include "head.h"
/**
 * simples - function to simplify the string
 * @buff: buffer
 * @d: delimiters
 * Return: each part of string inputed
 */
char **simples(char *buff, char *d)
{
	char **parts, *p; /* each token of string */
	int i;
	char *next;

	parts = malloc(sizeof(char *) * 1024); /* memory allocation */
	i = 0;
	p = strtok(buff, d);
	while (p != NULL)
	{
		parts[i] = p;
		next = strtok(NULL, d); /* to continue strtok func */
		p = next;
		i++;
	}
	parts[i] = NULL;
	return (parts);
}
