#include "shell.h"

/**
 *
 *
 *
 */

int builtins(arg_node *args)
{
	size_t i;
	built_ins func_arr[] = {
		{"cd", changedir},
		{"env", penv},
		{"exit", callexit},
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

int callexit(arg_node *args)
{
	(void) args;
	return (0);
}


