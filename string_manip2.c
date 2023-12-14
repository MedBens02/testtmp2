#include "main.h"


/**
 * _strdup - duplicates a str
 * @str: str
 *
 * Return: duplicated str
 */
char *_strdup(const char *str)
{
	char *dup;
	int i, length = 0;

	if (str == NULL)
		return (NULL);
	while (str[length])
		length++;
	dup = malloc(sizeof(char) * (length + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		dup[i] = str[i];
	return (dup);
}



/**
 * is_digit - checks if a number is positive
 *
 * @str: arr of strs
 *
 * Return: 1 if positive, otherwise 0
 */

int is_digit(const char *str)
{
	int i = 0;

	if (str == NULL || str[0] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
