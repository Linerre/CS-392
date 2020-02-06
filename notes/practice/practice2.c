#include <stdio.h>

int main(int arc, char **argv) {
    // [1] Create an integer variable
    int x;

    // [2] Assign a constant value to that variable(whatever value you want)
    x = 1;
    printf("x: %d\n", x);

    // [3] Create an integer pointer
    int *p;

    // [4] Make that pointer point to the integer variable
    p = &x;

    // [5] Change that integer variable to another constant value by dereferencing the pointer created in[3](instead of directly changing that integer variable)
    *p = 2;

    // [6] Print the integer variable again.
    printf("x: %d\n", x);
}