#include "header.h"
/**
 * main - main simple shell function.
 * @argc: arguments count.
 * @argv: arguments vector.
 * Return: int.
 */
int main(int argc, char **argv)
{
	char *path_pointer = NULL, *line_ptr = NULL, *directory, *delim = ":";
	char **path_value_tokens = NULL, **cmdline_tokens = NULL;
	ssize_t num_chars;
	size_t size = 0;
	int status = 0;
	char *variable_name = "PATH";
	(void)argc;
	path_pointer = get_path_value(environ, variable_name);
	path_value_tokens = tokenizer(path_pointer, delim);
	write(STDIN_FILENO, "\033[1;35m$\033[0m ", 13);
	while ((num_chars = getline(&line_ptr, &size, stdin)) != -1)
	{
		if (line_ptr != NULL && line_ptr[0] == '\n')
		{
			free(line_ptr);
			line_ptr = NULL;
		}
		if (line_ptr != NULL)
			cmdline_tokens = tokenizer(line_ptr, " \n");
		if (_strcmp(cmdline_tokens[0], "exit") == 0)
		{
			free_cmdline(cmdline_tokens);
			exitfn(cmdline_tokens);
		}
		directory = concatenate(*cmdline_tokens, path_value_tokens);
		if (directory != NULL)
			cmdline_tokens[0] = _strdup(directory);
		child_process_forker(argv[0], cmdline_tokens, status, line_ptr);
		if (isatty(STDIN_FILENO))
			_printstr("$ ");
	}
	if (num_chars == -1)
	{
		if (isatty(STDIN_FILENO))
			_putchar('\n');
		exit(0);
	}
	free_cmdline(cmdline_tokens);
	return (0);
}
/**
 * concatenate - finds a command's path in the path env variable.
 * @cmdline_token: user input.
 * @path_value_tokens: array of path tokens
 * Return: full cmd path.
 */
char *concatenate(char *cmdline_token, char **path_value_tokens)
{
	struct stat sb;

	char *tmp;

	while (*path_value_tokens != NULL)
	{
		tmp = _strconcat(_strconcat(*path_value_tokens, "/"), cmdline_token);
		if (stat(tmp, &sb) == 0)
			return (tmp);
		path_value_tokens++;
	}
	return (0);
}
/**
 * child_process_forker - execute user input in shell.
 * @av: first element of avrgs.
 * @cmd_tokens: typed commands.
 * @status: number to change it's value with sys call wait.
 * @line: getline's buffer;
 * Return: void.
 */
void child_process_forker(char *av, char **cmd_tokens, int status, char *line)
{
	int pid = fork();
	/*extern char **environ;*/

	if (pid == -1)
		perror(av);
	if (pid == 0)
	{
		if (execve(cmd_tokens[0], cmd_tokens, environ) == -1)
		{
			perror(av);
			exit(EXIT_FAILURE);
		}
	}
	if (wait(&status) == -1)
	{
		free_cmdline(cmd_tokens);
		free(line);
		perror(av);
	}
}
