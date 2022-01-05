#include "../headers/shell.h"

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
	if (s == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i++] = '\0';
	return (s);
}

/**
 * _strncpy - Copies String
 * @dest: destination
 * @src: src
 * @n: # of bytes
 * Return: pointer to dest
 */


char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0' && i < n; i++)
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

/**
 * is_digit - Determines if digit
 * @n: int
 * Return: 1 or 0
 */

int is_digit(char n)
{
	return (n >='0' && n <= '9' ? 1 : 0);
}



