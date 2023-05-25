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
		write(STDOUT_FILENO, "$ ", 2);
		chars = getline(&buffer, &buffsize, stdin);
		if (chars == -1)
		{
			write(STDOUT_FILENO, " \n", 2);
			exit(1);
		}
		buffer[chars - 1] = '\0';
		argument = simples(buffer, "\t \n");
		if (strcmp(argument[0], "exit") == 0)
			exit(0);
		pid = fork();
		if (pid == 0)
		{
			command = cmd(argument[0]);
			if (command != NULL)
				execve(command, argument, env), exit(1);
			else
				perror("Not found\n");
			exit(1);
		}
		else
			wait(&check);
	}
	return (0);
}
