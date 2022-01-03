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
	int file_d[2];


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
			else if (line[i] == '|' && op != 'p')
			{
				op = 'p';
				args->p_stat = 1;
				line[i] = '\0';
				if (pipe(args->pipe_fd) == -1)
				{
					perror("pipe");
					exit(EXIT_FAILURE);
				}
				file_d[1] = dup(STDOUT_FILENO);
				dup2(args->pipe_fd[1], STDOUT_FILENO);
				execute_shell(args, line + pos);
				dup2(file_d[1], STDOUT_FILENO);
				close(file_d[1]);
				pos = i + 1;
			}
			else if (line[i] == '|' && op == 'p')
			{
				line[i] = '\0';
				args->p_stat = 1;
				file_d[0] = dup(STDIN_FILENO);
				dup2(args->pipe_fd[0], STDIN_FILENO);
				close(args->pipe_fd[0]);
				if (pipe(args->pipe_fd) == -1)
				{
					perror("pipe");
					exit(EXIT_FAILURE);
				}
				file_d[1] = dup(STDOUT_FILENO);
				dup2(args->pipe_fd[1], STDOUT_FILENO);
				execute_shell(args, line + pos);
				dup2(file_d[1], STDOUT_FILENO);
				pos = i + 1;
				dup2(file_d[0], STDIN_FILENO);
				close(file_d[0]);
				close(file_d[1]);
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
	if (op == 'p')
	{
		args->p_stat = 0;
		file_d[0] = dup(STDIN_FILENO);
		dup2(args->pipe_fd[0], STDIN_FILENO);
		execute_shell(args, line + pos);
		dup2(file_d[0], STDIN_FILENO);
		close(file_d[0]);
	}
	else if (op == ';' || (op == '&' && !args->exit_status)
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
