#include "head.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @string: str input*
 * Return: pointer
 */
char *_strdup(const char *string)
{
	int x, l = 0;
	char *resu;

	if (string == NULL)
		return (NULL);

	while (string[l] != '\0')
		l++;

	resu = (char *)malloc((l + 1) * sizeof(char));

	if (resu == NULL)
		return (NULL);

	for (x = 0; x <= l; x++)
		resu[x] = string[x];

	return (resu);
}


/**
 * _isnumber - check if str is a nmbr
 * @stat: string to be checked
 * Return: nothing
 */

int _isnumber(const char *stat)
{
	if (stat == NULL || stat[0] == '\0')
		return (0);
	while (*stat)
	{
		if (!_isdigit(*stat))
			return (0);
		stat++;
	}
	return (1);
}


/**
 * _isdigit - check if char is a nmbr
 * @c: char
 * Return: 1 if its a digit 0 otherwise
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

