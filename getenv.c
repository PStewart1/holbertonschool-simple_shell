#include "main.h"

/**
 * _getenv - get an environment variable
 * @name: name of variable
 * Return: pointer to value of variable
 */


char *_getenv(const char *name)
{
	int i = 0;
	char *var;

	while (environ[i])
	{
		if (strstr(environ[i], name))
		{
			var = strchr(environ[i], '=');
			return (++var);
		}
		i++;
	}
	return (NULL);
}
