#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

extern char **environ;

char **tokenizer(char *str, char *delim);
char *get_path_value(char **environ, char *variable_name);
void free_cmdline(char **cmdline_tokens);
void exitfn(char **cmdline_tokens);
void child_process_forker(char *av, char **cmdline_tokens, int status, char *line_ptr);
char *concatenate(char *cmdline_token, char **path_value_tokens);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strconcat(char *s1, char *s2);
int _atoi(char *str);
void _printstr(char *str);
int _putchar(char c);
#endif
