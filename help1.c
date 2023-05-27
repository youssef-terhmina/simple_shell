#include "head.h"

/**
 * _printf - print a string to stander out put
 * @s: string input
 * Return: void
 */
void _printf(const char *s)
{
	if (!s)
		return;
	while (*s)
	{
		write(STDOUT_FILENO, s, 1);
		s++;
	}
}

/**
 * free_array - free an array of pointers
 * @a: array of pointers
 * Return: void
 */
void freea(char **a)
{
	int x;

	if (!a)
		return;

	for (x = 0; a[x]; x++)
	{
		free(a[x]);
		a[x] = NULL;
	}

	free(a);
}

/**
 * simplif - split a given string by a delimiter
 * @v: data struct input
 * @d: string input
 * Return: void
 */
void simplif(value *v, const char *d)
{
	char *tkn;
	int ntkn = 0;

	v->av = malloc(2 * sizeof(char *));
	if (v->av == NULL)
	{
		free(v->cmd);
		perror(v->name);
		exit(EXIT_FAILURE);
	}
	v->av[0] = NULL;
	v->av[1] = NULL;

	tkn = strtok(v->cmd, d);
	while (tkn)
	{
		v->av = realloc(v->av, (ntkn + 2) * sizeof(char *));
		if (v->av == NULL)
			goto free;
		v->av[ntkn] = _strdup(tkn);
		if (v->av[ntkn] == NULL)
			goto free;
		ntkn++;
		tkn = strtok(NULL, d);
	}
	v->av[ntkn] = NULL;
	return;
free:
	free_array(v->av);
	free(v->cmd);
	perror(v->name);
	exit(EXIT_FAILURE);
}

/**
 * init - init data
 * @v: data struct input
 * @name: string input
 * Return: void
 */

void init(value *v, const char *name)
{
	v->cmd = NULL;
	v->av = NULL;
	v->name = name;
	v->exits = EXIT_SUCCESS;
	v->flags = 0;
}

/**
 * getcmd - get the commend from the prompt and structure it into data struct
 * @v: data struct input
 * Return: void
 */
void getcmd(value *v)
{
	size_t n = 0;
	ssize_t get;
	int i = 0;

	get = _getline(&v->cmd, &n, stdin);

	if (get == -1)
	{
		free(v->cmd);
		exit(EXIT_SUCCESS);
	}

	v->cmd[get - 1] = '\0';
	_trim(v->cmd);
	for (i = 0; v->cmd[i] != '\0'; i++)
	{
		if (v->cmd[0] == '#' || (v->cmd[i] == '#' && v->cmd[i - 1] == ' '))
		{
			v->cmd[i] = '\0';
			break;
		}
	}
	_trim(v->cmd);
}
