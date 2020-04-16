/*******************************************************************************
 * Name        : cs392_fork.c
 * Author      : Robert Schaedler III
 * Date        : Apr. 16, 2020
 * Description : Using fork() to create a child process.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    int pid;
    if ((pid = fork()) == 0) {
        printf("CHILD PROCESS\n------------------------\n\tChild  ID: %u\n------------------------\n", getpid());
    } else { /* avoids error checking*/
        printf("PARENT PROCESS\n------------------------\n\tParent ID: %u\n\tChild  ID: %u\n------------------------\n", getpid(), pid);
    }
}