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
extern char **environ;
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
void gexit(value *v);
void genv(value *v);
void gsetenv(value *v);
void gunsetenv(value *v);

/* builtin2.c */

void gcd(value *v);

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

char *_strdup(const char *string);
int _isnumber(const char *stat);
int _isdigit(int c);

/* help1.c */

void _printf(const char *st);
void freea(char **a);
void simplif(value *v, const char *d);
void init(value *v, const char *name);
void getcmd(value *v);

/* help2.c */

void _perror(const char *str, const char *string);
void _trim(char *str);
void *_realloc(void *ptr, unsigned int nsize);

#endif
