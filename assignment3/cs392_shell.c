/*******************************************************************************
 * Name        : cs392_shell.c
 * Author      : Robert Schaedler III
 * Date        : Apr. 26, 2020
 * Description : CS 392 shell.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <stdio.h>
#include <string.h>

#include "cs392_exec.h"
#include "cs392_log.h"
#include "cs392_signal.h"

int main(int argc, char** argv) {
    while (1) {
        handle_signals();

        char buffer[256];
        printf("cs392_shell $: ");
        fflush(stdout);

        int index;
        if ((index = read(0, buffer, 99)) < 0) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("Invlid input.\n");
                exit(0);
            }
        }

        buffer[index - 1] = '\0';

        if (strcmp(buffer, "exit") == 0) break;

        log_command(buffer);
        run_exec(buffer);
    }
}