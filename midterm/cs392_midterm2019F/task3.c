/*******************************************************************************
 * Name        : task3.c
 * Author      : Robert Schaedler III
 * Date        : Mar. 7, 2020
 * Description : Midterm task3.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cs392_file_insert(char *path, int index, char *str) {
    FILE *fp;
    fp = fopen(path, "r+");

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    char *ptr = malloc(size);
    fseek(fp, 0, SEEK_SET);
    fread(ptr, 1, size, fp);
    fclose(fp);

    fp = fopen(path, "w");
    fwrite(ptr, 1, index, fp);
    fwrite(str, 1, strlen(str), fp);
    fwrite(ptr + index, 1, size - index, fp);
    fclose(fp);

    return 0;
}

int main(int argc, char **argv) {
    cs392_file_insert("cs392_task3_tmp.txt", 10, "@cs392 data inserted@");

    return 0;
}
