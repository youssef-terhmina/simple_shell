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

	if (name == NULL || *name == '\0' || environ == NULL)
		return (NULL);

	namel = _strlen(name);

	for (; environ[++x]; )
	{
		if (!_strncmp(environ[x], name, namel) && environ[x][namel] == '=')
			return (environ[x] + namel + 1);
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
	{
		free(pths);
		return (find);
	}
	_strcpy(pths, _getenv("PATH"));
	if (!pths)
	{
		free(pths);
		return (find);
	}
	tkn = strtok(pths, ":");
	for (; tkn; )
	{
		tokenl = _strlen(tkn) + _strlen(v->av[0]) + 2;
		pth = malloc(tokenl);
		if (!pth)
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
	char *catboth = malloc(newl);

	if ((new_ent) == NULL)
		return (NULL);

	strcpy(new_ent, name);
	strcat(catboth, "=");
	strcat(catboth, dt);
	strcat(new_ent, catboth);
	free(catboth);

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

	for (; environ[envl]; )
		envl++;

	new_ent = create_entry(name, dt);

	if (!new_ent)
		return (NULL);
	new_env = _getenv(name) ? malloc((envl + 1) * sizeof(char *))
								: malloc((envl + 2) * sizeof(char *));

	if (new_env == NULL)
		free(new_ent);
		return (NULL);
	x = 0;
	while (environ[x])
	{
		new_env[x] = malloc(strlen(environ[x]) + 1);
		if (new_env[x] == NULL)
			freea(new_env);
			free(new_ent);
			return (NULL);
		if (strncmp(environ[x], name, strlen(name)) == 0
		&& environ[x][strlen(name)] == '=')
		{
			strcpy(new_env[x], new_ent);
		}
		else
			strcpy(new_env[x], environ[x]);
		x++;
	}
	if (_getenv(name) == NULL)
		new_env[envl] = new_ent;
		new_env[envl + 1] = NULL;
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

	if (!name)
		return (-1);
	if (!dt)
		return (-1);

	new_env = _new_environ(name, dt);
	if (new_env == NULL)
		return (-1);

	environ = new_env;
	v->flags = 1;
	return (0);
}
