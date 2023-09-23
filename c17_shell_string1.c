#include "shell.h"

/**
* _strcpy - copies a string
* @dest: the destination
* @src: the source
*
* Return: pointer to destination
*/

char *_strcpy(char *dest, char *src)
{
int k = 0;

if (dest == src || src == 0)
return (dest);

/* Copy characters from source to destination */
while (src[k])
{
dest[k] = src[k];
k++;
}
dest[k] = '\0';
return (dest);
}

/**
* _strdup - duplicates a string
* @str: the string to duplicate
*
* Return: pointer to the duplicated string
*/

char *_strdup(const char *str)
{
int length = 0;
char *ret;

if (str == NULL)
return (NULL);

/* Calculate the length of the input string */
while (*str++)
length++;

/* Allocate memory for the duplicated string */
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);

/* Copy characters from the input string in reverse order */
for (length++; length--;)
ret[length] = *--str;

return (ret);
}

/**
* _puts - prints an input string
* @str: the string to be printed
*
* Return: Nothing
*/

void _puts(char *str)
{
int k = 0;

if (!str)
return;

/* Print each character in the string */
while (str[k] != '\0')
{
_putchar(str[k]);
k++;
}
}

/**
* _putchar - writes the character c to stdout
* @c: character to print
*
* Return: On success 1.
*         On error, -1 is returned, and errno is set appropriately.
*/

int _putchar(char c)
{
static int k;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
{
/* Flush the buffer and write to stdout */
write(1, buf, k);
k = 0;
}
if (c != BUF_FLUSH)
buf[k++] = c;

return (1);
}
