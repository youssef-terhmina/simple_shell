#include "head.h"

/**
 * gcd - changes dir
 * @v: input
 * Return: nothing
 */

void gcd(value *v)
{
	char *di = v->av[1];
	char cw[256], *ifst;

	if (getcwd(cw, sizeof(cw)) == NULL)
	{
		perror("getcw() error");
	}
	_setenv(v, "PWD", cw);

	if (di == NULL)
	{
		di = _getenv("HOME");
	}
	if (chdir(di) == -1)
		perror("cdnotfound");

	if (chdir(di) != -1 || di != NULL || getcwd(cw, sizeof(cw)) != NULL)
	{
		_setenv(v, "OLDPWD", _getenv("PWD"));
		ifst = getcwd(cw, sizeof(cw));
		if (ifst == NULL)
			perror("getcw() error");
		_setenv(v, "PWD", cw);
	}
}
