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
 * @name: The name of shell program
 * @exits: last exit status of last cmd executed
 * @flags: 1 if user did exec setenv
 */

typedef struct value
{
	char **av;
	char *cmd;
	const char *name;
	int exits;
	int flags;
} value;

/**
 * struct builtin - holds main data.
 * @cmd: built in cmd
 * @f: fnct of builtin cmd
 */

typedef struct builtin
{
	const char *cmd;
	void (*f)(value *v);
} builtin;

/* getline.c */

#define BUFSIZE 1024

ssize_t _getline(char **linep, size_t *n, FILE *strm);
int _getlineh(char **linep, size_t *n);

/* builtin1.c */

int excve(value *v);
void exit(value *v);
void env(value *v);
void setenv(value *v);
void unsetenv(value *v);

/* builtin2.c */

void cd(value *v);

/* env.c */

char *_getenv(char *name);
int _which(value *v);
char *create_entry(char *name, char *dt);
char **_new_environ(char *name, char *dt);
int _setenv(value *v, char *name, char *dt);

/* prexec.c */

void start(value *v);
void hansig(int sig);
void _exec(value *v);

/* str1.c */

unsigned int _strlen(char *str);
int _strcmp(const char *s, const char *ss);
int _strncmp(const char *s, const char *ss, int n);
char *_strcpy(char *de, const char *sr);
char *_strcat(char *de, const char *sr);

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
