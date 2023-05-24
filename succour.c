#include "shell.h"

/**
 * succour - help builtin command
 * @cmd: the command line inserted
 *
 * Return: 0 if success (always)
 */
int succour(char *cmd)
{
	int fd, r;
	char *file;
	char *s;

	if (cmd == NULL)
	{
		s = "help: no builtin entered.\n";
		r = my_strlen(s);
		r = write(1, s, r);
		return (0);
	}

	if (!my_strcmp(cmd, "cd"))
	{
		file = "helpCd";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!my_strcmp(cmd, "history"))
	{
		file = "helpHist";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!my_strcmp(cmd, "help"))
	{
		file = "helpHel";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!my_strcmp(cmd, "alias"))
	{
		file = "helpAl";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	} else if (!my_strcmp(cmd, "unset"))
	{
		file = "helpUnset";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!my_strcmp(cmd, "unalias"))
	{
		file = "helpUnal";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!my_strcmp(cmd, "env"))
	{
		file = "helpEnv";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!my_strcmp(cmd, "setenv"))
	{
		file = "helpSetenv";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!my_strcmp(cmd, "unsetenv"))
	{
		file = "helpUnenv";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else
	{
		s = "help: no help topics match.\n";
		r = my_strlen(s);
		r = write(1, s, r);
		return (0);
	}
}