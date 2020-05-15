#include "cs392_exec.h"

int get_arg_count(char *input) {
    int count = (input[0] != '\0' && input[0] != ' ') ? 1 : 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ' && input[i + 1] != ' ') {
            count++;
        }
    }
    return count;
}

char **get_args(char *input, int arg_count) {
    char **args = malloc(arg_count * sizeof(char));

    char *arg = strtok(input, " ");
    for (int i = 0; i < arg_count && arg != NULL; ++i) {
        // printf("%s\n", arg);
        args[i] = arg;
        arg = strtok(NULL, " ");
    }
    return args;
}

// int has_pipe(char **input) {
//     for (int i = 0; input[i] != '\0'; i++) {
//         if (input[i] == '|') {
//             return i;
//         }
//     }
//     return -1;
// }

void run_exec(char *input) {
    char **args;
    // int pipe;
    // if ((pipe = has_pipe(input)) == -1) {  // no pipe
    args = get_args(input, get_arg_count(input));
    pid_t pid, cpid;
    if ((pid = fork()) < 0) {
        perror("Error forking child process");
        return;
    } else if (pid > 0) {   // child process
        cpid = wait(NULL);  // wait for the child to finish
    } else {                // parent process
        // run the command
        if (execvp(args[0], args) < 0) {
            perror("Error!");
        }
    }
    // } else {  // contains pipe
    //     char *pipe_part = strtok(input, "|");
    //     args = get_args(pipe_part, get_arg_count(pipe_part));

    // }

    // clean_up(args, arg_count);
}

void clean_up(char **args, int arg_count) {
    for (int i = 0; i < arg_count - 1; i++) {
        printf("here");
        free(args[i]);
    }
    free(args);
}
