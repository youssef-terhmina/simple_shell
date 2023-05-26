#include "head.h"

/**
 * frees- free the memory allocated for the arguments
 * @argv: array of arguments
 */
void frees(char **argv)
{
	int i;

	if (argv == NULL)
		return;
	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}
