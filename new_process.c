#include "shell.h"

/**
 * new_process - creates new process
 * @args: array of strings containing the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */
int new_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid ==  0)
	{
		/* child process */
		if (execvp(args[0], args) == -1)
		{
			perror("new_process error resulting from child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* error forking */
		perror("new_process error while forking");
	}
	else
	{
		/* parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
