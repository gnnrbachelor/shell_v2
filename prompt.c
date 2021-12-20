#include "shell.h"


void init_arg_node(arg_node *args, const int ac, char **av)
{
	args->ac = ac;
	args->av = av;
	args->exitchr = '\0';
	args->token_array = NULL;
	args->head = NULL;
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
		builtins(args);
		free(args->token_array);
	}
}
