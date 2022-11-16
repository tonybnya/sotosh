#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int sotosh_execute(char **args);
int sotosh_launch(char **args);
char *sotosh_readline(void);
char **sotosh_splitline(char *line);

int sotosh_cd(char **args);
int sotosh_help(char **args);
int sotosh_exit(char **args);
int sotosh_num_builtins(void);

#endif /* MAIN_H */
