#include "shell.h"

/**
 * own_help - prints help function
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int own_help(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	long unsigned int i = 0;
	(void)(**args);

	printf("\n---help simple_shell---\n");
	printf("Enter a command and its arguments, then press enter\n");
	printf("Built-in commands:\n");
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		printf("  -> %s\n", builtin_func_list[i]);
	}
	printf("For information on other programs, use the man command.\n\n");
	return (-1);
}
