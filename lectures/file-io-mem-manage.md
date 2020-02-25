# Stream I/O and Memory Management

On Linux, input and output are mapped into logical data streams. To/from physical devices such as terminals, tape drives, files on structured storage devices.

## C Stream I/O

Operations on data streams are with uniform interfaces, regardless of source and destination.

Three standard streams defined by POSIX (stdio.h): `stdin`, `stdout`, `stderr`.

### Open/Close a Stream

```C
// openfile.c

#include<stdio.h>

int main(int argc, char **argv) {
    FILE *fp;
    fp = fopen("/path/to/file", "r");

    // do something with the file...

    fclose(fp); // close the open stream

    return 1;
}
```

### Read/Write with Streams

```C
// openfile.c

#include<stdio.h>

int main(int argc, char **argv) {
    FILE *fp;
    fp = fopen("/path/to/file", "r");

    // at most 19 bytes will be read and a null terminator witll be appended thereafter.
    fgets(str, 20, fp); 

    // print what was just read to the standard output
    fputs(str, stdout);

    fclose(fp);

    return 1;
}
```

## General I/O Read/Write

```C 
size_t fwrite (const void *ptr, size_t size, size_t count, FILE *stream );
``` 
Writes an array of count elements, each one with a size of size bytes, from theblock of memory pointed by ptr to the current position in the stream. The position indicator of the stream is advanced by the total number of byteswritten.The number of bytes written is indicated by the return value.

```C
int fseek(FILE* stream, long offset,int whence);
```
Sets the file position indicator for the stream pointed to by stream. The new position, measured in bytes, is obtained by adding offset bytes to the position specified by whence.

`whence`: `SEEK_SET`, `SEEK_CUR`, or `SEEK_END` 

```C
long ftell(FILE* stream);
```
Obtains the current value of the file position indicator for the stream pointed to by stream.

```C
void rewind(FILE* stream);
```
Sets the file position indicator for the stream pointed to by stream to the beginning of the file. It is equivalent to: `(void) fseek(stream, 0L, SEEK_SET)`


## Formatted Stream I/O

```C
int fscanf ( FILE * stream, const char * format, ... );
```
Read formatted data from stream. Reads data from the stream and stores them according to the parameter format into the locations pointed by the additional `arguments.scanf(const char* format,...) = fscanf(stdin,constchar *format,...)`

```C
int fprintf ( FILE * stream, const char * format, ... ); 
```
Write formatted data to stream. Writes the C string pointed by format to the stream. If format includes format specifiers (subsequences beginning with %), the additional arguments following format are formatted and inserted in the resulting string replacing their respective specifiers. `printf(const* format,...) = fprintf(stdout,const* format,...)`

## Error Handling 

In Unix-like operating systems, such as Linux, macOS X, and BSD, stderr is defined by the POSIX standard. Its default file descriptor number is 2. In the terminal, standard error defaults to the user's screen. stderr is a data stream defined in `stdio.h` for standard error.

`errno` is a global integer variable set by libc functions. Whenever an error occurs it is set to a non-zero error number. It is never set to zero by libc, but you can modify it. Numbers are defined in `errno.h`. We can use `errno -l` to print the error message behind an error number.

```C
char* strerror(interrnum);
```
Return a pointer to a string describing the error behind errnum.

```C
void perror(constchar*s);
```
Produces an error message including the string s, colon, and a description of the last error based on the error number stored in errno perror(s) is equivalent to `printf(“%s: %s\n”, s, strerror(errno));` 

## Terminating a Process

```C
void exit(int status);
```
In certain cases you may want to immediately terminate your process (*for example, after a fatal error occurs*). The process will exit with an exit code status. All open streams will be flushed and closed. 

The C standard specifies two constants, `EXIT_SUCCESS` and `EXIT_FAILURE`, that may be passed to `exit()` to indicate  successful or unsuccessful termination, respectively.