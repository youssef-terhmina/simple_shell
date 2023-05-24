#include "head.h"
/**
 * main - the main function to create the shell and run it
 * @argc: arg count
 * @argv: arguments to handle
 * @env: environ
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	size_t buffsize = 0;
	pid_t pid;
	int check, numb, chars;
	char *buffer = NULL;
	char *command;
	(void)argc;

	while (1)
	{
		write(1, "# ", 2);
		chars = getline(&buffer, &buffsize, stdin);
		numb = chars;
		if (numb == -1)
		{
			write(1, " \n", 2);
			exit(1);
		}
		argv = simples(buffer, "\t \n");
	}
	while (1)
	{
		if (strcmp(argv[0], "exit") == 0)
			exit(0);

		pid = fork();
		if (pid)
		{
			command = cmd(argv[0]);
			if (command != NULL)
				execve(command, argv, env);
			else
				perror("Not found\n");
			exit(1);
		}
		else
			wait(&check);
	}
	free(buffer);
	return (0);
}
