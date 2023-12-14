#include "main.h"

/**
 * _strlen - returns the length of a string.
 *
 * @s: setring
 *
 * Return: string length
 */
unsigned int _strlen(char *s)
{
	int len;

	for (len = 0; *s != '\0'; s++)
		++len;

	return (len);
}


/**
 * _strcmp - compares two strings.
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: comparison result
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strncmp - compares two strings.
 *
 * @s1: input const string
 * @s2: input const string
 * @n: input int
 *
 * Return: returns an integer indicating the result of the comparison,
 *	as follows:
 *		• 0, if the s1 and s2 are equal
 *		• a negative value if s1 is less than s2
 *		• a positive value if s1 is greater than s2
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * *_strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 *
 * @dest: buffer
 * @src: input
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	char *pt_to_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (pt_to_dest);
}

/**
 * _strcat - concatenates two strings.
 *
 * @dest: result
 * @src: source
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, const char *src)
{
	char *end = dest;

	while (*end != '\0')
		end++;
	while (*src != '\0')
	{
		*end = *src;
		end++;
		src++;
	}

	*end = '\0';
	return (dest);
}
