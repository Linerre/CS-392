# Standard C Libraries

A library of standard functions that can be used by all C programs (and sometimes by programs in other languages). By far the most widely used C library on Linux is the [GNU C Library](http://www.gnu.org/software/libc), often referred to as *glibc*.

- Standard IO and Stream IO operations `<stdio.h>`
- String operations `<string.h>`
- General functions `<stdlib.h>`

## Standard IO

```C
int printf ( const char * format, ... );
int putchar ( int character );
int puts ( const char * str );
int scanf ( const char * format, ... );
int getchar ( void );
char * gets ( char * str );

```

## Stream IO

```C
FILE* fopen ( const char * filename, const char * mode );
int fclose ( FILE * stream );
int ferror ( FILE * stream );
int feof ( FILE * stream );
char* fgets ( char * str, int num, FILE * stream );
int fgetc ( FILE * stream );
int fscanf ( FILE * stream, const char * format, ... );
size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
int fputs ( const char * str, FILE * stream );
int fputc ( int character, FILE * stream );
size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
int fprintf ( FILE * stream, const char * format, ... );
```

## String Operations

Predefined string operations provided by *glibc*.

### Copying
```C
// copy n bytes of src into dest, return dest
void* memcpy (void* dest, void* src, size_t n);

// copy src string into dest, return dest(stop when encountering '\0')
char* strcpy(char* dest, char* src);
```

### Concatenation
```C 
// append copy of src to end of dest, return dest('\0' of dest is overwritten)
char* strcat (char * dest, char* src);
```

### Comparison 

```C
// compare str1, str2 by character (based on ASCII value of each character, then string length), return comparison result
int strcmp (char * str1, char * str2);
```
- str1 < str2: -1 
- str1 == str2: 0
- str1 > str2: 1

### Searching 

```C 
// return pointer to first occurrence of str2 in str1, else NULL
char* strstr (char * str1, char * str2);

// tokenize str according to delimiter characters provided in delimiters, 
// return the next token per successive stroke call, using str = NULL
char* strtok (char * str, char * delimiters);
```

### Other 

```C
// returns length of the string (up to, but not including the ‘\0’ character)
size_t strlen (const char * str);

// set first n bytes of memory block addressed by ptr to val
void* memset (void* ptr, int val, size_t n);
```

## General Purpose Functions

- Dynamic memory allocation 
  - `malloc`, `calloc`, `free`
- String conversion 
  - `int atoi(char* str);` *parse string into integral value, return 0 if not parsed*
- System calls 
  - `void exit(int status);` *terminate calling process, return status to parent process* 
  - `void abort();` *aborts process abnormally*
- Sorting 
  - `void qsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*));` *Sorts the array destructively*
  - Function pointer: a pointer points to a function (pointer type must match the prototype)
- Integer arithmetic
  - `nt abs(int n);` *returns absolute value of n*
