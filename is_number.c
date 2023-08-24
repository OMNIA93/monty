#include "monty.h"

/**
 * is_number - Checks if a given string represents a valid integer.
 * @str: The string to be checked.
 *
 * Return: 1 if the string represents a valid integer, 0 otherwise.
 */
int is_number(const char *str)
{
if (str == NULL || *str == '\0')
	return (0);

int i = 0;
if (str[i] == '-')
i++;

for (; str[i] != '\0'; i++)
{
if (!isdigit(str[i]))
	return (0);
}

	return (1);
}
