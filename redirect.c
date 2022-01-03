#include "shell.h"

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

char *heredoc(arg_node *args, char *line, size_t i)
{
	char *buffer = NULL;
	int file_ds;
	static char *file = "/tmp/tmp_file.txt";
	char *end_char = strtok(line + i + 1, " \t\n");
	ssize_t rd_size;
	size_t s = 0;

	file_ds = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file_ds == -1)
	{
		error(args);
		return (NULL);
	}
	while (1)
	{
		prompt(args, ">");
		rd_size = getline(&buffer, &s, stdin);
		if ((rd_size == -1 || rd_size == 0) ||
		    (!_strncmp(buffer, end_char, _strlen(end_char)) 			&& _strlen(end_char) == _strlen(buffer) - 1))
			break;
		write(file_ds, buffer, rd_size);
	}
	free(buffer);
	close(file_ds);
	return (file);
}



int is_digit(char n)
{
	return (n >='0' && n <= '9' ? 1 : 0);
}



/**
 * quote_check - Parses for single quote
 * @line: Line
 * @i: counter
 * @quote: Is quote b
 * Return: 0;
 */

char quote_check(char * line, size_t i, char *q)
{
	*q = line[i] == '\'' && (i == 0 || line[i - 1] != '\\') ?
		*q ^ 1 << 0 : *q;

	*q = line[i] == '"' && (i == 0 || line[i - 1] != '\\') ?
		*q ^ 1 << 1 : *q;

	return (*q == 0);
}

int handle_redirect_errors(arg_node *args, int *file_ds, int flags, char *file, int is_valid, int which_redirect)
{
	if (!file)
	{
		fprintf(stderr, "%s: %lu: ", *args->av, args->cmd_count);
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

void re_redirect(arg_node *args, int *file_ds)
{
	(void) args;
	dup2(file_ds[1], file_ds[2]);
	close(file_ds[0]);
	unlink("/tmp/tmp_file.txt");
}





