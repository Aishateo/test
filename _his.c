#include "shell.h"
#include "_his.h"

/**
 * getHistoryList - gets the history list
 *
 * Return: 0 upon success
 */
HistList **getHistoryList()
{
	static HistList *historyList;

	return (&historyList);
}

/**
 * setHistory - set history and value
 *
 * @command: command
 * Return: 0 upon success
 */
int setHistory(char *command)
{
	HistList **historyListRoot = getHistoryList();
	HistList *historyList = *historyListRoot;
	HistList *ptr = historyList, *new;

	if (historyList == NULL)
	{
		new = malloc(sizeof(HistList));
		if (new == NULL)
			return (-1);

		new->_cmd = my_strdup(command);
		new->nxt = NULL;
		*historyListRoot = new;
		return (0);
	}

	while (ptr->nxt != NULL)
		ptr = ptr->nxt;

	new = malloc(sizeof(HistList));
	if (new == NULL)
		return (-1);

	new->_cmd = my_strdup(command);
	new->nxt = NULL;
	ptr->nxt = new;
	return (0);
}

/**
 * printHistory - prints all elements of history list
 *
 * Return: number of elements
 */
int printHistory(void)
{
	int i, len, numlen;
	char *s, *num;

	HistList **historyListRoot = getHistoryList();
	HistList *history = *historyListRoot;

	i = 0;
	while (history != NULL)
	{
		len = my_strlen(history->_cmd);
		s = history->_cmd;
		num = intToString(i);
		numlen = my_strlen(num);
		write(1, num, numlen);
		my_putchar(' ');
		write(1, s, len);
		history = history->nxt;
		i++;
	}
	return (i);
}

/**
 * exitHistory - exit history and copy to file
 *
 * Return: int
 */
int exitHistory(void)
{
	int fd, len;
	char *file = ".simple_shell_history";
	char *s;

	HistList **historyListRoot = getHistoryList();
	HistList *historyList = *historyListRoot;
	HistList *ptr = historyList;

	fd = open(file, O_CREAT | O_RDWR, 0600);
	if (fd == -1)
		return (-1);

	while (historyList != NULL)
	{
		ptr = historyList->nxt;
		s = historyList->_cmd;
		len = my_strlen(s);
		write(fd, s, len);
		free(historyList->_cmd);
		free(historyList);
		historyList = ptr;
	}

	close(fd);
	return (1);
}