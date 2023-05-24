#include "head.h"
/**
 * envhan - handling env
 * @store: where data is stored
 * @data: value stored
 * Return: 0 or -1
 */
int envhan(const char *store, const char *data)
{
	int ndata = 0, i = 0, length = 0;/* ndata checks if new data shld overwrite */
	extern char **environ; /* global variable */
	char *temp, *dataloc; /* to allocate memory to store new data */
	int envlen = 0, datalen = 0;

	if (*store != '\0')
	{
		if (*data != '\0')
		{
			while (environ[i] != NULL)
			{
				length = strlen(store);
				envlen = strlen(environ[i]);
				datalen = (strlen(data) + 1);
				if (length == envlen)
				{
					if (ndata != '\0')
					{
						dataloc = malloc(length + datalen + 1);
						strcpy(dataloc, store);
						strcat(temp, "="), strcat(temp, store);
						strcat(dataloc, temp);
						environ[i] = dataloc;
						return (0);
					}
					return (0);
				}
				i++;
			}
			dataloc = malloc(length + datalen + 1);
			strcpy(dataloc, store);
			strcat(temp, "="), strcat(temp, store), strcat(dataloc, temp);
			environ[i] = dataloc;
			return (0);
		}
		return (-1);
	}
	return (-1);
}
