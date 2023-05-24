#include "head.h"

/**
 **_strncpy - cpy a str
 *@dest: destination to be copied to
 *@src: the source of string
 *@n: Amount of char to be copied
 *Return: Concatenated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates 2 strings
 *@dest: 1st string
 *@src: 2nd string
 *@n: Amount of bytes to be maximally used
 *Return: Concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	b = 0;

	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < n)
		dest[a] = '\0';
	return (s);
}

/**
 **_strchr - locates a char in a string
 *@s: String to be parsed
 *@c: Character to look for
 *Return: Pointer to the memory area s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
