#include "cs392_signal.h"

void handler(int sig, siginfo_t *siginfo, void *context) {
    if (sig == SIGINT || sig == SIGTSTP) {
        printf("%d\n", sig);
        exit(0);
    }
}

void handle_signals() {
    struct sigaction act;

    memset(&act, '\0', sizeof(act));

    act.sa_sigaction = &handler;
    act.sa_flags = SA_SIGINFO;

    if ((sigaction(SIGTSTP, &act, NULL) < 0) || (sigaction(SIGINT, &act, NULL) < 0)) {
        perror("Sigaction error.\n");
    }
}