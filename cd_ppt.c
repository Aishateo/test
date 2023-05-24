#include "shell.h"

/**
 * cd - change directory builtin
 * @av: argument to work with
 * Return: int
 */
int cdPrompt(char *av[])
{
	int ret, printPath = 0;
	char *oldPwd = NULL, *newPath, *pathBit, *newPtr;
	char *homeStr = "HOME", *oldPwdStr = "OLDPWD";

	oldPwd = getcwd(oldPwd, 0);
	if (oldPwd == NULL)
		return (1);
	if (av[1] == NULL || av[1][0] == 0)
	{
		newPath = getEnv(homeStr);
		if (newPath == homeStr)
			newPath = my_strdup("");
		av[1] = newPath;
		av[2] = NULL;
	}
	else if (av[1][0] == '-' && av[1][1] == 0)
	{
		newPath = getEnv(oldPwdStr);
		if (newPath == oldPwdStr)
			newPath = my_strdup("");
		printPath = 1;
		free(av[1]);
		av[1] = newPath;
	}

#ifdef DEBUGCD
	printf("Making newPath %s:%c\n", av[1], av[1][0]);
#endif

	newPath = malloc(sizeof(char) * (my_strlen(oldPwd) + my_strlen(av[1]) + 2));
	if (newPath == NULL)
		return (-1);
	newPtr = newPath;
	pathBit = oldPwd;
	if (av[1][0] != '/' && pathBit[1] != 0)
		while (*pathBit)
			*newPtr++ = *pathBit++;
	*newPtr++ = '/';
	pathBit = strtok(av[1], "/");

#ifdef DEBUGCD
	printf("Starting newPath:%s:PathBit got:%s\n", newPath, pathBit);
	printf("newPath/ptr diff:%p\n", newPtr - newPath);
#endif

	while (pathBit != NULL)
	{
		if (pathBit[0] == '.' && pathBit[1] == '.' && pathBit[2] == 0)
		{
#ifdef DEBUGCD
			printf("Going back a directory%s:%s\n", newPath, newPath);
#endif
			newPtr--;
			if (newPtr != newPath)
				newPtr--;
			while (*newPtr != '/')
				newPtr--;
			*newPtr++ = '/';
		}
		else if (!(pathBit[0] == '.' && pathBit[1] == 0))
		{
			while (*pathBit)
				*newPtr++ = *pathBit++;
			*newPtr++ = '/';
		}
		pathBit = strtok(NULL, "/");

#ifdef DEBUGCD
		printf("Got pathBit:%s\n", pathBit);
#endif
	}

	if (newPtr != newPath && newPtr != newPath + 1)
		newPtr--;
	*newPtr = 0;

#ifdef DEBUGCD
	printf("New path:%s\n", newPath);
#endif

	ret = chdir(newPath);
	if (ret == 0)
	{
		setEnv("OLDPWD", oldPwd);
		free(oldPwd);
		setEnv("PWD", newPath);
		if (printPath)
			fPrintStrings(1, newPath, "\n", NULL);
		free(newPath);
		return (0);
	}

	printError(": cd: can't cd to ");
	fPrintStrings(STDERR_FILENO, av[1], "\n", NULL);
	free(oldPwd);
	free(newPath);
	return (ret);
}