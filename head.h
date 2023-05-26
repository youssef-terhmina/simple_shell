#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#define PROMPT "#csisfun$ "
int envhan(const char *store, const char *data, int ndata);
extern char **environ;
char *cmd(char *cd);
char *getit(const char *var);
char **simples(char *buff, char *d);
int main(int argc, char **argv);

/**
 * struct data - holds main data.
 * @av: Array of tokens to pass for execve
 * @cmd: The user input, the command line
 * @shell_name: The name of shell program
 * @last_exit_status: last exit status of last cmd executed
 * @flag_setenv: 1 if user did exec setenv
 */

typedef struct data
{
	char **av;
	char *cmd;
	const char *shell_name;
	int last_exit_status;
	int flag_setenv;
} data;

/**
 * struct builtin - holds main data.
 * @cmd: built in cmd
 * @f: fnct of builtin cmd
 */

typedef struct builtin
{
	const char *cmd;
	void (*f)(data *d);
} builtin;

/* getline.c */

#define READ_BUF_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _getline_helper(char **lineptr, size_t *n);

/* builtin1.c */

int exec_builtin(data *d);
void builtin_exit(data *d);
void builtin_env(data *d);
void builtin_setenv(data *d);
void builtin_unsetenv(data *d);

/* builtin2.c */

void builtin_cd(data *d);

/* env.c */

char *_getenv(char *name);
int _which(data *d);
int _setenv(data *d, char *name, char *value);

/* prexec.c */

void start_process(data *d);
void handler_sigint(int sig);
void _exec(data *d);

/* str1.c */

unsigned int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);

/* str2.c */

char *_strdup(const char *str);
int _isnumber(const char *status);
int _isdigit(int c);

/* help1.c */

void _printf(const char *str);
void free_array(char **array);
void split(data *d, const char *delim);
void init_data(data *d, const char *shell_name);
void read_cmd(data *d);

/* help2.c */

void _perror(const char *str1, const char *str2);
void _trim(char *str);
void *_realloc(void *ptr, unsigned int new_size);

#endif
