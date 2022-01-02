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
	int flags = O_RDWR;
	char *file;

	(void) args;
	for (i = 0; line[i]; ++i)
	{
		if (quote_check(line, i, &q))
		{
			if (line[i] == '>')
			{
				if (i != 0 && is_digit(line[i - 1]))
				{
					file_ds[2] = line[i - 1] - '0';
					line[i - 1] = '\0';
				}
				line[i++] = '\0';
				if (line[i] == '>')
					++i, flags |= O_APPEND | O_CREAT;
				else
					flags |= O_TRUNC | O_CREAT;
				file = strtok(line + i, " \t\n");
				file_ds[0] = open(file, flags, 0666);
				file_ds[1] = dup(file_ds[2]);
				break;

			}
			if (line[i] == '<')
			{
				line[i++] = '\0';
				file = strtok(line + i, " \n");
                                file_ds[0] = open(file, flags, 0664);
				file_ds[2] = STDIN_FILENO;
                                file_ds[1] = dup(file_ds[2]);
				break;
			}
		}
	}
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


