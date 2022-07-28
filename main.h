#ifndef _MAIN_H_
#define _MAIN_H_

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

char *linecheck(char *argv);
char *_getenv(const char *name);
char *_path(char *str);
void _env(void);

#endif /* _MAIN_H_ */
