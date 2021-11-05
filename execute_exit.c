#include "header.h"

/**
 * exitfn - exit function
 * @cmdline_tokens: command line arguments
 * Return: void
 */
void exitfn(char **cmdline_tokens)
{
	int k;

	if (cmdline_tokens[1] == NULL)
		exit(0);
	else
	{
		k = _atoi(cmdline_tokens[1]);
		if (k < 0)
			k = 2;
		exit(k);
	}
}
