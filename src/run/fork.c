#include "../headers/shell.h"

/**
 * _fork - Forks for execve
 * @args: Args
 * @exec: Executable
 * Return: Void
 *
 */

void _fork(arg_node *args, char *exec)
{
	pid_t pid = 0;
	int wstatus;
	char **env_array = NULL;

	pid = fork();
	if (pid < 0)
		error(args);
	else if (pid == 0)
	{
		env_array = link_to_arr(args->env);
		if (args->pipe_fd[0] != 0)
		{
			close(args->pipe_fd[0]);
			close(args->pipe_fd[1]);
		}
		if (execve(exec, args->token_array, env_array))
		{
			free(env_array);
			error(args);
			exit(errno);
		}
	}
	else
	{
		if (args->p_stat == 1)
			close(args->pipe_fd[1]);
		else if (args->p_stat == 0)
			close(args->pipe_fd[0]);
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

	exec = ((*args->token_array)[0] == '.' &&
		((*args->token_array)[1] == '.' || (*args->token_array)[1] == '/')) ||
		**args->token_array == '/'
		? args->token_array[0] : get_path(args);

	if (!exec || access(exec, F_OK))
	{
		errno = ENOENT;
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


