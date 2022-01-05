#include "../headers/shell.h"

/**
 * handle_redirect - Handles redirect
 * @args: Args
 * @line: Line
 * @file_ds: File descriptors
 * Return: Void
 */

int handle_redirect(arg_node *args, char *line, int *file_ds)
{
	char q = 0;
	size_t i;

	for (i = 0; line[i]; ++i)
	{
		if (quote_check(line, i, &q))
		{
			if (line[i] == '>')
			{
				file_ds[2] = STDOUT_FILENO;
				return (redirect_stdout(args, line, i, file_ds));
			}
			if (line[i] == '<')
			{
				file_ds[2] = STDIN_FILENO;
				return (redirect_stdin(args, line, i, file_ds));
			}
		}

	}
	return (0);
}


int redirect_stdout(arg_node *args, char *line, size_t i, int *file_ds)
{
	char *file;
	int flags = O_WRONLY | O_CREAT | O_TRUNC, is_valid = 0;

	if (i != 0 && is_digit(line[i - 1]))
	{
		file_ds[2] = line[i - 1] - '0';
		line[i - 1] = '\0';
		is_valid = 1;
	}

	line[i++] = '\0';
	if (line[i] == '>')
		++i, flags = (flags & ~O_TRUNC) | O_APPEND;
	file = strtok(line + i, " \t\n");

	return (handle_redirect_errors(args, file_ds, flags, file, is_valid, 1));

}

int redirect_stdin(arg_node *args, char *line, size_t i, int *file_ds)
{
	int flags = O_RDONLY;
	char *file;

	line[i++] = '\0';
	if (line[i] == '<')
		file = heredoc(args, line, i);
	else
		file = strtok(line + i, " \t\n");
	return (handle_redirect_errors(args, file_ds, flags, file, 0, 0));
}



