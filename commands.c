#include "head.h"
/**
 * cmd - function to run commands
 * @cd: command used as example, the function should work on all bin commands
 * Return: command or NULL
 */
char *cmd(char *cd)
{
	char *path = getit("PATH");
	char *tmp = NULL, *search = NULL, *adress = NULL;
	struct stat check;
	int checker;
	int len, clen;

	if (search == NULL)
		return (NULL);
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
		checker = stat(adress, &check);
		if (checker == 0)
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
