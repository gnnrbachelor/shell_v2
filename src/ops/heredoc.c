#include "../headers/shell.h"

/**
 * heredoc - handles heredoc
 * @args: args
 * @line: line
 * @i: index
 * Return: temp file
 */

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
		    (!_strncmp(buffer, end_char, _strlen(end_char))
			&& _strlen(end_char) == _strlen(buffer) - 1))
			break;
		write(file_ds, buffer, rd_size);
	}
	free(buffer);
	close(file_ds);
	return (file);
}
