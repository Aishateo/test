#ifndef HISTORY_H
#define HISTORY_H

/**
 * struct HistList - singly linked list
 *
 * @_cmd: command line entered
 * @nxt: pointer to the next node
 * Description: singly linked list node structure for History 
 * for Holberton project
 */

typedef struct HistList
{
	char *_cmd;
	struct HistList *nxt;
} HistList;

#endif