#include "shell.h"

/**
 * add_node - Adds node at beginning
 *
 * @head: Current head
 * @str: data
 *
 * Return: NULL or address of new head
 */

list_t *add_node(list_t **head, const char *str)
{
	int i;
	list_t *n_node;

	for (i = 0; str[i]; i++)
		;

	if (head && str)
	{
		n_node = malloc(sizeof(list_t));
		if (n_node)
		{
			n_node->str = strdup(str);
			n_node->len = i;
			n_node->next = *head;

			*head = n_node;
		}
		else
			return (NULL);
	}
	return (n_node);

}

/**
 * count_cmd - Prints elements of a list_t list
 *
 * @h: pointer to head
 *
 * Return: Number of nodes
 */

size_t count_cmd(const list_t *h)
{
	unsigned int i;
	cmd_node *temp = h;

	for (i = 0; h; i++)
		temp = temp->next;
	return (i);
}


/**
 * print_list - Prints elements of a list_t list
 *
 * @h: pointer to head
 *
 * Return: void
 */

void print_list(const list_t *h)
{
	unsigned int i;
	cmd_node temp = h;

	while (temp)
	{
		printf("%s\n", temp->str);
		h = h->next;

	}
}


/**
 * free_list - Free a list_t list
 *
 * @head: pointer to head
 *
 * Return: Void
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}

}
