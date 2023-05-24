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
<<<<<<< HEAD
#include <fcntl.h>
#include <errno.h>

/* exit.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

=======
#include <limits.h>
int envhan(const char *store, const char *data);
extern char **environ;
>>>>>>> fd2bfb8c7ed13ef3c8f34f6ea017b49e711da9e9
#endif
