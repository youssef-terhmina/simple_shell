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
	int i = 0;
	char *next;

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
