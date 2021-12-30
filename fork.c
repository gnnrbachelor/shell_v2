#include "shell.h"

/**
 * fork - Forks for execve
 * @args: Args
 * @exec: Executable
 * Return: Void
 *
 */

void _fork(arg_node *args, char *exec)
{
	pid_t pid = 0;
	int wstatus;

	pid = fork();
	if (pid < 0)
		error(args);
	else if (pid == 0)
	{
		if (execve(exec, args->token_array, NULL))
		{
			error(args);
			exit(errno);
		}
	}
	else
	{
		waitpid(-1, &wstatus, 0);
		if (WIFEXITED(wstatus))
			args->exit_status = WEXITSTATUS(wstatus);
	}
}

/**
 * make_proc - Creates process
 * @args: Args
 * Return: Void
 */

void make_proc(arg_node *args)
{
	char *exec = NULL;

	exec = !_strncmp(args->token_array[0], "./", 2) || **args->token_array == '/' ? args->token_array[0] : get_path(args);
	if (!exec || access(exec, F_OK))
	{
		error(args);
	}
	else if (access(exec, X_OK | R_OK))
	{
		error(args);
	}
	else
		_fork(args, exec);
}

/**
 * get_path - Gets path
 * @args: Args
 * Return: Void
 */

char *get_path(arg_node *args)
{
	char *path = _getenv("PATH=", args);
	char *token = NULL;
	char *delim = NULL;
	static char buffer[PATH_MAX];

	if (!path)
		return (NULL);
	for (token = tokenize_path(path); token; token = tokenize_path(NULL))
	{
		delim = *token ? "/" : "./";
		sprintf(buffer, "%s%s%s", token, delim, args->token_array[0]);
		free(token);
		if (!access(buffer, F_OK))
			return (buffer);
	}
	return (NULL);
}

/*
 * tokenize_path - Tokenizes path
 * @args: Args
 * Return: pointer to new array
 */

char *tokenize_path(char *str)
{
	static char *path;
	char *dir = NULL;
	static size_t cur;
	size_t new;

	if (str)
	{
		cur = 0;
		path = str;
	}

	if (!path || !*(path + cur))
		return (NULL);
	for (new = cur; *(path + new) && *(path + new) != ':'; new++)
		;
	dir = malloc(sizeof(char) * (new - cur + 1));
	_strncpy(dir, path + cur, new - cur);
	dir[new - cur] = '\0';
	cur = *(path + new) ? ++new : new;
	return (dir);
}

