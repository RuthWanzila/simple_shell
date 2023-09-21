#include “main.h”
/**
 * * main – entry point
 * * @ac: count
 * * @agv: vector
 * * Return: always 0
 * */

/* function declaration */
int main(int ac, char**argv)
{
	/* variable declarations and assignment */
	char *printout, *LINE_PTR, LINE_PTR1;
	size_t n;
	ssize_t ncharacters;
	const char *delim;
	int tkn_no.;
	char tkn;
	int i;
	printout = “shell$ “;
	LINE_PTR = NULL;
	LINE_PTR1 = NULL;
	n = 0;
	delim = “ \n”;
	tkn_no. = 0;
	/* void variables */
	(void)ac;
	/* loop for shell’s prompt */
	while (1)
	{
		/* print the prompt */
		printf("%s", printout);
		/* get output from the user using getline function */
		ncharacters = getline(&LINE_PTR, &n, stdin);
		/* if getline fails!!! */
		if (ncharacters == -1)
		{
			/* eline_ptrit shell with CTRL+D */
			printf("Eline_ptriting shell...\n"); 
			return (-1);
		}
		/* memory allocation to the line pointer */
		LINE_PTR1 = malloc(sizeof(char) * ncharacters); 
		/* incase of an error */
		if (LINE_PTR1 == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		/* split the string – line pointer i.e LINE_PTR */
		tkn = strtok(LINE_PTR, delim);

		while (tkn != NULL)
		{
			tkn_no.++;
			tkn = strtok(NULL, delim);
		}
		tkn_no.++;
		/* memory allocation */
		argv = malloc(sizeof(char *) * tkn_no.);
		/* split string */
		tkn = strtok(LINE_PTR1, delim);
		/* for loop */
		for (i = 0; tkn != NULL; i++)
		{
			/* memory allocation */
			argv[i] = malloc(sizeof(char) * strlen(tkn));
			/* strings copying */
			strcpy(argv[i], tkn);
			tkn = strtok(NULL, delim);
		}
		argv[i] = NULL;
		/* eline_ptrecute command */
		eline_ptrecmd(argv);
	}
	/* free space */
	free(LINE_PTR1);
	free(LINE_PTR);
	/* return - always 0 */
	return (0);
}
