#include "main.h"

/**
 * _printf - print a string to stander out put
 * @str: string input
 * Return: void
 */
void _printf(const char *str)
{
	if (!str)
		return;
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}

/**
 * free_array - free an array of pointers
 * @array: array of pointers
 * Return: void
 */
void free_array(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}

	free(array);
}

/**
 * split - split a given string by a delimiter
 * @d: data struct input
 * @delim: string input
 * Return: void
 */
void split(data *d, const char *delim)
{
	char *token;
	int ntoken = 0;

	d->av = malloc(2 * sizeof(char *));
	if (d->av == NULL)
	{
		free(d->command);
		perror(d->shell_name);
		exit(EXIT_FAILURE);
	}
	d->av[0] = NULL;
	d->av[1] = NULL;

	token = strtok(d->command, delim);
	while (token)
	{
		d->av = realloc(d->av, (ntoken + 2) * sizeof(char *));
		if (d->av == NULL)
			goto free;
		d->av[ntoken] = _strdup(token);
		if (d->av[ntoken] == NULL)
			goto free;
		ntoken++;
		token = strtok(NULL, delim);
	}
	d->av[ntoken] = NULL;
	return;
free:
	free_array(d->av);
	free(d->command);
	perror(d->shell_name);
	exit(EXIT_FAILURE);
}

/**
 * init_data - init data
 * @d: data struct input
 * @shell_name: string input
 * Return: void
 */

void init_data(data *d, const char *shell_name)
{
	d->command = NULL;
	d->av = NULL;
	d->shell_name = shell_name;
	d->exit_code = EXIT_SUCCESS;
	d->flag_overwrite_env = 0;
}

/**
 * read_cmd - get the commend from the prompt and structure it into data struct
 * @d: data struct input
 * Return: void
 */
void read_cmd(data *d)
{
	size_t n = 0;
	ssize_t nread;
	int i = 0;

	nread = _getline(&d->command, &n, stdin);

	if (nread == -1)
	{
		free(d->command);
		exit(EXIT_SUCCESS);
	}

	d->command[nread - 1] = '\0';
	_trim(d->command);
	/* replace hashtag with end of line we can also do it with strtok*/
	for (i = 0; d->command[i] != '\0'; i++)
	{
		if (d->command[0] == '#' || (d->command[i] == '#' && d->command[i - 1] == ' '))
		{
			d->command[i] = '\0';
			break;
		}
	}
	_trim(d->command);
}