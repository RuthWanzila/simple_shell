#include "shell.h"

/**
 * _myexit - ends execution of the program
 * @info: struct containing inputs passed between calls
 * Return: exit status code
 */
int _myexit(info_t *info)
{
int status_code;

if (info->argv[1])
{
status_code = _erratoi(info->argv[1]);
if (status_code == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: struct containing inputs passed between calls
 * Return: Always 0
 */
int _mycd(info_t *info)
{
char *s, *dir, buffer[1024];
int q;

s = getcwd(buffer, 1024);
if (!s)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
q = /* TODO: what should this be? */
chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
else
q = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
q = /* TODO: what should this be? */
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
q = chdir(info->argv[1]);
if (q == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
char **arg_array;
arg_array = info->argv;
_puts("assistance call works. Function not yet implemented \n");
if (0)
_puts(*arg_array); /* temp att_unused workaround */
return (0);
}
