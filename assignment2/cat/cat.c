/*******************************************************************************
 * Name        : cat.c
 * Author      : Robert Schaedler III
 * Date        : Mar. 25, 2020
 * Description : Implemenatation of cat.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 
 * Prints the contents of a file to the standard output.
 */
void cat(FILE *fp) {
    // Get the size of the file
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);

    // Read the file into a ptr
    char *ptr = malloc(size);
    fseek(fp, 0, SEEK_SET);
    fread(ptr, 1, size, fp);

    // Write ptr to std out
    fwrite(ptr, 1, size, stdout);
    free(ptr);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }

    FILE *fp;
    if (!(fp = fopen(argv[1], "r"))) {  // file does not exist
        fprintf(stderr, "%s: No such file or directory\n", argv[1]);
        return 1;
    }

    cat(fp);
    return 0;
}