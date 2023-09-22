#include "main.h"
/**
* main - entry point of program
* @ac: count
* @argv: vector
* Return: always 0
*/
int main(int ac, char **argv)
{
char *printout = "shell$ ", *X = NULL, *X1 = NULL;
size_t n = 0;
ssize_t ncharacters;
const char *Y = " \n";
int tkn_no = 0, i;
char *tkn;
(void)ac;
while (1)
{
/* print the prompt and get output from the user*/
printf("%s", printout);
ncharacters = getline(&X, &n, stdin);
if (ncharacters == -1)
/* exit shell with CTRL+D */
printf("Exiting shell...\n");
return (-1);
/* memory allocation to the line pointer and incase of an error */
X1 = malloc(sizeof(char) * ncharacters);
if (X1 == NULL)
perror("tsh: memory allocation error");
return (-1);
tkn = strtok(X, Y);
while (tkn != NULL)
tkn_no++;
tkn = strtok(NULL, Y);
tkn_no++;
/* memory allocation and string splitting*/
argv = malloc(sizeof(char *) * tkn_no);
tkn = strtok(X1, Y);
for (i = 0; tkn != NULL; i++)
argv[i] = malloc(sizeof(char) * strlen(tkn));
/* strings copying and execute command */
strcpy(argv[i], tkn);
tkn = strtok(NULL, Y);
argv[i] = NULL;
execmd(argv);
}
free(X1);
free(X);
return (0);
}
