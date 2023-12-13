#include "ben.h"

/**
 * read_input - reads user input
 * @user: command entered by user
 */

void read_input(char *user)
{
	user = _getline();
	parse(user);
	free(user);
}

/**
 * parse - parses the string for command
 * @buff: string to parse
 */

void parse(char *buff)
{
	char *buffer = strdup(buff);
	char *buffer1 = strdup(buff);
	char *tok, **av, *cmd, *path;
	int j, num_tok = 0, i = 0;

	tok = _strtok(buffer1, " \n");
	while (tok != NULL)
	{
		num_tok++;
		tok = _strtok(NULL, " \n");
	}
	av = malloc((num_tok + 1) * sizeof(char *));
	cmd = _strtok(buffer, " \n");
	while (cmd != NULL)
	{
		av[i] = _strdup(cmd);
		strcpy(av[i], cmd);
		cmd = _strtok(NULL, " \n");
		i++;
	}
	av[i] = NULL;
	path = path_finder(av[0]);
	run(path, av);
	free(path);
	for (j = 0; j < i; j++)
		free(av[j]);
	free(av);
	free(buffer);
	free(buffer1);
}


/**
 * run - runs commands
 * @av: command to run
 * @path: path to the exec
 */

void run(char *path, char **av)
{
	int stat;
	pid_t gameli = fork();

	if (gameli == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (gameli == 0)
	{
		if (execve(path, av, environ) == -1)
		{
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(gameli, &stat, WUNTRACED);
	}
}



/**
 * path_finder - finds path of files in the directory
 * @file: name of the file to search for
 * Return: the path of the file
 */

char *path_finder(char *file)
{
	char *path, *fullpath;

	path = getenv("PATH");

	if (fwds(file) && access(file, X_OK) == 0)
	{
		return (strdup(file));
	}
	if (path == NULL)
	{
		perror("error getting path");
		exit(EXIT_FAILURE);
	}
	fullpath = loc_finder(path, file);
	if (fullpath == NULL)
	{
		perror("Absolute path not found");
		return (NULL);
	}
	return (fullpath);
}


/**
 * loc_finder - finds the location of an executable
 * @path: path to the executable
 * @file: name of the executable
 * Return: NULL
 */

char *loc_finder(char *path, char *file)
{
	char *pathcpy, *str, *buffer = NULL;
	struct stat f_path;

	pathcpy = strdup(path);
	str = strtok(pathcpy, ":");

	while (str)
	{
		buffer = malloc(strlen(str) + strlen(file) + 2);
		if (buffer == NULL)
		{
			perror("Error: memory allocation failed");
			exit(EXIT_FAILURE);
		}
		strcpy(buffer, str);
		strcat(buffer, "/");
		strcat(buffer, file);

		if (stat(buffer, &f_path) == 0 && access(buffer, X_OK) == 0)
		{
			free(pathcpy);
			return (buffer);
		}
		free(buffer);
		str = strtok(NULL, ":");
	}
	free(pathcpy);
	return (NULL);
}
