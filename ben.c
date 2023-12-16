#include "ben.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	char *user = NULL;
	(void)ac, (void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "Ben and Dani -> $", 18);
		fflush(stdout);
		read_input(user);
	}
	free(user);
	return (0);
}


/**
 * fwds - checks for "/"
 * @str: string to check
 * Return: 1 for fail else 0
 */

int fwds(const char *str)
{
	if (str != NULL || str[0] == '/')
		return (1);
	return (0);
}
