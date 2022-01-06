#include "../headers/shell.h"

/**
 * pipe_wr - Writes to pipe
 * @args: args
 * @line: line
 * @file_d: file desc
 * @op: operator
 * Return: Void
 */

void pipe_wr(arg_node *args, char *line, int *file_d, char *op)
{
	args->p_stat = 1;
	*op = 'p';
	if (pipe(args->pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	file_d[1] = dup(STDOUT_FILENO);
	dup2(args->pipe_fd[1], STDOUT_FILENO);
	execute_shell(args, line);
	dup2(file_d[1], STDOUT_FILENO);
	close(file_d[1]);
}


/**
 * handle_pipe_chain - Handles pipe chain
 * @args: args
 * @line: line
 * @file_d: file desc
 * @op: operator
 * @p_stat: pipe status
 * Return: Void
 */

void handle_pipe_chain(arg_node *args, char *line, int *file_d,
			 char *op, int p_stat)
{
	file_d[0] = dup(STDIN_FILENO);
	dup2(args->pipe_fd[0], STDIN_FILENO);

	if (p_stat == 1)
	{
		close(args->pipe_fd[0]);
		pipe_wr(args, line, file_d, op);
	}
	else
	{
		args->p_stat = 0;
		execute_shell(args, line);
	}
	dup2(file_d[0], STDIN_FILENO);
	close(file_d[0]);
}
