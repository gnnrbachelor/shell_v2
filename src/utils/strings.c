#include "../headers/shell.h"

/**
 * _memset - memset
 * @s: s
 * @b: b
 * @n: n
 * Return: pointer to buffer
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; ++i)
		s[i] = b;
	return (s);
}

/**
 * _strcat - Concats two strings
 * @dest: Destination
 * @src: String
 * Return: Pointer to string
 */

char *_strcat(char *dest, char *src)
{
	int i = _strlen(dest);
	int j = 0;

	while (src[j])
		dest[i++] = src[j++];
	dest[i] = src[j];
	return (dest);
}

/**
 * _strncmp - Compares two strings at n bytes
 * @s1: String 1
 * @s2: String 2
 * @n: n
 * Return: Diff
 *
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] == s2[i])
			++i;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strcmp - Compares two strings
 * @s1: String 1
 * @s2: String 2
 * Return: Diff between
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}


/**
 * _atoi - Converts str to int
 * @s: String
 * Return: integer
 */

int _atoi(char *s)
{
	size_t i;
	size_t n = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i]; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
			n = n * 10 + (s[i] - '0');
		else
			return (-1);
	}
	if (n > INT_MAX)
		return (-1);
	return (n);
}
