# I/O Part 2

Input and output in systems programming part 2.

## Formatted Output

```C
printf(fmt, ...);
```

Within the format string, [`format specifiers`](https://codeforwin.org/2015/05/list-of-all-format-specifiers-in-c-programming.html) are used to define a type value that will be printed. Format specifiers are printed based on their order following the format string.

## Strings in C

There is no string type in C programming. Instead arrays of characters terminated by the null character (null byte) `\O`. Also called null-terminated strings.

### Creating a string

```C 
// A string that fits 9 characters and the terminating null byte.
char str[10];

// str is automatically allocated to hold the string and the terminating null byte.
// Size is determined by the compiler to be 13 + 1 (null byte) = 14
char str[] = "Hello, world!";

// A constant string is created and str points to its beggining.
// It cannot be updated.
char *str = "Hello, world!";
```

### Printing a string

To print a string, the format specifier `%s` must be used:
```C
char str[] = "Hello, world!";
printf("%s\n", str);
```

Other common stardard output functions:
```C
// Writes a single character to the standard output
int putchar(char c);

// Write a string to the standard output
int puts(char* str);
```

## Recieving Input

```C
#include <stdio.h> 

int main(int argc, char * argv) {
    int var;
    scanf("%d", &var);
}
```

