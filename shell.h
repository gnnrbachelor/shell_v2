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


#define EXIT_ERROR 100
#define CD_ERROR 101

extern char **environ;

/**
 * struct list - Linked list
 * @str: String
 * @next: Next node
 *
 * Description: Linked list
 */

typedef struct list
{
	char *str;
	struct list *next;
} list;


/**
 * struct arg_node - Arg node
 * @ac: Int
 * @av: av
 * @exitchr: exit n
 * @token_array: Token array
 * @env: envir
 * @exit_status: exit status
 */

typedef struct arg_node
{
	int ac;
	char **av;
	char *exitchr;
	char **token_array;
	list *env;
	int exit_status;
	size_t cmd_count;
} arg_node;

/**
 * struct built_ins - Builtins
 * @bi: name
 * @f: function pointer
 */

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
ssize_t count_cmds(char *line);
int exit_this(arg_node *args);
int print_env(arg_node *args);
void free_it_all(arg_node *args, char mode);
list *arr_to_link(void);
int parse_cd_tok(arg_node *args);
void set_env_var(list **env, char *name, char *value);
char *_getenv(char *command, arg_node *args);
int _unsetenv(arg_node *args);
int _setenv(arg_node *args);
size_t find_env_var(char *s, list *s2, arg_node *args);
void _fork(arg_node *args, char *exec);
void make_proc(arg_node *args);
char *get_path(arg_node *args);
char *tokenize_path(char *str);
void error(arg_node *args);
void parse_op(arg_node *args, char *line);
void execute_shell(arg_node *args, char *line);





/* Strings */

size_t _strlen(char *str);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strncpy(char *dest, char *src, int n);

#endif
