/*******************************************************************************
 * Name        : sort.c
 * Author      : Robert Schaedler III
 * Date        : Mar. 25, 2020
 * Description : Implemenatation of sort.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include "sort.h"

int num_lines(char *ptr) {
    int count = 0;
    while (*ptr != '\0') {
        if (*ptr == '\n') {
            count++;
        }
        ptr++;
    }
    return count;
}

void sort(FILE *input_file, FILE *output_file) {
    fseek(input_file, 0, SEEK_END);
    size_t size = ftell(input_file);

    char *ptr = malloc(size);

    fseek(input_file, 0, SEEK_SET);
    fread(ptr, 1, size, input_file);

    int arr_size = num_lines(ptr);
    int *arr = malloc(arr_size * sizeof(int));

    int buffer = 0, line_count = 0;

    for (; *ptr != '\0'; ptr++) {  // read lines to int[]
        if (*ptr == '\n') {
            arr[line_count++] = buffer;
            buffer = 0;
        } else {
            buffer = (buffer * 10) + (*ptr - '0');
        }
    }

    heap_sort(arr, arr_size);

    for (int i = arr_size - 1; i >= 0; i--) {  // convert sorted data to char[]
        int num = arr[i];
        *--ptr = '\n';
        do {
            *--ptr = (num % 10) + '0';
            num /= 10;
        } while (num != 0);

        if (arr[i] < 0) {  // handle negative numbers
            *--ptr = '-';
        }
    }

    fwrite(ptr, 1, size, output_file);
}

void heap_sort(int *arr, int size) {
    // create a max max heap
    for (int i = (size / 2) - 1; i >= 0; i--) {
        percolate_down(arr, i, size);
    }

    // sort by removing elements from the 'top' of the heap
    for (int end = size - 1; end > 0; end--) {
        swap(arr, 0, end);
        percolate_down(arr, 0, end);
    }
}

void percolate_down(int *arr, int i, int end) {
    int parent = i,
        left = (2 * parent) + 1,
        right = (2 * parent) + 2;

    while (right <= end) {
        int maxChild = left;
        if (right < end && arr[right] > arr[left]) {
            maxChild = right;
        }

        if (arr[parent] > arr[maxChild]) {
            break;
        }

        swap(arr, parent, maxChild);
        parent = maxChild;
        left = (2 * parent) + 1;
        right = (2 * parent) + 2;
    }
}

void swap(int *arr, int i, int j) {
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <inputfile> <outputfile>\n", argv[0]);
        return 1;
    }

    FILE *input_file, *output_file;

    if (!(input_file = fopen(argv[1], "r"))) {  // file does not exist
        fprintf(stderr, "%s: No such file or directory\n", argv[1]);
        return 1;
    }

    if ((output_file = fopen(argv[2], "r"))) {  // output file already exists
        fclose(output_file);
        fprintf(stderr, "%s: File already exists\n", argv[2]);
        return 1;
    }

    output_file = fopen(argv[2], "w");

    sort(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}