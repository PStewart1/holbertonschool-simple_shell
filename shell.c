#include "main.h"

/**
 * main - Simple Shell
 *
 * Return: Always 0.
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	pid_t pid;
	char *argv[3];
	char *saveptr;
	int i, mode = 1;

	while (mode)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("#cisfun$ ");
			getline(&line, &len, stdin);
			for (i = 0; ; i++, line = NULL)
			{
				argv[i] = strtok_r(line, " \n", &saveptr);
				if (argv[i] == NULL)
					break;
			}
			execve(argv[0], argv, NULL);
			fprintf(stderr, "./shell: %s\n", strerror(errno));
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
