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

	address = malloc(sizeof(path));
	for (j = 0; j < 6; j++, path = NULL)
	{
		token = strtok_r(path, ":", &saveptr2);
		if (token == NULL)
			break;
		strcpy(address, token);
		strcat(address, "/");
		strcat(address, str);
		if (access(address, F_OK) == 0)
		{
			free(path);
			return (address);
		}
	}
	free(address);
	free(path);
	return (NULL);
}

