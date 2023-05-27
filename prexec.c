#include "head.h"

/**
 * start - starts new process
 * @v: input
 * Return: nothing
 */

void start(value *v)
{
	pid_t child_p = fork();
	int stat = 0;

	if (child_p == -1)
		goto free;
	if (child_p == 0 && execve(v->av[0], v->av, NULL) == -1)
		goto free;
	else if (wait(&stat) == -1)
		goto free;
	if (WIFEXITED(stat))
		v->exits = WEXITSTATUS(stat);
	return;
free:
	perror(v->name);
	free_array(v->av);
	free(v->cmd);
	exit(EXIT_FAILURE);
}

/**
 * hansig - Signal handler fnct
 * @sig: input
 * Return: nothing
 */

void hansig(int sig)
{
	(void)sig;
	exit(EXIT_FAILURE);
}

/**
 * _exec - exectutes cmd
 * @v: data struct input
 * Return: nothing
 */

void _exec(value *v)
{
	const char prompt[] = PROMPT;

	signal(SIGINT, hansig);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf(prompt);

		read_cmd(v);
		if (_strlen(v->cmd) != 0)
		{
			split(v, " ");
			if (!excve(v))
			{
				_which(v);
				if (access(v->av[0], F_OK) == -1)
				{
					perror(v->name);
				}
				else
				{
					start(v);
				}
			}
			free_array(v->av);
		}
		free(v->cmd);
	}
}
