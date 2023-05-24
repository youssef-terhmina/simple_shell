#include "head.h"
/**
 * cmd - function to run commands
 * @cd: command used as example, the function should work on all bin commands
 * Return: command or NULL
 */

char *cmd(char *cd)
{
	char *path = getit("PATH");
	char *tmp, *search, *adress;
	struct stat check;
	int len, clen;

	search = strtok(path, ":");
	while (search != NULL)
	{
		len = (strlen(search) + 1);
		clen = (strlen(cd) + 1);
		tmp = malloc(len + clen);
		adress = malloc(len + clen);
		strcpy(adress, search);
		strcat(tmp, "/");
		strcat(tmp, cd);
		strcat(adress, tmp);
		if (stat(adress, &check) == 0)
		{
			free(tmp);
			return (adress);
		}
		free(adress);
		free(tmp);
		search = strtok(NULL, ":");
	}
	return (NULL);
}
