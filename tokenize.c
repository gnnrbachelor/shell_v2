#include "shell.h"

/**
 * tokenize - Tokenizes
 * @line: Line
 * Return: pointer to arr
 */

char **tokenize(char *line)
{
	char *token;
	char **arr;
	size_t count = 0;
	size_t i = 0;

	count = count_cmds(line);
	arr = malloc(sizeof(*arr) * (count + 1));
	if (!arr)
		return (NULL);
	token = strtok(line, "\t\n");
	for (; token; i++)
	{
		arr[i] = token;
		token = strtok(NULL, " \t\n");
	}
	arr[i] = NULL;
	return (arr);
}

/**
 * count_cmds - Counts commands
 * @line: line
 * Return: count
 *
 */

ssize_t count_cmds(char *line)
{
	size_t i = 0;
	size_t count = 0;
	size_t word = 0;

	for (; line[i]; i++)
	{
		if (!word && line[i] != ' ')
		{
			word = 1;
			count++;
		}
		else if (word && line[i] == ' ')
			word = 0;
	}
	return (count);
}
