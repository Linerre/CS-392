#include "cs392_log.h"

void cs392_log(char *buff) {
    FILE *fp;
    if ((fp = fopen("cs392_socket.log", "a+")) == NULL) {  // Checking the error for the fopen
        perror("Error: opening 'cs392_socket.log'");
        return;
    } else {
        fprintf(fp, "%s", buff);
        fclose(fp);
    }
}