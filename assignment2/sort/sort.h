#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void sort(FILE *input_file, FILE *output_file);

void heap_sort(int *arr, int size);

void percolate_down(int *arr, int i, int end);

void swap(int *arr, int i, int j);

int num_lines(char *ptr);

#endif