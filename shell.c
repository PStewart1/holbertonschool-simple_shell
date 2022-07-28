#include "main.h"

/**
 * main - Simple Shell
 *
 * Return: Always 0
 */

int main(void)
{
	char *argv[3], *saveptr, *line = NULL;
	size_t len = 0;
	pid_t pid;
	int i, mode = 1, linestatus;

	while (mode)
	{
		printf("#cisfun$ ");
		linestatus = getline(&line, &len, stdin);
		if (linestatus < 0)
			return (0);
		for (i = 0; ; i++, line = NULL)
		{
			argv[i] = strtok_r(line, " \n", &saveptr);
			if (argv[i] == NULL)
				break;
		}
		argv[0] = linecheck(argv[0]);
		if (argv[0] == NULL)
		{
			free(line);
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			execve(argv[0], argv, NULL);
			fprintf(stderr, "%s\n", strerror(errno));
			return (-1);
		}
		else if (pid < 0)
			perror("fork failed");
		else
			wait(NULL);
		mode = isatty(STDIN_FILENO);
		free(argv[0]);
		free(line);
	}
	return (0);
}
