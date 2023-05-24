#include "head.h"

/**
 * getit - to find path to bin where toget commands
 * @var: variable to find in path
 * Return: NULL
 */

char *getit(const char *var)
{
	char **env = environ, *point; /* point is a pointer to the var in env array */
	int i = 0;
	char *cont; /* to continue strtok function */

	while (env[i] != NULL)
	{
		point = strtok(env[i], "=");
		cont = point;
		if (strcmp(cont, var) == 0)
		{
			cont = (strtok(NULL, "\n"));
			return (cont);
		}
		i++;
	}
	return (NULL);
}
