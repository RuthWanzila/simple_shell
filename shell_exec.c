#include "main.h"
/**
 * * execmd - execute cmd function
 * *@argv: argument vector
 * *Return: nothing!!
 * */

/* function declaration */
void execmd(char **argv)
{
/* variable declaration and definition/assignment */
	char *cmd, *init_cmd;
	cmd = NULL;
	init_cmd = NULL;
/* conditional statement for the argument vector of the function*/
	if (argv)
	{
/* get the command */
		cmd = argv[0];
/* get the actual location of the command */
		init_cmd = get_location(cmd);
/* what happens when you use the execute cmd(execve) a*/
		if (execve(init_cmd, argv, NULL) == -1)
		{
/* for an error */
			perror("Error:");
		}
	}
/* return = void */
}
