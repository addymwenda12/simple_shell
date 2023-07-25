#include "shell.h"

/**
 * str_to_int - Convert a string to an integer
 * @s: String to be converted
 *
 * Return: The converted integer
 */

int str_to_int(char *s)
{
	int result = 0;
	int sign = 1;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}

	return (sign * result);
}

/**
 * my_strlen - Measure the string length
 * @s: String to be measured
 *
 * Return: The length of string
 */

int my_strlen(char *s)
{
	int len = 0;

	while (*s++)
	{
		len++;
	}
	return (len);
}

/**
 * my_strdup - Creates a duplicate of a string
 * @src: string duplicate
 *
 * Return: The duplicated string
 */

char *my_strdup(char *src)
{
	char *str = malloc(my_strlen(src) + 1);
	char *p = str;

	while (*src)
	{
		*p++ = *src++;
	}
	*p = '\0';

	return (str);
}

/**
 * my_strcat - Concatenate one string to the end of another string
 * @s1: The first string
 * @s2: The second string
 *
 * Return: Concatenated string
 */

char *my_strcat(char *s1, char *s2)
{
	char *str = malloc(my_strlen(s1) + my_strlen(s2) + 1);
	char *p = str;

	while (*s1)
	{
		*p++ = *s1++;
	}
	while (*s2)
	{
		*p++ = *s2++;
	}
	*p = '\0';
	return (str);
}

/**
 * itoa - converts integer to string
 * @num: Number to be converted
 *
 * Return: Converted string
 */

char *itoa(int num)
{
	char *str = malloc(20);
	char temp;
	int i = 0, j = 0;
	int sign = (num < 0) ? -1 : 1;

	num = (sign < 0) ? -num : num;

	do {
		str[i++] = num % 10 + '0';
	} while (num /= 10);

	if (sign < 0)
	{
		str[i++] = '-';
	}

	str[i] = '\0';

	for (j = 0; j < i / 2; j++)
	{
		temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}

	return (str);
}
