#include "shell.h"

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


