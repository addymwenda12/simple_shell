#include "shell.h"

/**
 * my_isalnum - Checks if the character is alphanumeric
 * @c: Character to check
 *
 * Return: Alphanumeric character
 */

int my_isalnum(int c)
{
	return ((c >= '0' && c <= '9') ||
			(c >= 'A' && c <= 'Z') ||
			(c >= 'a' && c <= 'z'));
}

/**
 * *my_strncpy - Copies n characters from the source string
 * to destination string
 *
 * @dest: Destination string to be copied to
 * @src: The source string
 * @n: Amount of characters to be copied
 *
 * Return: Concatenated string
 */

char *my_strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

/**
 * *my_strcpy - Copies the source string to the destination string
 * @dest: The destination string
 * @src: The source string
 *
 * Return: the concatenated string
 */

char *my_strcpy(char *dest, char *src)
{
	char *save = dest;

	while ((*dest++ = *src++))
		;
	return (save);
}

/**
 * *my_strchr - Returns a pointer to the first occurrence of the character c
 * in the string s
 * @s: the string to be parsed
 * @c: the character to look for
 *
 * Return: (s) a pointer to the memory area s
 */

char *my_strchr(char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}
