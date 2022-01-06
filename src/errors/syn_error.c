#include "../headers/shell.h"

/**
 * handle_syn_err - Handles syntax error
 * @line: Line
 * Return: 0
 *
 */

int handle_syn_err(char *line)
{
	char double_quote = 0;
	char single_quote = 0;
	size_t i = 0;

	for (i = 0; line[i]; ++i)
	{
		single_quote = line[i] == '\'' && (i == 0 ||
				 line[i - 1] != '\\') ? ~single_quote : single_quote;
		double_quote = line[i] == '"' && (i == 0 ||
				 line[i - 1] != '\\') ? ~double_quote : double_quote;
	}
	return (0);
}

/**
 * print_syn_err - Print syntax error
 * @stat: stat
 * @err: error
 * @i: index
 * @j: index 2
 * Return: Void
 */


void print_syn_err(int *stat, char *err, size_t *i, int j)
{
	printf("syntax error %s \n", err);
	*stat = 1;
	if (j)
		++*i;
}

