#ifndef _MAIN_H_
#define _MAIN_H_
#define EXITCMD "exit\n"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>

extern int errno;
extern char **environ;

char *_getenv(const char *name);
char *_path(char *str);

#endif /* _MAIN_H_ */
