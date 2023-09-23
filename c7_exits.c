#include "shell.h"

/**
**_strncpy - copies a string
*@dest: the destination string to be copied to
*@src: the source string
*@n: the amount of characters to be copied
*Return: the concatenated string
*/
char *_strncpy(char *dest, char *src, int n)
{
int x, y;
char *p = dest;
x = 0;
while (src[x] != '\0' && x < n - 1)
{
dest[x] = src[x];
x++;
}
if (x < n)
{
y = x;
while (y < n)
{
dest[y] = '\0';
y++;
}
}
return (p);
}

/**
**_strncat - concatenates two strings
*@dest: the first string
*@src: the second string
*@n: the amount of bytes to be maximally used
*Return: the concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
int x, y;
char *p = dest;

x = 0;
y = 0;
while (dest[x] != '\0')
x++;
while (src[y] != '\0' && y < n)
{
dest[x] = src[y];
x++;
y++;
}
if (y < n)
dest[x] = '\0';
return (p);
}

/**
**_strchr - locates a character in a string
*@p: string to be checked
*@c: the character to look for
*Return: a pointer to the memory area p
*/
char *_strchr(char *p, char c)
{
do {
if (*p == c)
return (p);
} while (*p++ != '\0');

return (NULL);
}
