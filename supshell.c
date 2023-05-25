#include "head.h"

/**
 * envhan - handling env
 * @store: where data is stored
 * @data: value stored
 * @ndata: checks if new data shld overwrite
 * Return: 0 or -1
 */

int envhan(const char *store, const char *data, int ndata)
{
	int i = 0, length = 0;
	char **env = environ; /* global variable */
	char *dataloc; /* to allocate memory to store new data */
	int datalen = 0;

	if (*store != '\0')
	{
		if (*data != '\0')
		{
			while (env[i] != NULL)
			{
				length = strlen(env[i]);
				datalen = (strlen(data) + 1);
				if (strncmp(env[i], store, length) == 0)
				{
					if (ndata != '\0')
					{
						free(env[i]);
						dataloc = malloc(length + datalen + 1);
						strcpy(dataloc, store);
						strcat(dataloc, "=");
						strcat(dataloc, data);
						env[i] = dataloc;
						return (0);
					}
					return (0);
				}
				i++;
			}
			dataloc = malloc(strlen(store) + strlen(data) + 2);
			strcpy(dataloc, store);
			strcat(dataloc, "=");
			strcat(dataloc, data);
			env[i] = dataloc;
			env[i + 1] = NULL;
		}
		return (-1);
	}
	return (-1);
}
