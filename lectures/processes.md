# Processes 

A process is an instance of a running program. The life of a process begins when it is executed and it ends when its main function returns or when a function/system call that terminates it is made.

## PIDs

Every process has a unique process ID (PID) non-negative integer. PIDs are assigned by the kernel and the ID of terminated process can be reused. The currently running processes can be listed using the `ps` command.

```C
// Return the process ID of the current process.
pid_t getpid(void);
```

```C
#include <stdlib.h> /* needed to define exit() */ 
#include <unistd.h> /* needed to define getpid() */ 
#include <stdio.h>  /* needed for printf() */ 
int main(int argc, char **argv) { 
    printf("my process ID is %d\n", getpid()); 
    exit(0);
}
```

## Exit Functions

`return <nr>` from main is equivalent to `exit(nr)` (`exit(int)` is a libc function). It calls all handlers installed with `atexit()` and `on_exit()`, closes I/O streams, calls `_exit()` or `_Exit()` 

`_exit(int)` or `_Exit(int)` is a system call that tells the kernel to immediately close all files and terminate the process.

