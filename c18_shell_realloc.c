#include "shell.h"

/**
* _memset - fills memory with a constant byte
* @s: the pointer to the memory area
* @b: the byte to fill *s with
* @n: the amount of bytes to be filled
*
* Return: (s) a pointer to the memory area s
*/

char *_memset(char *s, char b, unsigned int n)
{
unsigned int k;

/* Fill the memory area with the specified byte */
for (k = 0; k < n; k++)
s[k] = b;
return (s);
}

/**
* ffree - frees a string of strings
* @pp: string of strings
*/

void ffree(char **pp)
{
char **a = pp;

if (!pp)
return;

/* Free each string in the string of strings */
while (*pp)
free(*pp++);
free(a);
}

/**
* _realloc - reallocate memory block
* @ptr: pointer to the previous allocated block
* @old_size: The byte size of the previous block
* @new_size: The byte size of the new block
*
* Return: pointer to the old block name.
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return (malloc(new_size));

if (!new_size)
return (free(ptr), NULL);

if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (!p)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;

/* Copy the contents from the old block to the new block */
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];

free(ptr);
return (p);
}
