#include "../headers/shell.h"

/**
 * init_arg_node - Inits arg node
 * @args: Arg node
 * @ac: Arg count
 * @av: Args
 * Return: Void
 */

int init_arg_node(arg_node *args, const int ac, char **av)
{
	args->ac = ac;
	args->av = av;
	args->exitchr = "";
	args->token_array = NULL;
	args->env = arr_to_link();
	if (!args->env)
	{
		args->exit_status = EXIT_FAILURE;
		return (EXIT_FAILURE);
	}
	args->exit_status = EXIT_SUCCESS;
	args->cmd_count = 1;
	args->error = "";
	args->pipe_fd[0] = 0;
	args->pipe_fd[1] = 0;
	args->p_stat = -1;
	return (EXIT_SUCCESS);
}

/**
 * prompt - Prompt
 * @args: args
 * @p: prompt
 * Return: Void
 */

void prompt(arg_node *args, char *p)
{
	(void)args;

	if (isatty(STDIN_FILENO))
	{
		fprintf(stderr, "%s ", p);
		args->exitchr = "\n";
	}
}


/**
 * free_it_all - Frees env linked
 * @args: args
 * @mode: mode
 */

void free_it_all(arg_node *args, char mode)
{
	list *temp;

	if (mode == 'L')
	{
		free(args->token_array);
		args->token_array = NULL;
		return;
	}

	if (args->token_array)
		free(*args->token_array);
	free(args->token_array);
	args->token_array = NULL;
	while (args->env)
	{
		temp = args->env;
		args->env = args->env->next;
		free(temp->str);
		free(temp);
	}
	args->env = NULL;
}
