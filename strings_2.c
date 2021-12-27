#include "shell.h"

/**
 * _strchr - Finds char in string
 * @s: String
 * @c: Char
 * Return: Pointer to first occ
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i++])
		if (s[i] == c)
			return (s + i);
	return (0);
}


/**
 * _strlen - Gets length of string
 * @str: string
 * Return: length
 */

size_t _strlen(char *str)
{
	size_t i = 0;

	while (*(str + i))
		++i;
	return (i);
}

/**
 * _strdup- Duplicates String
 * @str: String
 * Return: pointer to new string
 *
 */

char *_strdup(const char *str)
{
	char *s;
	int i = 0;

	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	s = malloc(sizeof(char) * i + 1);


