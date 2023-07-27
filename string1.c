#include "shell.h"

/**
 * str_compare - Compare two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: 0 if the strings are equal, otherwise non-zero
 */

int str_compare(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		return (-1);
	}

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * my_strncmp - Compare two strings up to a specified number of characters.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: An integer less than, equal to, or greater than 0, depending on
 * the comparison result (similar to strncmp).
 */

int my_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return ((int)(unsigned char)s1[i] -
					(int)(unsigned char)s2[i]);

		if (s1[i] == '\0' || s2[i] == '\0')
			return (0);
	}

	return (0);
}
