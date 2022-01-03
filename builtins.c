#include "shell.h"

/**
 * builtins - Selects builtin
 * @args: args
 * Return: 0
 */

int builtins(arg_node *args)
{
	size_t i;
	size_t stat;

	built_ins func_arr[] = {
		{"cd", changedir},
		{"env", print_env},
		{"exit", exit_this},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"clear", _clear},
		{NULL, NULL}
	};

	for (i = 0; func_arr[i].bi; ++i)
		if (!_strcmp(*args->token_array, func_arr[i].bi))
		{
			stat = func_arr[i].f(args);
			if (!stat)
				args->exit_status = 0;
			if (args->p_stat == 1)
				close(args->pipe_fd[1]);
			else if (args->p_stat == 0)
				close(args->pipe_fd[0]);
			return (0);
		}
	return (1);
}

/**
 * clear_screen - Clear Screen
 * @arg_node: Args
 * Return: Void
 */

int _clear(arg_node *args)
{
	char *clr = "\033[2J";
	char *move = "\033[1;1H";

	(void) args;
	printf("%s%s", move, clr);
	return (0);
}


/**
 * changedir - cd command
 * @args: args
 * Return: 0;
 */

int changedir(arg_node *args)
{
	char *cur = NULL;
	char *next = NULL;

	cur = getcwd(cur, 0);
	if (parse_cd_tok(args) == -1)
	{
		errno = CD_ERROR;
		error(args);
		free(cur);
		return (1);
	}
	next = getcwd(next, 0);
	set_env_var(&(args->env), "OLDPWD", cur);
	set_env_var(&(args->env), "PWD", next);
	free(next);
	free(cur);
	return (0);
}


/**
 * print_env - Prints environment
 * @args: Args
 * Return: 0 if success
 */

int print_env(arg_node *args)
{
	list *temp = args->env;

	while (temp)
	{
		printf("%s\n", temp->str);
		temp = temp->next;
	}
	return (0);
}

/**
 * exit_this - Exits
 * @args: args
 * Return: 0
 *
 */

int exit_this(arg_node *args)
{
	int exit_num = 0;

	if (args->token_array[1])
	{
		exit_num = _atoi(args->token_array[1]);
		if (exit_num == -1)
		{
			errno = EXIT_ERROR;
			error(args);
			return (1);
		}
	}
	else
		exit_num = args->exit_status;
	free_it_all(args, '\0');
	exit(exit_num);
}


