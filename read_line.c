#include "shell.h"

/**
 * read_line - reads a line from the stdin
 *
 * Return: pointer that points to a string with the line content
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1) /* if getline fails */
	{
		if (feof(stdin)) /* test for the eof */
		{
			free(line); /* avoid memory leaks when ctrl + d */
			exit(EXIT_SUCCESS); /* we recieved an eof */
		}
		else
		{
			free(line);
			perror("error reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
