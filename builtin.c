#include "shell.h"

/**
 * builtins - Selects builtin
 * @args: args
 * Return: 0
 */

int builtins(arg_node *args)
{
	size_t i;
	built_ins func_arr[] = {
		{"cd", changedir},
		{"env", penv},
		{"exit", exit_this},
		{NULL, NULL}
	};

	for (i = 0; func_arr[i].bi; ++i)
		if (!_strcmp(*args->token_array, func_arr[i].bi))
			return (func_arr[i].f(args));
	return (0);
}


int changedir(arg_node *args)
{
	(void) args;

	return (0);
}

int penv(arg_node *args)
{
	(void) args;
	return (0);
}

int exit_this(arg_node *args)
{
	int exit_num = 0;

	if (args->token_array[1])
	{
		exit_num = _atoi(args->token_array[1]);
		if (exit_num == -1)
		{
			printf("Error\n");
			return (1);
		}
	}
	else
		exit_num = args->exit_status;
	free(*args->token_array);
	free(args->token_array);
	exit(exit_num);
}


