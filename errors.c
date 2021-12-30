#include "shell.h"

/**
 * error - Handles errors
 * @args: args
 * Return: Void
 */

void error(arg_node *args)
{
	fprintf(stderr, "%s: ", *args->av + 2);
	if (errno == EXIT_ERROR)
	{
		fprintf(stderr, "%lu: %s: Illegal number: %s\n", args->cmd_count,
				*args->token_array, args->token_array[1]);
	}
	else if (errno == CD_ERROR)
	{
		fprintf(stderr, "%lu: %s: can't cd to %s\n", args->cmd_count,
				*args->token_array, args->token_array[1]);
	}
	else if (errno == EACCES)
	{
		perror(NULL);
		args->exit_status = 126;
	}
	else if (errno == ENOENT)
	{
		fprintf(stderr, "%s: not found\n", *args->token_array);
		args->exit_status = 127;
	}
	else
		perror(NULL);
}

