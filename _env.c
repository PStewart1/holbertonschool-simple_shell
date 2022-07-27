#include "main.h"

/**
 *main - will implement env, which prints environment variables
 *@argc: argument count
 *@argv: pointer to argument vectors
 *@envp: pointer to array of environmental variables
 */
int main(int argc, char *argv[], char *envp[])
{
	int i = 0;
	
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	getchar();
	return(0);
}
