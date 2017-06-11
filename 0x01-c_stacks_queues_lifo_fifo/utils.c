#include "monty.h"

/**
 * strstrip - Takes an string and trims the trailing and leading spaces
 * @s : string
 *
 * Return: stripped string
 */
char *strstrip(char *s)
{
	size_t size;
	char *end;

	size = strlen(s);
	if (!size)
		return (s);

	end = s + size - 1;
	while (end >= s && isspace(*end))
		end--;
	*(end + 1) = '\0';

	while (*s && isspace(*s))
		s++;

	return (s);
}

/**
 * isnum - checks if string is a number.
 * @str: A string to check.
 *
 * Return: 1 if true else 0.
 */
int isnum(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (i == 0 && str[i] == '-')
		{
			i++;
		}

		if (isdigit(str[i]) == 0)
		{
			return (0);
		}
	}

	return (1);
}
