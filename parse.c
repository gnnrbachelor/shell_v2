#include "shell.h"

/**
 * parse_op - Parses operators
 * @arg_node *args
 * @line
 * Return: Void
 *
 */

void parse_op(arg_node *args, char *line)
{
	char q = 0;
	char op = ';';
	size_t i;
	size_t pos = 0;


	for (i = 0; line[i]; ++i)
	{
		if (quote_check(line, i, &q))
		{
			if (comment_check(line, i))
				break;
			if ((line[i] == '&' || line[i] == '|')
			    && i != 0 && line[i - 1] == '\0')
			{
				op = line[i];
				pos = i + 1;
			}
			else if (line[i] == ';' ||
				!_strncmp(line + i, "&&", 2) ||
				!_strncmp(line + i, "||", 2))
			{
				line[i] = '\0';
				if (op == ';' || (op == '&' && !args->exit_status)
					|| (op == '|' && args->exit_status))
						execute_shell(args, line + pos);
				pos = i + 1;
			}
		}
	}
	if (op == ';' || (op == '&' && !args->exit_status)
					|| (op == '|' && args->exit_status))
						execute_shell(args, line + pos);
}



int comment_check(char *line, size_t i)
{
	if (line[i] == '#' && (i == 0 || line[i - 1] == ' '))
	{
		line[i] = '\0';
		return (1);
	}
	return (0);
}
