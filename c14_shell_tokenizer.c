#include "shell.h"

/**
* **strtow - splits a string into words. Repeat delimiters are ignored
* @str: the input string
* @d: the delimeter string
* Return: a pointer to an array of strings, or NULL on failure
*/

char **strtow(char *str, char *d)
{
int i, j, k, m, countwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (i = 0; str[i] != '\0'; i++)
if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
countwords++;

if (countwords == 0)
return (NULL);
s = malloc((1 + countwords) *sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < countwords; j++)
{
while (is_delim(str[i], d))
i++;
k = 0;
while (!is_delim(str[i + k], d) && str[i + k])
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = str[i++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}

/**
* **strtow2 - splits a string into words
* @str: input string
* @d: delimeter
* Return: a pointer to an array of strings, or NULL on failure
*/

char **strtow2(char *str, char d)
{
int i, j, k, p, countwords = 0;
char **s;
/* if conditional statement */
if (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
if ((str[i] != d && str[i + 1] == d) ||
(str[i] != d && !str[i + 1]) || str[i + 1] == d)
countwords++;
if (countwords == 0)
return (NULL);
s = malloc((1 + countwords) *sizeof(char *));
if (!s)
return (NULL);
/* loop for the program */
for (i = 0, j = 0; j < countwords; j++)
{
while (str[i] == d && str[i] != d)
i++;
k = 0;
while (str[i + k] != d && str[i + k] && str[i + k] != d)
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (p = 0; p < k; p++)
s[j][p] = str[i++];
s[j][p] = 0;
}
s[j] = NULL;
/* return statement */
return (s);
}
