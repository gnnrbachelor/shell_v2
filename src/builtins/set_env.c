#include "../headers/shell.h"

/**
 * print_env - Prints environment
 * @args: Args
 * Return: 0 if success
 */

int print_env(arg_node *args)
{
	list *temp = args->env;

	while (temp)
	{
		printf("%s\n", temp->str);
		temp = temp->next;
	}
	return (0);
}

/**
 * _getenv - Gets environment
 * @command: environment variable
 * @args: Argument node
 * Return: environment
 *
 */

char *_getenv(char *command, arg_node *args)
{
	size_t l = _strlen(command);
	list *head = args->env;

	while (head)
	{
		if (!_strncmp(command, head->str, l))
		{
			command = head->str + l;
			return (command);
		}
		head = head->next;
	}
	return (NULL);
}

/**
 * _setenv - Sets environment variable
 * @args: args
 * Return: 1
 *
 */

int _setenv(arg_node *args)
{
	int stat = 0;

	if (args->token_array[1] && args->token_array[2])
		stat = set_env_var(&(args->env), args->token_array[1], args->token_array[2]);
	else
	{
		stat = 1;
		errno = ENV_ERROR;
		error(args);
	}

	return (stat);
}

/**
 * _set_env_var - Sets environment variable
 * @env: env
 * @name: name
 * @value: value
 * Return: Void
 *
 */

int set_env_var(list **env, char *name, char *value)
{
	list *temp = NULL;
	list *prev = NULL;
	char buf[PATH_MAX] = {0};

	temp = *env;

	while (temp)
	{
		if (find_env_var(name, temp, NULL))
			break;
		prev = temp;
		temp = temp->next;
	}
	sprintf(buf, "%s=%s", name, value);
	if (temp)
	{
		free(temp->str);
	}
	else
	{
		temp = malloc(sizeof(*temp));
		if (!temp)
			return (1);
		temp->next = NULL;
	}
	if (prev)
		prev->next = temp;
	else if (!*env)
		*env = temp;
	temp->str = _strdup(buf);
	if (!temp->str)
		return (1);
	return (0);
}

