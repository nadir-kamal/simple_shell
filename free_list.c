#include "shell.h"

/**
 * free_list - frees the linked list
 * @head - linked list head
 */
void free_list(list_path *head)
{
	list_path *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
