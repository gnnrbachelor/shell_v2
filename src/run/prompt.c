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
 * shell - Primary action
 * @args: Args
 * Return: Void
 */


void shell(arg_node *args)
{
	char *line = NULL;
	size_t n;
	ssize_t char_read = 0;

	while (1)
	{
		prompt(args, "$");
		char_read = getline(&line, &n, stdin);

		if (char_read == EOF || handle_syn_err(line))
		{
			printf("%s", args->exitchr);
			free(line);
			return;
		}
		parse_op(args, line);
		++args->cmd_count;
	}
}



/**
 * execute_shell - Execute Shell
 * @args: args
 * @line: line
 * Return: void
 *
 */

void execute_shell(arg_node *args, char *line)
{
	int file_ds[3] = {0};
	int res;

	res = handle_redirect(args, line, file_ds);
	if (res == -1)
		return;

	args->token_array = tokenize(line);
	if (!args->token_array)
		return;
	if (builtins(args))
		make_proc(args);
	free_it_all(args, 'L');
	if (res == 1)
		re_redirect(args, file_ds);
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