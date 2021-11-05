#include "header.h"

/**
 *get_path_value - get an environment variable value of the given name
 * @environ: array of pointers pointing to env variable values
 * @variable_name: name of env variable you're looking for.
 * Return: the env variable value of being searched
 */
char *get_path_value(char **environ, char *variable_name)
{
	char **curr = environ;
	char *temp, *token = NULL;

	/**
	* if (*curr == NULL || variable_name[0] == '\0');
	* return (NULL);
	*/
	while (*curr != NULL)
	{
		temp = _strdup(*curr);
		token = strtok(temp, "=");
		if (_strcmp(token, variable_name) == 0)
			return (strtok(NULL, "="));
		curr++;
	}
	return (token);
}
