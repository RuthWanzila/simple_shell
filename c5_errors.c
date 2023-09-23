#include "shell.h"

/**
* _eputs - prints an input string
* @str: the input string to be printed
*
* Return: void
*/
void _eputs(char *str)
{
int i = 0;
if (!str)
return;
while (str[i] != '\0')
{
_eputchar(str[i]);
i++;
}
}
/**
* _eputchar - writes the character c to stderr
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _eputchar(char c)
{
static int i;
static char buff[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buff, i);
i = 0;
}
if (c != BUF_FLUSH)
buff[i++] = c;
return (1);
}

/**
* _putfd - writes the character c to given file descriptor.
* @c: character to print.
* @fd: file descriptor to write to.
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putfd(char c, int fd)
{
static int i;
static char buff[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buff, i);
i = 0;
}
if (c != BUF_FLUSH)
buff[i++] = c;
return (1);
}

/**
* _putsfd - prints an input string
* @str: input string to be printed
* @fd: file descriptor to write to
*
* Return: the number of chars put
*/
int _putsfd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}