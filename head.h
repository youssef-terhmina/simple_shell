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
#include <limits.h>
int envhan(const char *store, const char *data);
extern char **environ;
char *cmd(char *cd);
char *getit(const char *var);
char **simples(char *buff, char *d);
int main(int argc, char **argv, char **env);
#endif
