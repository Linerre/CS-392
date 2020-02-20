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



