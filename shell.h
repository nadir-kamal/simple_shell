#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

extern char **environ;

/**
 *sturct path - linked list containing path directories
 *@dir - directory in the path
 *@p - pointer to the next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *next;
} list_path;

list_path *create_list(char *str);
list_path *add_node_end(list_path **head, char *str);
list_path *link_path(char *path);
char *_which(char *file_name, list_path *head);
void free_list(list_path *head);

/**
 * struct mybuild - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

void _feof(ssize_t nread, char *line);
void sig_handler(int sig_num);
void _isatty(void);
void *_realloc(void *ptr, size_t size);
ssize_t _getline(char **line, size_t *n);
void execute(char **arg);
char **string_parse(char *line);
char *_strtok(char *line, const char *delim);
int _putchar(char c);
int _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_getenv(const char *name);
int _atoi(char *s);
void exitt(char **arg);
void env(char **arg);
void _setenv(char **arg);
void _unsetenv(char **arg);
void _cd(char **arg);
void(*checkbuild(char **arg))(char **arg);

#endif
