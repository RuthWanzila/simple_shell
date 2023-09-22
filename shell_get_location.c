#include "main.h"
/**
 * get_location - Find the full path of a given cmd in the PATH directories
 * @cmd: The cmd to search for
 * Return: The full path of the cmd if found, NULL otherwise
 */
char *get_location(char *cmd)
{
char *path, *duplicate_path, *path_tkn, *fpath;
int size_cmd, dir_length;
struct stat buffer;
/* Get the value of the PATH environment variable */
path = getenv("PATH");
if (path)
/* Duplicate the path string and get length of the command */
duplicate_path = strdup(path);
size_cmd = strlen(cmd);
/* Break down the path into individual directories */
path_tkn = strtok(duplicate_path, ":");
while (path_tkn != NULL)
/* Get the length of the directory */
dir_length = strlen(path_tkn);
/* Allocate memory for the file path */
fpath = malloc(size_cmd + dir_length + 2);
/* Build the complete path for the cmd */
strcpy(fpath, path_tkn);
strcat(fpath, "/");
strcat(fpath, cmd);
strcat(fpath, "\0");
/* Check if the file path exists */
if (stat(fpath, &buffer) == 0)
{
free(duplicate_path);
return (fpath);
}
else
/* Free the file path memory and move to the next directory */
free(fpath);
path_tkn = strtok(NULL, ":");
/* Free the path copy memory */
free(duplicate_path);
/* Check if the cmd itself is a valid file path */
if (stat(cmd, &buffer) == 0)
return (cmd);
/* No valid file path found */
return (NULL);
/* PATH environment variable not found */
return (NULL);
}
