#include "header.h"

/**
 * tokenizer - parse a string into tokens using delimiters
 *
 * @str: string to be parsed
 * @delim: delimiter
 * Return: array of pointers to tokens
 */
char **tokenizer(char *str,  char *delim)
{
	if (str == NULL || delim == NULL)
	return (NULL);
	int i = 0;

	int count = 0;

	char **tokens = NULL;
	char *portion = NULL;
	char *s = NULL;

	s = _strdup(str);
	while (*str != '\0')
	{
		if (*str == *delim)
		{
			count++;
		}
		str++;
	}
	tokens = malloc(sizeof(char *) * (count + 2));
	portion = strtok(s, delim);
	if (portion == NULL || portion[0] == '\0')
		return (NULL);
	while (portion != NULL)
	{
		tokens[i] = _strdup(portion);
		portion = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
