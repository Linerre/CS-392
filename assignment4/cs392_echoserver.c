/*******************************************************************************
 * Name        : cs392_echoserver.c
 * Author      : Robert Schaedler III
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

#include "cs392_log.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        perror("Usage: ./cs392_echoserver <SERVER PORT>");
        exit(EXIT_FAILURE);
    }

    fd_set active_fd_set, read_fd_set;
    struct sockaddr_in echo_server, echo_client;

    int s;
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: could not create socket");
        exit(EXIT_FAILURE);
    }

    memset(&echo_server, 0, sizeof(echo_server));
    echo_server.sin_family = AF_INET;
    echo_server.sin_addr.s_addr = htonl(INADDR_ANY);
    echo_server.sin_port = htons(atoi(argv[1]));

    if (bind(s, (struct sockaddr *)&echo_server, sizeof(echo_server)) < 0 || listen(s, 1) < 0) {
        perror("Error!");
        exit(EXIT_FAILURE);
    }

    FD_ZERO(&active_fd_set);
    FD_SET(s, &active_fd_set);

    int c, n;
    char buff[1024];
    while (1) {
        read_fd_set = active_fd_set;

        if (select(FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0) {
            perror("Error: could not select");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < FD_SETSIZE; ++i) {
            if (FD_ISSET(i, &read_fd_set)) {
                if (i == s) {
                    n = sizeof(echo_client);
                    if ((c = accept(s, (struct sockaddr *)&echo_client, &n)) < 0) {
                        perror("Error");
                        exit(EXIT_FAILURE);
                    }

                    FD_SET(c, &active_fd_set);
                } else {
                    if (recv(i, buff, 1024, 0) < 0 || send(i, buff, 1023, 0) < 0 || close(i) < 0) {
                        perror("Error");
                        exit(EXIT_FAILURE);
                    }
                    cs392_log(buff);
                    printf("%s\n", buff);

                    FD_CLR(i, &active_fd_set);
                }
            }
        }
    }

    return 0;
}