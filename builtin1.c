#include "head.h"

/**
 * excve - check & exec
 * @v: input
 * Return: 1 or 0
 */

int excve(value *v)
{
	builtin builtin[] = {
		{"exit", exit},
		{"env", env},
		{"setenv", setenv},
		{"unsetenv", unsetenv},
		{"cd", cd},
		{NULL, NULL},
	};
	int x;

	for (x = 0; builtin[x].cmd; x++)
	{
		if (_strcmp(v->av[0], builtin[x].cmd) == 0)
		{
			builtin[x].f(v);
			return (1);
		}
	}
	return (0);
}

/**
 * exit - exit shell
 * @v: input
 * Return: nothing
 */

void exit(value *v)
{
	if (v->av[1] && _isnumber(v->av[1]))
		v->exits = atoi(v->av[1]);
	free_array(v->av);
	free(v->cmd);
	if (v->flags)
		free_array(environ);
	exit(v->exits);
}

/**
 * env - current environment
 * @v: input
 * Return: nothing
 */

void env(value *v)
{
	int x =	0;

	(void)v;
	while (environ[x])
	{
		_printf(environ[x]);
		_printf("\n");
		x++;
	}
}

/**
 * setenv - Initialize new environment
 * @v: input
 * Return: nothing
 */

void setenv(value *v)
{
	(void)v;
	if (v->av[1] && v->av[2])
	{
		if (_setenv(v, v->av[1], v->av[2]) == -1)
		{
			perror("setenv");
		}
	}
}

/**
 * unsetenv - Remove environment
 * @v: input
 * Return: nothing
 */

void unsetenv(value *v)
{
	int x, y;
	int l;

	(void)v;
	if (!v->av[1] || !getenv(v->av[1]))
	{
		_perror(v->shell_name, "variable not found.");
		return;
	}
	l = strlen(v->av[1]);
	for (x = 0; environ[x]; x++)
		if (strncmp(environ[x], x->av[1], l) == 0 && environ[x][l] == '=')
			for (y = x; environ[y]; y++)
				environ[y] = environ[y + 1];
}

