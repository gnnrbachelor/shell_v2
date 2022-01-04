#include "../headers/shell.h"

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



