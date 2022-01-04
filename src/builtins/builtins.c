#include "../headers/shell.h"

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



