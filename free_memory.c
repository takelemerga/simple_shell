#include "header.h"

/**
* free_cmdline - free cmds
 * @cmdline_tokens: array of user commands.
 * Return: nothing
 */
void free_cmdline(char **cmdline_tokens)
{
	int k = 0;

	while (cmdline_tokens[k])
	{
		free(cmdline_tokens[k]);
		k++;
	}
	free(cmdline_tokens);
}
