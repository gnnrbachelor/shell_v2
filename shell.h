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
#define ENV_ERROR 102

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
	char *error;
	int pipe_fd[2];
	int p_stat;
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
int init_arg_node(arg_node *args, const int ac, char **av);
void prompt(arg_node *args, char *p);
void shell(arg_node *args);
int builtins(arg_node *args);
int changedir(arg_node *args);
ssize_t count_cmds(char *line);
int exit_this(arg_node *args);
int print_env(arg_node *args);
void free_it_all(arg_node *args, char mode);
list *arr_to_link(void);
int parse_cd_tok(arg_node *args);
int set_env_var(list **env, char *name, char *value);
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
int _clear(arg_node *args);
void print_syn_err(int *stat, char *err, size_t *i, int j);
int handle_redirect(arg_node *args, char *line, int *file_ds);
char quote_check(char * line, size_t i, char *q);
int handle_syn_err(char *line);
int step_parse(char *s, size_t *i);
int comment_check(char *line, size_t i);
int is_digit(char n);
int redirect_stdout(arg_node *args, char *line, size_t i, int *file_ds);
int handle_redirect_errors(arg_node *args, int *file_ds, int flags, char *file, int is_valid, int which_redirect);
int redirect_stdin(arg_node *args, char *line, size_t i, int *file_ds);
void re_redirect(arg_node *args, int *file_ds);
char *heredoc(arg_node *args, char *line, size_t i);
int handle_pipe(arg_node *args, char *line);
char **link_to_arr(list *head);
size_t list_size(const list *head);
void handle_pipe_chain(arg_node *args, char *line, int *file_d, char *op, int p_stat);
void pipe_wr(arg_node *args, char *line, int *file_d, char *op);
int check_op(arg_node *args, char op);





/* Strings */

size_t _strlen(char *str);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strncpy(char *dest, char *src, int n);
char *_memset(char *s, char b, unsigned int n);


#endif
