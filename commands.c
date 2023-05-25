#include "head.h"
/**
 * cmd - function to run commands
 * @cd: command used as example, the function should work on all bin commands
 * Return: command or NULL
 */

char *cmd(char *cd)
{
	char *path = getit("PATH");
	char *search, *adress, *tmp;
	struct stat check;

	search = strtok(path, ":");
	while (search != NULL)
	{
		adress = malloc(strlen(search) + strlen(cd) + 2);
		tmp = malloc(strlen(search) + strlen(cd) + 2);
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
