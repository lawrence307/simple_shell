#include "shell.h"

/**
 * shell_interactive - the  UNIX command line interpreter
 *
 * Return: void
 */
void shell_interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		printf("law_shell$ "); 
		line = read_line();
		args = split_line(line); /* tokenize line */
		status = execute_args(args);
		/* avoid memory leaks */
		free(line);
		free(args);
		/* exit with status */
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
