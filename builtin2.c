#include "head.h"

/**
 * gcd - changes dir
 * @v: input
 * Return: nothing
 */

void gcd(value *v)
{
	char *di = v->av[1];
	char cw[256];

	if (getcwd(cw, sizeof(cw)) == NULL)
		perror("getcwd() error");
	_setenv(v, "PWD", cw);
	if (!di)
		di = _getenv("HOME");
	if (chdir(di) == -1)
		perror("cd");
	else
	{
		_setenv(v, "OLDPWD", _getenv("PWD"));
		if (getcwd(cw, sizeof(cw)) == NULL)
			perror("getcwd() error");
		_setenv(v, "PWD", cw);
	}
}
