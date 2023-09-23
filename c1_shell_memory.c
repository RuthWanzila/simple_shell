#include "shell.h"

/**
* bfree - frees a pointer and NULLs the address
* @ptr: address of the pointer to free
*
* Return: 1 if freed, otherwise 0.
*/

int bfree(void **ptr)
{
if (ptr && *ptr)
{
/* Free the memory and set the pointer to NULL */
free(*ptr);
*ptr = NULL;
/* return statement for if */
return (1);
}
/* final return statement */
return (0);
}
