#include "head.h"

/**
 * _perror - print in stderr
 * @str: name of shell program
 * @string: message error
 * Return: nothing
 */

void _perror(const char *str, const char *string)
{
	if (!str || !string)
		return;

	while (*str)
	{
		write(STDERR_FILENO, str, 1);
		str++;
	}

	write(STDERR_FILENO, ": ", 2);

	while (*string)
	{
		write(STDERR_FILENO, string, 1);
		string++;
	}
	write(STDERR_FILENO, "\n", 1);
}


/**
 * _trim - remove leading and trailing spaces and tabs from a string
 * @str: string input
 * Return: nothing
 */

void _trim(char *str)
{
	int x, y, l = _strlen(str);

	for (x = 0; x < l && (str[x] == ' ' || str[x] == '\t'); x++)
		;

	for (y = 0; x < l ; x++, y++)
		str[y] = str[x];

	str[y] = '\0';

	for (x = _strlen(str) - 1; x > 0 && (str[x] == ' ' || str[x] == '\t'); x--)
		str[x] = '\0';
}


/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer void
 * @nsize: unsigned int
 * Return: new allocated memory
 */

void *_realloc(void *ptr, unsigned int nsize)
{
	char *p;
	unsigned int x, tp = nsize, osize = sizeof(ptr);

	if (osize == nsize)
		return (ptr);
	if (ptr == NULL)
		return (malloc(nsize));

	if (nsize > osize)
		tp = osize;

	if (nsize == 0)
	{
		free(ptr);
		return (NULL);
	}

	p = malloc(nsize);

	for (x = 0; x < tp; x++)
		p[x] = ((char *)ptr)[x];
	free(ptr);
	return (p);
}
