#include "ben.h"

/**
 * check_delim - function that checks if a character matchs any character
 * @c: character to check
 * @str: string of delimiters
 * Return: 1 on success, 0 on failure
 */
unsigned int check_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - function that extracts tokens of a string
 * @str: string
 * @delim: delimiter
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *tokens;
	static char *new_token;
	unsigned int i;

	if (str != NULL)
		new_token = str;
	tokens = new_token;
	if (tokens == NULL)
		return (NULL);
	for (i = 0; tokens[i] != '\0'; i++)
	{
		if (check_delim(tokens[i], delim) == 0)
			break;
	}
	if (new_token[i] == '\0' || new_token[i] == '#')
	{
		new_token = NULL;
		return (NULL);
	}
	tokens = new_token + i;
	new_token = tokens;
	for (i = 0; new_token[i] != '\0'; i++)
	{
		if (check_delim(new_token[i], delim) == 1)
			break;
	}
	if (new_token[i] == '\0')
		new_token = NULL;
	else
	{
		new_token[i] = '\0';
		new_token = new_token + i + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (tokens);
}




/**
 * create_envi - Creates an array of Enviroment Variables
 * @envi: Array to store Enviroment Variables
 */

void create_envi(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}

/**
 * free_env - Frees the memory of the created Enviroment Variables array
 * @env:  Array of Environment variables
 */
void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}


/**
 * _strlen - function that counts the length of a string
 * @s: string input
 * Return: length of string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

