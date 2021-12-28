#include "shell.h"


void init_arg_node(arg_node *args, const int ac, char **av)
{
	args->ac = ac;
	args->av = av;
	args->exitchr = '\0';
	args->token_array = NULL;
	args->env = arr_to_link();
	args->exit_status = 0;
}

void prompt(arg_node *args)
{
	(void)args;

	if (isatty(STDIN_FILENO))
	{
		printf("hsh$ ");
		args->exitchr = '\n';
	}
}


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
			printf("%c", args->exitchr);
			free(line);
			return;
		}
		if (*line == '\n')
			continue;

		args->token_array = tokenize(line);
		if (!args->token_array)
			continue;

		builtins(args);
		free_it_all(args, 'L');;
	}
}

void free_it_all(arg_node *args, char mode)
{
	list *temp;

	if (mode == 'L')
	{
		free(args->token_array);
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
