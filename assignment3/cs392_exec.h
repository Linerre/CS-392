#ifndef CS392_EXEC
#define CS392_EXEC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void clean_up(char **command, int arg_count);
int get_arg_count(char *input);
char **get_args(char *input, int arg_count);
void run_exec(char *command);

#endif