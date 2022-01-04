#include "../headers/shell.h"

/**
 * changedir - cd command
 * @args: args
 * Return: 0;
 */

int changedir(arg_node *args)
{
	char *cur = NULL;
	char *next = NULL;

	cur = getcwd(cur, 0);
	if (parse_cd_tok(args) == -1)
	{
		errno = CD_ERROR;
		error(args);
		free(cur);
		return (1);
	}
	next = getcwd(next, 0);
	set_env_var(&(args->env), "OLDPWD", cur);
	set_env_var(&(args->env), "PWD", next);
	free(next);
	free(cur);
	return (0);
}

