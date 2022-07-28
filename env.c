#include "main.h"

/**
 *_env - will implement env, which prints environment variables
 *
 *Return: void
 */
void _env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
