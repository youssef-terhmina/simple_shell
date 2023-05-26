#include "head.h"

/**
 * _strlen - returns nbr of char in str
 * @str: string input
 * Return: nbr of char in str.
 */

unsigned int _strlen(char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}


/**
 * _strcmp - compares 2 str
 * @s1: input const str
 * @s2: input const str
 * Return: returns an int indicating result of the comparison as follows:
 *		• 0, if s1 & s2 are equal
 *		• a negative value if s1 is less than s2
 *		• a positive value if s1 is greater than s2
 */

int _strcmp(const char *s1, const char *s2)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * _strncmp - compares 2 str
 * @s1: input const string
 * @s2: input const string
 * @n: input int
 * Return: returns an int indicating result of the comparison as follows:
 *		• 0, if s1 & s2 are equal
 *		• a negative value if s1 is less than s2
 *		• a positive value if s1 is greater than s2
 */

int _strncmp(const char *s1, const char *s2, int n)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * _strcpy - copy src to dest
 * @dest: input char *
 * @src: input const char *
 * Return: char *
 */

char *_strcpy(char *dest, const char *src)
{
	int len;

	for (len = 0; src[len] != '\0'; ++len)
	{
		dest[len] = src[len];
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _strcat - appends src str to dest str
 * @dest: input str
 * @src: input const str
 * Return: nothing
 */

char *_strcat(char *dest, const char *src)
{
	char *result = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (result);
}
