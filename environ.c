#include "shell.h"

/**
 * _getenv - Gets environment
 * @env_var: environment variable
 * @args: Argument node
 * Return: environment var
 *
 */

char *_getenv(char *command, arg_node *args)
{
	size_t l = _strlen(command);
	list *head = args->head;

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
