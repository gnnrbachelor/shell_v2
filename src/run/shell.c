#include "../headers/shell.h"

/**
 * shell - Primary action
 * @args: Args
 * Return: Void
 */


void shell(arg_node *args)
{
	char *line = NULL;
	size_t n;
	ssize_t char_read = 0;

	while (1)
	{
		prompt(args, "$");
		char_read = getline(&line, &n, stdin);

		if (char_read == EOF || handle_syn_err(line))
		{
			printf("%s", args->exitchr);
			free(line);
			return;
		}
		parse_op(args, line);
		++args->cmd_count;
	}
}



/**
 * execute_shell - Execute Shell
 * @args: args
 * @line: line
 * Return: void
 *
 */

void execute_shell(arg_node *args, char *line)
{
	int file_ds[3] = {0};
	int res;

	res = handle_redirect(args, line, file_ds);
	if (res == -1)
		return;

	args->token_array = tokenize(line);
	if (!args->token_array)
		return;
	if (builtins(args))
		make_proc(args);
	free_it_all(args, 'L');
	if (res == 1)
		re_redirect(args, file_ds);
}


