#include "shell.h"

/**
* main - Entry point of the shell program
* @ac: Argument count
* @av: Argument vector
*
* Return: 0 on success, 1 on error
*/
int main(int ac, char **av)
{
info_t infos[] = {INFO_INIT};   /* Array of info_t structs */
int fd = 2;                    /* File descriptor for error output */

asm("mov %1, %0\n\t"
"add $3, %0"
: "=r"(fd)
: "r"(fd));

if (ac == 2)
{
fd = open(av[1], O_RDONLY);/* open with read only permission*/
if (fd == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputs(av[0]);
_eputs(": 0: Can't open ");
_eputs(av[1]);
_eputchar('\n');
_eputchar(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
infos->readfd = fd;
}

populate_env_list(infos);  /* Populate environment list */
read_history(infos);       /* Read command history */
hsh(infos, av);            /* Run the shell loop */
return (EXIT_SUCCESS);
}
