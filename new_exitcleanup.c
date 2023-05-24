#include "shell.h"
#include "shell_vars.h"
#include "my_alias.h"

ShellVar **getSpecial();
ShellVar **getVars();
my_AliasData **getAList();
char ***getEnviron();

/**
 * exitCleanup - cleans up various variables before exiting
 *
 * @argList: argument list to free (if any)
 * Return: void
 */
void exitCleanup(char **argList)
{
	ShellVar *specialPtr = *(getSpecial());
	ShellVar *specialNext;
	my_AliasData *aliasPtr = *(getAList());
	my_AliasData *aliasNext;
	char **environ = *(getEnviron());
	int index = 0;

	if (argList != NULL)
	{
		for (index = 0; argList[index] != NULL; index++)
		{
			free(argList[index]);
		}
	}

	index = 0;
	while (environ[index] != NULL)
	{
		free(environ[index]);
		index++;
	}
	free(environ);

	while (specialPtr != NULL)
	{
		free(specialPtr->val);
		free(specialPtr->name);
		specialPtr = specialPtr->next;
	}
	free(*(getSpecial()));

	specialPtr = *(getVars());
	while (specialPtr != NULL)
	{
		free(specialPtr->val);
		free(specialPtr->name);
		specialNext = specialPtr->next;
		free(specialPtr);
		specialPtr = specialNext;
	}

	while (aliasPtr != NULL)
	{
		free(aliasPtr->_v);
		free(aliasPtr->_na);
		aliasNext = aliasPtr->_n;
		free(aliasPtr);
		aliasPtr = aliasNext;
	}
}