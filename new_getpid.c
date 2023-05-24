#include "shell.h"

/**
 * getPid - Retrieve the process ID of the current process.
 *
 * Return: A string containing the process ID,
 * or NULL if an error occurs.
 */
char *getPid()
{
	int fileDescriptor;
	char *name;
	char *file = "/proc/self/status";
	char *pidString;
	char *pidValue;

	pidString = malloc(256);
	fileDescriptor = open(file, O_RDONLY);
	if (fileDescriptor == -1)
		return (NULL);

	while (get_line(&pidString, fileDescriptor))
	{
		name = strTok(pidString, ":");
		if (my_strcmp(name, "Pid") == 0)
		{
			pidValue = my_strdup(strTok(NULL, "\n \t"));
			free(pidString);
			return (pidValue);
		}
		free(pidString);
		pidString = NULL;
	}
	return (NULL);
}