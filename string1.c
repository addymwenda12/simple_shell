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
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
