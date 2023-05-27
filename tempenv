#include "head.h"

/**
 * _getenv - value of environment
 * @name: str input
 * Return: value of environment
 */

char *_getenv(char *name)
{
	int x = -1;
	size_t namel;

	if (name == NULL || *name == '\0')
		return (NULL);
	if (environ == NULL)
		return (NULL);

	namel = _strlen(name);

	while (environ[++x])
	{
		if (!_strncmp(environ[x], name, namel) && environ[x][namel] == '=')
		{
			return (environ[x] + namel + 1);
		}
	}
	return (NULL);
}

/**
 * _which - locates executable file
 * @v: input
 * Return: nothing
 */

int _which(value *v)
{
	char *tkn, *pth,
		*pths = malloc(_strlen(_getenv("PATH") ? _getenv("PATH") : "") + 1);
	size_t tokenl;
	int find = -1;

	if (!_getenv("PATH"))
		goto step_out;
	_strcpy(pths, _getenv("PATH"));
	if (pths == NULL)
		goto step_out;
	tkn = strtok(pths, ":");
	while (tkn)
	{
		tokenl = _strlen(tkn) + _strlen(v->av[0]) + 2;
		pth = malloc(tokenl);
		if (pth == NULL)
			return (find);
		_strcpy(pth, tkn);
		_strcat(pth, "/");
		_strcat(pth, v->av[0]);
		if (access(pth, F_OK) == 0)
		{
			free(v->av[0]);
			v->av[0] = _strdup(pth);
			free(pth);
			find = 0;
			break;
		}
		free(pth);
		tkn = strtok(NULL, ":");
	}
step_out:
	free(pths);
	return (find);
}

/**
 * create_entry - Initializes new environment
 * @name: variable name
 * @dt: variable value
 * Return: nothing
 */

char *create_entry(char *name, char *dt)
{
	size_t newl = strlen(name) + strlen(dt) + 2;
	char *new_ent = malloc(newl);

	if (new_ent == NULL)
		return (NULL);

	strcpy(new_ent, name);
	strcat(new_ent, "=");
	strcat(new_ent, dt);

	return (new_ent);
}
/**
 * _new_environ - Initializes new environment
 * @name: variable name
 * @dt: variable value
 * Return: nothing
 */

char **_new_environ(char *name, char *dt)
{
	int envl = 0, x = 0;
	char *new_ent;
	char **new_env;

	while (environ[envl])
		envl++;
	new_ent = create_entry(name, dt);
	if (new_ent == NULL)
		return (NULL);
	new_env = _getenv(name) ? malloc((envl + 1) * sizeof(char *))
								: malloc((envl + 2) * sizeof(char *));

	if (!new_env)
	{
		free(new_ent);
		return (NULL);
	}
	for (x = 0; environ[x]; x++)
	{
		new_env[x] = malloc(strlen(environ[x]) + 1);
		if (!new_env[x])
		{
			freea(new_env);
			free(new_ent);
			return (NULL);
		}
		if (strncmp(environ[x], name, strlen(name)) == 0
		&& environ[x][strlen(name)] == '=')
			strcpy(new_env[x], new_ent);
		else
			strcpy(new_env[x], environ[x]);
	}
	if (!_getenv(name))
	{
		new_env[envl] = new_ent;
		new_env[envl + 1] = NULL;
	}
	else
		new_env[envl] = NULL;
	return (new_env);
}

/**
 * _setenv - Initializes new environment
 * @v: flag
 * @name: variable name
 * @dt: variable value
 * Return: nothing
 */

int _setenv(value *v, char *name, char *dt)
{
	char **new_env;

	if (!name || !dt)
		return (-1);

	new_env = _new_environ(name, dt);
	if (!new_env)
		return (-1);
	environ = new_env;
	v->flags = 1;

	return (0);
}
