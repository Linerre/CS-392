#include <stdio.h>
int cs392_sum(int, int);

// creates the library object
// gcc -O0 -c cs392_sum.c

// creates the shared library
// gcc -shared -o libcs392_sum.so cs392_sum.o

// compiles the main program
// gcc -O0 -c main.c

// links the library and main
// gcc -O0 -o main main.o cs392_sum.o

int main() {
    int a = 2;
    int b = 3;
    printf("sum: %d\n", cs392_sum(a, b));
}