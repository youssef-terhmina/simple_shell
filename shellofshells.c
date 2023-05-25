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
	int check;
	ssize_t chars;
	char *buffer = NULL;
	char *command;
	char **argument;
	(void)argc;
	(void)argv;

	while (1)
	{
		chars = getline(&buffer, &buffsize, stdin);
		if (chars == -1)
		{
			exit(EXIT_SUCCESS);
		}
		buffer[chars - 1] = '\0';
		argument = simples(buffer, "\t \n");
		if (strcmp(argument[0], "exit") == 0)
			exit(EXIT_SUCCESS);
		pid = fork();
		if (pid == 0)
		{
			command = cmd(argument[0]);
			if (command != NULL)
				execve(command, argument, env), exit(1);
			else
				perror("Not found\n");
			exit(EXIT_FAILURE);
		}
		else
			wait(&check);
	}
	return (0);
}
