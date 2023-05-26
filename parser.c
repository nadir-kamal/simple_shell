#include "shell.h"

/**
 * is_executable - Determines if a file is an executable command
 * @info: The info struct
 * @path: Path to the file
 *
 * Return: 1 if the file is executable, 0 otherwise
 */
int is_executable(info_t *info, char *path)
{
    struct stat st;

    (void)info;
    if (!path || stat(path, &st))
        return 0;

    if (st.st_mode & S_IFREG)
    {
        return 1;
    }
    return 0;
}

/**
 * duplicate_characters - Duplicates characters within a specified range
 * @pathstr: The PATH string
 * @start: Starting index
 * @stop: Stopping index
 *
 * Return: Pointer to the new buffer
 */
char *duplicate_characters(char *pathstr, int start, int stop)
{
    static char buf[1024];
    int k = 0;
    int i;

    for (i = start; i < stop; i++)
    {
        if (pathstr[i] != ':')
        {
            buf[k++] = pathstr[i];
        }
    }
    buf[k] = '\0';
    return buf;
}


/**
 * find_cmd_path - Finds the full path of a command within the PATH string
 * @info: The info struct
 * @pathstr: The PATH string
 * @cmd: The command to find
 *
 * Return: Full path of the command if found, otherwise NULL
 */
char *find_cmd_path(info_t *info, char *pathstr, char *cmd)
{
    int i = 0, curr_pos = 0;
    char *path;

    if (!pathstr)
        return NULL;

    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_executable(info, cmd))
            return cmd;
    }

    while (pathstr[i] != '\0')
    {
        if (pathstr[i] == ':')
        {
            path = duplicate_characters(pathstr, curr_pos, i);
            if (!*path)
            {
                _strcat(path, cmd);
            }
            else
            {
                _strcat(path, "/");
                _strcat(path, cmd);
            }

            if (is_executable(info, path))
                return path;

            curr_pos = i + 1;
        }
        i++;
    }

    path = duplicate_characters(pathstr, curr_pos, i);
    if (!*path)
    {
        _strcat(path, cmd);
    }
    else
    {
        _strcat(path, "/");
        _strcat(path, cmd);
    }

    if (is_executable(info, path))
        return path;

    return NULL;
}

