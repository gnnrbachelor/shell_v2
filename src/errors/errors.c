#include "../headers/shell.h"

/**
 * error - Handles errors
 * @args: args
 * Return: Void
 */

void error(arg_node *args)
{
	fprintf(stderr, "%s: %lu ", *args->av, args->cmd_count);
	if (errno == EXIT_ERROR)
	{
		fprintf(stderr, "%s: Illegal number: %s\n", *args->token_array, args->token_array[1]);
		args->exit_status = 2;
	}
	else if (errno == CD_ERROR)
	{
		fprintf(stderr, "%s: can't cd to %s\n",
				*args->token_array, args->token_array[1]);
		args->exit_status = 2;
	}
	else if (errno == EACCES)
	{
		perror("cannot create file");
		args->exit_status = 126;
	}
	else if (errno == ENOENT)
	{
		fprintf(stderr, "%s: not found\n", *args->token_array);
		args->exit_status = 127;
	}
	else if (errno == ENV_ERROR)
	{
		fprintf(stderr, "%s: invalid argument(s)\n", *args->token_array);
		args->exit_status = 2;
	}
	else
		perror(NULL);
}

int handle_syn_err(char *line)
{
	char double_quote = 0;
	char single_quote = 0;
	size_t i = 0;

	for (i = 0; line[i]; ++i)
	{
		single_quote = line[i] == '\'' && (i == 0 || line[i - 1] != '\\') ? ~single_quote : single_quote;
		double_quote = line[i] == '"' && (i == 0 || line[i - 1] != '\\') ? ~double_quote : double_quote;
/*		if (!single_quote && !double_quote && step_parse(line + i, &i))
			return (1);
*/
	}
	return (0);
}


void print_syn_err(int *stat, char *err, size_t *i, int j)
{
	printf("syntax error %s \n", err);
	*stat = 1;
	if (j)
		++*i;
}


