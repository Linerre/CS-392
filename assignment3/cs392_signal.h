#ifndef CS392_SIGNAL
#define CS392_SIGNAL

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void handler(int sig, siginfo_t *siginfo, void *context);
void handle_signals();

#endif