#include "main.h"

/**
 *linecheck - checks the command line
 *@argv: argument vector
 *Return: argv
 */
char *linecheck(char *argv)
{

	if (strcmp(argv, "exit") == 0)
		exit(0);
	if (strcmp(argv, "env") == 0)
	{
		_env();
		return (NULL);
	}
	if (strchr(argv, '/') == NULL)
	{
		argv = _path(argv);
		if (argv == NULL)
		{
			fprintf(stderr, "%s\n", strerror(errno));
			return (NULL);
		}
	}
	return (argv);
}
