#include "cs392_log.h"

/**
 * Maintains a log of the commands entered in the shell.
 */
void log_command(char *command) {
    FILE *fp;
    if (!(fp = fopen("cs392_shell.log", "a"))) {
        fprintf(stderr, "Could not open log file\n");
    } else {
        fprintf(fp, "%s\n", command);
    }
    fclose(fp);
}