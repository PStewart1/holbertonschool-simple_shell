#include "main.h"

/**
 * _path - searches PATH for built-in and returns address if found
 * @str: name of built-in
 * Return: pointer to path of builtin, or null if not found
 */

char *_path(char *str)
{
	int j;
	char *token, *address, *saveptr2, *path = strdup(_getenv("PATH"));
	struct stat st;

	for (j = 0; ; j++, path = NULL)
	{
		token = strtok_r(path, ":", &saveptr2);
		if (token == NULL)
			break;
		address = strdup(token);
		strcat(address, "/");
		strcat(address, str);
		if (stat(address, &st) == 0)
		{
			free(path);
			return (address);
		}
		else
			free(address);
	}
	free(path);
	return (NULL);
}

/**
 * main - Simple Shell
 *
 * Return: Always 0.
 */

int main(void)
{
	char *argv[2], *saveptr, *line = NULL;
	size_t len = 0;
	pid_t pid;
	int i, mode = 1, getit;

	while (mode)
	{
		printf("#cisfun$ ");
		getit = getline(&line, &len, stdin);
		if (getit < 0)
		{
			putchar('\n');
			return (-1);
		}
		for (i = 0; ; i++, line = NULL)
		{	
			argv[i] = strtok_r(line, " \n", &saveptr);
			if (argv[i] == NULL)
				break;
		}
		if (strcmp(argv[0], "exit") == 0)
			return (-1);
		if (strcmp(argv[0], "env") == 0)
		{
			_env();
			continue;
		}
		if (strchr(argv[0], '/') == NULL)
		{
			argv[0] = _path(argv[0]);
			if (argv[0] == NULL)
			{	
				fprintf(stderr, "%s\n", strerror(errno));
				continue;
			}
		}		
		pid = fork();
		if (pid == 0)
		{	
			execve(argv[0], argv, NULL);
			fprintf(stderr, "%s\n", strerror(errno));
			return (-1);
		}	
		else if (pid < 0)
			perror("lsh");
		else
			wait(NULL);
		mode = isatty(STDIN_FILENO);
	}
	free(line);
	return (0);
}
