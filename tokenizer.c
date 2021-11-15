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
	int i;

	int  count;

	char **tokens = NULL;
	char *portion = NULL;
	char *s = NULL;

	if (str == NULL || delim == NULL)
	return (NULL);
	i = 0;
	count = 0;

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
