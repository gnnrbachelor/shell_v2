#ifndef SHELL_H
#define SHELL_H

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <pwd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

extern char **environ;

typedef struct list
{
	char *str;
	struct list *next;
} list;

typedef struct arg_node {
	int ac;
	char **av;
	char exitchr;
	char **token_array;
	list *head;
	int exit_status;

} arg_node;


typedef struct built_ins
{
	char *bi;
	int (*f)(arg_node *args);
} built_ins;


ssize_t wordcount(char *line);
char **tokenize(char *line);
void init_arg_node(arg_node *args, const int ac, char **av);
void prompt(arg_node *args);
void shell(arg_node *args);
int builtins(arg_node *args);
int changedir(arg_node *args);
int penv(arg_node *args);
int callexit(arg_node *args);
ssize_t count_cmds(char *line);


/* Strings */

size_t _strlen(char *str);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif
