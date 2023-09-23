#include "shell.h"

/**
* _strlen - returns the length of a string
* @s: the string whose length to check
*
* Return: integer length of string
*/

int _strlen(char *s)
{
int k = 0;

if (!s)
return (0);

/* Calculate the length of the string */
while (*s++)
k++;
return (k);
}

/**
* _strcmp - performs lexicographic comparison of two strings.
* @s1: the first string
* @s2: the second string
*
* Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
*/

int _strcmp(char *s1, char *s2)
{
/* Compare characters of s1 and s2 until a difference is found */
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}

/* If both strings have reached the end, they are equal */
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
* starts_with - checks if haystack starts with needle
* @haystack: string to search
* @needle: the substring to find
*
* Return: address of the next character of haystack or NULL
*/

char *starts_with(const char *haystack, const char *needle)
{
/* Check if the characters of needle match the characters of haystack */
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
* _strcat - concatenates two strings
* @dest: the destination buffer
* @src: the source buffer
*
* Return: pointer to destination buffer
*/

char *_strcat(char *dest, char *src)
{
char *ret = dest;

/* Find the end of the destination string */
while (*dest)
dest++;

/*Copy the characters from source string to the end of the destination string*/
while (*src)
*dest++ = *src++;
*dest = *src;

return (ret);
}
