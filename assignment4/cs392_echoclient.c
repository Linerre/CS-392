/*******************************************************************************
 * Name        : cs392_echoclient.c
 * Author      : Robert Schaedler III
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        perror("Usage: ./cs392_echoclient <SERVER ADDRESS> <SERVER PORT>");
        exit(EXIT_FAILURE);
    }

    char buff[1024];
    struct sockaddr_in echoserver;

    int s;
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: Socket");
        exit(EXIT_FAILURE);
    }

    memset(&echoserver, 0, sizeof(echoserver));
    echoserver.sin_family = AF_INET;
    echoserver.sin_addr.s_addr = inet_addr(argv[1]);
    echoserver.sin_port = htons(atoi(argv[2]));

    if (connect(s, (struct sockaddr *)&echoserver, sizeof(echoserver)) == -1) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    fgets(buff, 1024, stdin);

    if (send(s, buff, 1023, 0) < 0) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }
    printf("Sent: %s\n", buff);

    if (recv(s, buff, 1023, 0) < 0) {
        perror("Error recvieving message");
        exit(EXIT_FAILURE);
    }
    printf("Recieved: %s\n", buff);

    if (close(s) < 0) {
        perror("Error closing socket");
        exit(EXIT_FAILURE);
    }

    return 0;
}