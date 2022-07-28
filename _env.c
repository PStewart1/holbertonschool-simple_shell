#include "main.h"

/**
 *main - will implement env, which prints environment variables
 *@argc: argument count
 *@argv: pointer to argument vectors
 *@envp: pointer to array of environmental variables
 */
void _env()
{
	int i = 0;
	
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
