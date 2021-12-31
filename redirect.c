#include "shell.h"

/**
 * handle_redirect - Handles redirect
 * @args: Args
 * @line: Line
 * @file_ds: File descriptors
 * Return: Void
 */

void handle_redirect(arg_node *args, char *line, int *file_ds)
{
	char q = 0;
	size_t i;
	int flags = O_RDWR | O_CREAT;
	char *file;

	(void) args;
	for (i = 0; line[i]; ++i)
	{
		if (quote_check(line, i, &q))
		{
			if (line[i] == '>')
			{
				line[i++] = '\0';
				if (line[i] == '>')
				{
					i++;
					flags |= O_APPEND;
				}
				file = strtok(line + i, " \n");
				file_ds[0] = open(file, flags, 0664);
				file_ds[1] = dup(STDOUT_FILENO);
				break;

			}
		}
	}
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
	*q = line[i] == ''\' && (i == 0 || line[i - 1] != '\\') ?
		*quote ^ 1 << 0 : *q;

	*q = line[i] == '"' && (i == 0 || line[i - 1] != '\\') ?
		*quote ^ 1 << 1 : *q;

	return (*quote == 0);
}








