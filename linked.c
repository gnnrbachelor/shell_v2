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
	list *temp = *head;

	n_node = malloc(sizeof(list));
	if (!n_node)
		return (NULL);
	n_node->str = _strdup(str);
	n_node->next = NULL;
	if (!head)
	{
		*head = n_node;
		return (*head);
	}

	while (temp->next)
		temp = temp->next;
	temp->next = n_node;
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

