#include "shell.h"

/**
* get_environ - returns the string array copy of our environ
* @info: struct containing inputs passed between calls.
* Return: Always 0
*/
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}
return (info->environ);
}

/**
* _unsetenv - remove an environment variable
* @info: struct containing inputs passed between calls.
*  Return: 1 on delete, 0 otherwise
* @var: the string env var property
*/
int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t p = 0;
char *q;

if (!node || !var)
return (0);

while (node)
{
q = starts_with(node->str, var);
if (q && *q == '=')
{
info->env_changed = delete_node_at_index(&(info->env), p);
p = 0;
node = info->env;
continue;
}
node = node->next;
p++;
}
return (info->env_changed);
}

/**
* _setenv - Set a new environment variable or modify an existing one
* @info: struct containing inputs passed between calls.
* @var: string environ variable property
* @value: the string environ variable value
*  Return: Always 0
*/
int _setenv(info_t *info, char *var, char *value)
{
char *buff = NULL;
list_t *node;
char *q;

if (!var || !value)
return (0);

buff = malloc(_strlen(var) + _strlen(value) + 2);
if (!buff)
return (1);
_strcpy(buff, var);
_strcat(buff, "=");
_strcat(buff, value);
node = info->env;
while (node)
{
q = starts_with(node->str, var);
if (q && *q == '=')
{
free(node->str);
node->str = buff;
info->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(info->env), buff, 0);
free(buff);
info->env_changed = 1;
return (0);
}
