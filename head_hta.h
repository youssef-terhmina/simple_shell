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
#include <signal.h>
#define BUFSIZE 1024
/**
 * struct value - enters value
 * @av: array
 * @cmd: command
 * @name: name of the shell
 * @exits: s for status
 * @flags: s for setenv
 */
typedef struct value
{
	int exits;
	int flags;
	char **av;
	const char *name;
	char *cmd;
} value;
/**
 * struct coma - holding commands
 * @cmd: command
 * @f: function pointer
 */
typedef struct coma
{
	void (*f)(value *v);
	const char *cmd;
} coma;
int excve(value *v);
void _printf(const char *s);
void exit(value *v);
void env(value *v);
void setenv(value *v);
void unsentenv(value *v);
void cd(value *v);
extern char **environ;
void freea(char **a);
void simplif(value *v, const char *d);
void init(value *v, const char *name);
void getcmd(value *v);
void _perror(const char *str, const char *string);
void _trim(char *str);
void *_realloc(void *ptr, unsigned int nsize);
void start(value *v);
void hansig(int sig);
void _exec(value *v);
char *_getenv(char *name);
int _which(value *v);
int _setenv(value *v, char *name, char *data);
unsigned int _strlen(char *name);
char *_strcpy(char *de, const char *sr);
char *_strcat(char *de, const char *sr);
int _strncmp(const char *s, const char *ss, int x);
int _strcmp(const char *s, const char *ss);
char *_strdup(const char *string);
int _isdigit(int c);
int _isnumber(const char *stat);
#endif
