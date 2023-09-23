#include "shell.h"

/**
* interactive - Checks if the shell is in interactive mode.
* @info: Pointer to the info struct.
*
* Return: 1 if in interactive mode, 0 otherwise.
*/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - Checks if a character is a delimiter.
* @c: The character to check.
* @delim: The delimiter string.
*
* Return: 1 if the character is a delimiter, 0 otherwise.
*/
int is_delim(char c, char *delim)
{
while (*delim)
{
if (*delim++ == c)
return (1);
}
return (0);
}

/**
* _isalpha - Checks for an alphabetic character.
* @c: The character to check.
*
* Return: 1 if the character is alphabetic, 0 otherwise.
*/
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
* _atoi - Converts a string to an integer.
* @s: The string to be converted.
*
* Return: The converted integer, or 0 if no numbers in the string.
*/
int _atoi(char *s)
{
int i, j = 1, k = 0, outcome;
unsigned int res = 0;

for (i = 0; s[i] != '\0' && k != 2; i++)
{
if (s[i] == '-')  /* Check if the current character is a minus sign */
j *= -1;     /* Update the sign multiplier */

if (s[i] >= '0' && s[i] <= '9')/* Check if the current character is a digit */
{
k = 1;/*Set the flag indicating at least one digit has been encountered */
res *= 10;/* Multiply the result by 10 to shift digits to the left */
res += (s[i] - '0');  /* Add the current digit to the result */
}
else if (k == 1)
k = 2;/* Set the flag indicating digits have been encountered and then ended */
}

if (j == -1)
outcome = -res;/* Apply the sign multiplier to the result if necessary */
else
outcome = res;

return (outcome);
}
