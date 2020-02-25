# I/O Part 1

Input and output in systems programming part 1.

## Intro

```C
// hello.c

#include<stdio.h>
int main(int argc, char** argv) {
    printf("Hello World\n");
    return 1;
}
``` 

Compile with:
```bash
gcc -O0 hello.c -o hello
```

`-O0` disables optimization by the compiler. This helps with debugging.

## Header files

To successfully print a string, the header file `stdio.h` must be included. Inside the header file, the prototype of the `printf()` function is defined. This is all that is needed for compilation. *The code will be discussed in later lectures.*

Each header file contains one or more functions, definitiions, and macros. **Try to avoid defining variables or functions inside.**

### Creating a header file

Assume a project with the 3 following files:

```C
// main.c

int main(int argc, char** argv) {
    finc_num1(1, 2);
    return 1;
}
```

```C
// src1.c

int func_num1(int a, int b) {
    return func_num2(a, b);
}
```

```C
// src2.c

int func_num2(int a, int b) {
    return a + b;
}
```

The current issue is that the C compiler does not know the argument/return types of `func_num1()` and `func_num2()` when compiling `main.c` and `src.c`. To solve this the following header files are created to define the protoytypes of the functions and are included in `main.c` and `src1.c`.

Include in `main.c`
```C
// src.h

int func_num1(int a, int b);
```

Include in `src1.c`.
```C
// src2.h

int func_num2(int a, int b);
```

Issues may arise when dealing with a large number of header files since duplicate inclusion of header files will *redefine* the contents and cause an error durring compilation.

### ifdef and ifndef

The `#ifdef` and `#ifndef` statements are for the compiler to determine if certain header definitions have been created yet.

```C
// myheader1.h

#ifndef MY_HEADER1_H
#define MY_HEADER1_H
// header stuff...
#endif
```

```C
// myheader2.h

#ifndef MY_HEADER2_H
#define MY_HEADER2_H
#include "myheader1.h"
// header stuff...
#endif
```

```C
// main.c

#include "myheader1.h"
#include "myheader2.h"

// some other code...
```

In the above example the duplicate inclusion of `header1.h` will be avoided because of the pre-existing definition when the comiler attempts to include it a second time via `header2.h`.

## <> vs. ""

`<...>` is used for system headers. These are searched for in the system path where headers are stored. `"..."` searches the current working directory for the header.

## Standard output

`printf()` accesses code in `libc`. From here a system call is exectued which transfers the execution to the linux kernel which handels the device hardware and display.

