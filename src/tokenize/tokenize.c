#include "../headers/shell.h"

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
	token = strtok(line, " \t\n");
	for (; token; i++)
	{
		arr[i] = token;
		token = strtok(NULL, " \t\n");
	}
	arr[i] = NULL;
	if (!i)
	{
		free(arr);
		arr = NULL;
	}
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

/**
 * parse_cd_tok - Parses for cd
 * @args: Args
 * Return: 1 or 0
 */

int parse_cd_tok(arg_node *args)
{
	int val = 0;
	char *home = _getenv("HOME=", args);
	char *old = _getenv("OLDPWD=", args);
	char *temp = NULL;

	if (args->token_array[1] == NULL)
	{
		if (home)
			val = chdir(home);
	}
	else if (*args->token_array[1] == '-')
	{
		if (old)
			val = chdir(old);
		temp = getcwd(temp, 0);
		printf("%s\n", temp);
		free(temp);
	}
	else
		val = chdir(args->token_array[1]);
	return (val);
}


/**
 * tokenize_path - Tokenizes path
 * @str: path
 * Return: pointer to new array
 */

char *tokenize_path(char *str)
{
	static char *path;
	char *dir = NULL;
	static size_t cur;
	size_t new;

	if (str)
	{
		cur = 0;
		path = str;
	}

	if (!path || !*(path + cur))
		return (NULL);
	for (new = cur; *(path + new) && *(path + new) != ':'; new++)
		;
	dir = malloc(sizeof(char) * (new - cur + 1));
	if (!dir)
		return (NULL);
	_strncpy(dir, path + cur, new - cur);
	dir[new - cur] = '\0';
	cur = *(path + new) ? ++new : new;
	return (dir);
}

