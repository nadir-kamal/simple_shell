#include "shell.h"

/**create_list - creates a node 
 * @str - dir
 *return : node on success
 */
list_path *create_list(char *str)
{
	list_path *head = malloc(sizeof(list_path));

	if (head == NULL)
	{
		return (NULL);
	}
	head->dir = str;
	head->next = NULL; 

	return (head);
}
/**add_node - function that adds a node to the end of the list
 *@head - struct list_path
 *@str - string
 *return - head on success
 */
list_path *add_node(list_path **head, char *str)
{
	list_path *new = malloc(sizeof(list_path));
	list_path *last;
	new->dir = str;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (NULL);
	}
	last = *head;
	while (last->next != NULL)
	{
		last->next = last;
	}
	last->next = new;
	return (last);
}
/**link_path - creates a list of the path directories
 *@path
 *return : head
 */
list_path *link_path(char *path)
{
	list_path *head;
	char *path_B, *token;

	path_B = _strdup(path);
	token = _strtok(path_B, ":");
	head = create_list(token);

	while (token)
	{
		head = add_node(&head, token);
		token = _strtok(NULL, ":");
	}
	return (head);
}
/**_which - checks for a command in path
 *@file_name - pointer to the command name
 *@head - linked list of the path 
 *return - directory name on success / null on failure
 */
char *_which(char *file_name, list_path *head)
{
	struct stat st;
	char *path;

	list_path *list = head;

	while (list)
	{
		_strcat(list->dir, "/");
		path = _strcat(list->dir, file_name);

		if (!stat(path, &st))
		{
			return (path);
		}
		free(path);
		list = list->next;
	}
	return (NULL);
}
/**_getenv - function to search for enviroment varibles by name
 *@name - specefied name
 *return : its value
 */
char *_getenv(const char *name)
{
	char *var, *val, *token;
	int i, j;

	if (!name)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		j = 0;
		var = _strdup(environ[i]);
		token = _strtok(var, "=");
		val = _strtok(NULL, "=");

		if (var && val)
		{
			while (name[j])
			{
				if (name[j] != token[j])
					break;
				j++;
			}
			if (name[j] == '\0')
			{
				free(var);
				return (val);
			}
		}
		free(var);
	}
	return (NULL);
}

