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
	char *p;
	size_t l;

	if (!args->token_array[1])
	{
		perror("called in _unsetenv");
		return (1);
	}
	temp = args->env;
	l = _strlen(args->token_array[1]);
	while (temp)
	{
		p = _strchr(temp->str, '=');
		if (l == (size_t) (p - temp->str) &&
		   !(_strncmp(temp->str, args->token_array[1], l)))
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
	if (args->token_array[1] && args->token_array[2])
	{
		set_env_var(&(args->env), args->token_array[1], args->token_array[2]);
		return (0);
	}
	perror("setenv gone wrong");
	return (1);
}

/**
 * _set_env_var - Sets environment variable
 * @env: env
 * @name: name
 * @value: value
 * Return: Void
 *
 */

void set_env_var(list **env, char *name, char *value)
{
	list *temp = NULL;
	list *prev = NULL;
	char *p = NULL;
	char buf[PATH_MAX] = {0};
	size_t l;

	temp = prev = *env;
	l = _strlen(name);

	while (temp)
	{
		p = _strchr(temp->str, '=');
		if (l == (size_t ) (p - temp->str) && !(_strncmp(temp->str, name, l)))
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
		temp->next = NULL;
	}
	if (prev)
		prev->next = temp;
	else
		*env = temp;
	temp->str = _strdup(buf);
}


