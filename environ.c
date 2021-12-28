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

