#ifndef MAIN_H
#define MAIN_H

/* header files inclusion */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
/* function declaration */
void execmd(char **argv);
char *get_location(char *cmd);

#endif /* MAIN_H */
