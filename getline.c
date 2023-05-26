#include "head.h"

/**
 * _getlineh - getline helper fnct
 * @linep: str input
 * @n: int input
 * Return: int
 */

int _getlineh(char **linep, size_t *n)
{
	if (*linep == NULL || *n == 0)
	{
		*n = 128;
		*linep = malloc(*n);
		if (*linep == NULL)
			return (-1);
	}
	return (0);
}

/**
 * _getline - reads inputs from FILE
 * @linep: str input
 * @n: int input
 * @strm: FILE input
 * Return: ssize_t
 */

ssize_t _getline(char **linep, size_t *n, FILE *strm)
{
	ssize_t bytesR = 0;
	size_t posi = 0, nSize;
	static char buff[BUFSIZE];
	static size_t bfS, bfP;
	char *nBuffer;

	if (linep == NULL || n == NULL || strm == NULL
		|| _getlineh(linep, n) == -1)
		return (-1);
	while (1)
	{
		if (bfP >= bfS)
		{
			bytesR = read(strm->_fileno, buff, BUFSIZE);
			if (bytesR <= 0 && posi == 0)
				return (-1);
			else if (bytesR <= 0)
				break;
			bfS = bytesR;
			bfP = 0;
		}
		if (posi >= *n - 1)
		{
			nSize = *n * 2;
			nBuffer = realloc(*linep, nSize);
			if (nBuffer == NULL)
				return (-1);
			*linep = nBuffer;
			*n = nSize;
		}
		(*linep)[posi++] = buff[bfP++];
		if ((*linep)[posi - 1] == '\n')
			break;
	}
	(*linep)[posi] = '\0';
	return (posi);
}
