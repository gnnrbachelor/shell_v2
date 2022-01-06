#include "../headers/shell.h"

/**
 * quote_check - Parses for single quote
 * @line: Line
 * @i: counter
 * @q: quote
 * Return: 0;
 */

char quote_check(char *line, size_t i, char *q)
{
	*q = line[i] == '\'' && (i == 0 || line[i - 1] != '\\') ?
		*q ^ 1 << 0 : *q;

	*q = line[i] == '"' && (i == 0 || line[i - 1] != '\\') ?
		*q ^ 1 << 1 : *q;

	return (*q == 0);
}

/**
 * handle_redirect_errors - Handles redirect errors
 * @args: args
 * @file_ds: file desc
 * @flags: flags
 * @file: File
 * @is_valid: Valid?
 * @which_redirect: Which redirect
 * Return: 1 or -1
 */

int handle_redirect_errors(arg_node *args, int *file_ds,
				int flags, char *file, int is_valid,
				int which_redirect)
{
	if (!file)
	{
		fprintf(stderr, "%s: %lu: ", *args->av,
			 args->cmd_count);
		fprintf(stderr, "Syntax error: newline unexpected\n");
		args->exit_status = 2;
		return (-1);
	}
	file_ds[0] = open(file, flags, 0666);
	file_ds[1] = dup(file_ds[2]);
	if (file_ds[0] == -1 || (file_ds[1] == -1 && !is_valid))
	{
		fprintf(stderr, "%s: %lu: ", *args->av, args->cmd_count);
		if (errno == EACCES || errno == ENOENT)
			fprintf(stderr, "%s %s %s: ", "cannot",
				which_redirect ? "create" : "open", file);
		if (errno == ENOENT && !which_redirect)
			fprintf(stderr, "No such file\n");
		else
			perror(NULL);
		args->exit_status = 2;
		return (-1);
	}
	if (dup2(file_ds[0], file_ds[2]) == -1 && !is_valid)
	{
		error(args);
		return (-1);
	}
	return (1);
}


/**
 * re_redirect - reverts redirect
 * @args: args
 * @file_ds: file desc
 */


void re_redirect(arg_node *args, int *file_ds)
{
	(void) args;
	dup2(file_ds[1], file_ds[2]);
	close(file_ds[0]);
	unlink("/tmp/tmp_file.txt");
}



