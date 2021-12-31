#include "shell.h"

/**
 * init_arg_node - Inits arg node
 * @args: Arg node
 * @ac: Arg count
 * @av: Args
 * Return: Void
 */

void init_arg_node(arg_node *args, const int ac, char **av)
{
	args->ac = ac;
	args->av = av;
	args->exitchr = "";
	args->token_array = NULL;
	args->env = arr_to_link();
	args->exit_status = 0;
	args->cmd_count = 1;
}

/**
 * prompt - Prompt
 * @args: args
 * Return: Void
 */

void prompt(arg_node *args)
{
	(void)args;

	if (isatty(STDIN_FILENO))
	{
		printf("hsh$ ");
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
		prompt(args);
		char_read = getline(&line, &n, stdin);

		if (char_read == EOF)
		{
			printf("%s", args->exitchr);
			free(line);
			return;
		}
		++args->cmd_count;
		parse_op(args, line);
	}
}


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
	size_t i, pos = 0;

	for (i = 0; line[i]; ++i)
	{
		single_quote = line[i] == '\'' && (i == 0 || line[i - 1] != '\\') ? ~single_quote : single_quote;
		double_quote = line[i] == '"' && (i == 0 || line[i - 1] != '\\') ? ~double_quote : single_quote;
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
				execute_shell(args, line + pos);
				pos = ++i;
			}
		}
	}
	execute_shell(args, line + pos);
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
	args->token_array = tokenize(line);
	if (!args->token_array)
		return;
	if (builtins(args) == 2)
		make_proc(args);
	free_it_all(args, 'L');
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
