#include "shell.h"

/**
 * add_node_end - Adds node at end of ist
 * @head: Head
 * @str: String
 * Return: New node
 */

list *add_node_end(list **head, const char *str)
{
	list *n_node = NULL;
	list **temp = NULL;

	n_node = malloc(sizeof(*n_node));
	if (!n_node)
		return (NULL);
	n_node->str = _strdup(str);
	if (!n_node->str)
		return (NULL);
	n_node->next = NULL;
	temp = head;
	while (*temp)
		temp = &(*temp)->next;
	n_node->next = *temp;
	*temp = n_node;

	if (!*head)
	{
		*head = n_node;
		return (*head);
	}

	return (n_node);
}

/**
 * list_size - Gets list size
 * @head: Head
 * Return: list size
 */

size_t list_size(const list *head)
{
	size_t i = 0;

	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

/**
 * free_list - Frees linked list
 * @head: Head
 * Return: Void
 */

void free_list(list *head)
{
	list *cur = head;
	list *next = NULL;

	if (head == NULL)
		return;
	while (cur->next != NULL)
	{
		free(cur->str);
		next = cur->next;
		free(cur);
		cur = next;
	}
}

/**
 * arr_to_link - Converts array to list
 * Return: pointer to head
 */

list *arr_to_link(void)
{
	int i = 0;
	list *head = NULL;

	while (environ[i])
	{
		add_node_end(&head, environ[i]);
		i++;
	}
	return (head);
}

