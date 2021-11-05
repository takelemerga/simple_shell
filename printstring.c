#include "header.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printstr - function that displays string to stdou.
 * @str: string to display.
 * Return: void.
 */
void _printstr(char *str)
{
	int k = 0;

	if (str == NULL)
		return;

	while (str[k])
	{
		_putchar(str[k]);
		k++;
	}
}
