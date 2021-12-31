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
	char double_quote = 0;
	char single_quote = 0;
	char op = 0;
	size_t i = 0;
	size_t pos = 0;


	op = ';';
	for (i = 0; line[i]; ++i)
	{
		single_quote = line[i] == '\'' && (i == 0 || line[i - 1] != '\\') ? ~single_quote : single_quote;
		double_quote = line[i] == '"' && (i == 0 || line[i - 1] != '\\') ? ~double_quote : double_quote;
		if (!single_quote && !double_quote)
		{
			if (line[i] == '#' && (i == 0 || line[i - 1] == ' '))
			{
				line[i] = '\0';
				execute_shell(args, line + pos);
				return;
			}
			if (line[i] == ';')
			{
				line[i] = '\0';
				if (op == ';' || (op == '&' && !args->exit_status)
					|| (op == '|' && args->exit_status))
						execute_shell(args, line + pos);
				pos = ++i;
			}
			else if (line[i] == '&')
			{
				if (line[i + 1] == '&')
				{
					line[i] = '\0';
					if (op == ';' || (op == '&' && !args->exit_status)
						|| (op == '|' && args->exit_status))
							execute_shell(args, line + pos);
					pos = i + 1;
				}
				else if (i != 0 && line[i - 1] == '\0')
				{
					op = '|';
					pos = i + 1;
				}
			}
		}
	}
	if (op == ';' || (op == '&' && !args-> exit_status)
		|| (op == '|' && args->exit_status))
			execute_shell(args, line + pos);
}
