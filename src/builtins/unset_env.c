#include "../headers/shell.h"

/**
 * _unsetenv - Unsets environment var
 * @args: Args
 * Return: 1 if success
 */

int _unsetenv(arg_node *args)
{
	list *temp = NULL;
	list *prev = NULL;

	if (!args->token_array[1])
	{
		errno = ENV_ERROR;
		error(args);
		return (1);
	}
	temp = args->env;
	while (temp)
	{
		if (find_env_var(NULL, temp, args))
		{
			if (prev)
				prev->next = temp->next;
			else
				args->env = temp->next;
			free(temp->str);
			free(temp);
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	return (0);
}


/**
 * find_env_var - Finds matching env var
 * @s: String
 * @s2: String2
 * @args: args node
 *
 */

size_t find_env_var(char *s, list *s2, arg_node *args)
{
	char *p = NULL;
	size_t l;

	if (!s)
		s = args->token_array[1];
	l = _strlen(s);
	p = _strchr(s2->str, '=');
	return ((l == (size_t) (p - s2->str) &&
			!(_strncmp(s2->str, s, l))));
}


