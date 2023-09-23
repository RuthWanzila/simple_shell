#include "shell.h"

/**
* _myenv - Prints the current environment.
* @info: Struct containing inputs passed between calls.
*
* Return: Always 0.
*/
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
* _getenv - Gets the value of an environment variable.
* @info: Struct containing inputs passed between calls.
* @name: Name of the environment variable.
*
* Return: The value of the variable, or NULL if it doesn't exist.
*/
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *value;

while (node)
{
value = starts_with(node->str, name);
if (value && *value)
return (value);
node = node->next;
}
return (NULL);
}

/**
* _mysetenv - Sets a new environment variable or alters an existing one.
* @info: Struct containing inputs passed between calls.
*
* Return: Always 0.
*/
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Argument count mismatch\n");
return (1);
}

/* Call the _setenv function to set or modify the environment variable */
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
* _myunsetenv - Removes an environment variable.
* @info: Struct containing inputs passed between calls.
*
* Return: Always 0.
*/
int _myunsetenv(info_t *info)
{
int k;

if (info->argc == 1)
{
_eputs("Insufficient arguments.\n");
return (1);
}

/* Loop through and call _unsetenv to remove each specified variable */
for (k = 1; k <= info->argc; k++)
_unsetenv(info, info->argv[k]);

return (0);
}

/**
* populate_env_list - Populates the list with current environment variables.
* @info: Struct containing inputs passed between calls.
*
* Return: Always 0.
*/
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t k;

/* Iterate through the environ array to retrieve environment variables */
for (k = 0; environ[k]; k++)
add_node_end(&node, environ[k], 0);

/* Assign the populated environment list to the info struct */
info->env = node;
return (0);
}
