#include "header.h"
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 * @str: String to be duplicated.
 * Return: pointer to newly allocated space in memory
 * contianing duplicate string.
 */

char *_strdup(char *str)
{
	char *dup;
	int i;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (str[i])
		i++;

	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);

	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}

	dup[i] = '\0';

	return (dup);
}

/**
 * _strcmp - Compares two strings.
 *
 * @s1: First string.
 * @s2: Second string.
* Return: 0 if strings are equal, non-zero, otherwise.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}

	return (s1[i] - s2[i]);
}
/**
 * _strconcat - concatenates s2 to s1.
 * @s1: string 1.
 * @s2: string 2.
 * Return: pointer to character of the new concatenated string.
 */
char *_strconcat(char *s1, char *s2)
{
	int len1 = 0, len2 = 0, lens_sum, i;
	char *str;

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	lens_sum = len1 + len2;
	str = malloc(sizeof(char) * (lens_sum + 1));
	/* str = malloc(sizeof(char) * 1000); */

	if (str == NULL)
		return (NULL);

	for (i = 0; i < lens_sum; i++)
	{
		if (i < len1)
			str[i] = s1[i];
		else
			str[i] = s2[i - len1];
	}
	str[lens_sum] = '\0';
	return (str);
}
