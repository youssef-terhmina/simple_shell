#include "head.h"

/**
 * _strlen - returns nbr of char in str
 * @str: string input
 * Return: nbr of char in str.
 */

unsigned int _strlen(char *str)
{
	unsigned int x;

	for (x = 0; str[x] != '\0'; x++)
		;
	return (x);
}


/**
 * _strcmp - compares 2 str
 * @s: input const str
 * @ss: input const str
 * Return: returns an int indicating result of the comparison as follows:
 *		• 0, if s & ss are equal
 *		• a negative value if s is less than ss
 *		• a positive value if s is greater than ss
 */

int _strcmp(const char *s, const char *ss)
{
	int x;
	int re = 0;

	for (x = 0; s[x] != '\0' && ss[x] != '\0'; x++)
	{
		if (s[x] != ss[x])
		{
			re = s[x] - ss[x];
			break;
		}
	}

	return (re);
}

/**
 * _strncmp - compares 2 str
 * @s: input const string
 * @ss: input const string
 * @n: input int
 * Return: returns an int indicating result of the comparison as follows:
 *		• 0, if s & ss are equal
 *		• a negative value if s is less than ss
 *		• a positive value if s is greater than ss
 */

int _strncmp(const char *s, const char *ss, int n)
{
	int x;
	int re = 0;

	for (x = 0; s[x] != '\0' && ss[x] != '\0'; x++)
	{

		if (x >= n)
			break;
		if (s[x] != ss[x])
		{
			re = s[x] - ss[x];
			break;
		}
	}

	return (re);
}

/**
 * _strcpy - copy src to dest
 * @de: input char *
 * @sr: input const char *
 * Return: char *
 */

char *_strcpy(char *de, const char *sr)
{
	int l;

	for (l = 0; sr[l] != '\0'; ++l)
	{
		de[l] = sr[l];
	}
	de[l] = '\0';
	return (de);
}

/**
 * _strcat - appends src str to dest str
 * @de: input str
 * @sr: input const str
 * Return: nothing
 */

char *_strcat(char *de, const char *sr)
{
	char *resu = de;

	while (*de != '\0')
		de++;

	while (*sr != '\0')
	{
		*de = *sr;
		de++;
		sr++;
	}
	*de = '\0';

	return (resu);
}
