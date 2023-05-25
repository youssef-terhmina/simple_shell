#include "head.h"
/**
 * cmd - function to run commands
 * @cd: command used as example, the function should work on all bin commands
 * Return: command or NULL
 */

char *cmd(char *cd)
{
	char *path = getit("PATH");
	char *tmp = NULL, *search, *adress = NULL;
	struct stat check;
	int len, clen;

	search = strtok(path, ":");
	while (search != NULL)
	{
		len = strlen(search);
		clen = strlen(cd);
		tmp = malloc(len + clen + 2);
		adress = malloc(len + clen + 2);
		if (tmp == NULL || adress == NULL)
		{
			perror("Memory allocation failed");
			return (NULL);
		}
		strcpy(adress, search);
		strcat(tmp, "/");
		strcat(tmp, cd);
		strcat(adress, tmp);
		if (stat(adress, &check) >= 0 &&
			       S_ISREG(check.st_mode) && (check.st_mode & S_IXUSR))
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
