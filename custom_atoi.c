#include "header.h"

/**
 * _atoi - convert a string to an integer.
 * @s: string's pointer
 * Return: type integer.
 */
int _atoi(char *s)
{
	int i = 0;
	int len = 0;
	int num = 0;
	int multi = 1;
	int getout = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	while (i < len && getout == 0)
	{
		if (s[i] == 45)
			multi *= -1;
		if (s[i] >= 48 && s[i] <= 57)
		{
			num = num * 10 + multi * (s[i] - 48);
			if (s[i + 1] >= 48 && s[i + 1] <= 57)
				getout = 0;
			else
				getout = 1;
		}
		i++;
	}
	return (num);
}
