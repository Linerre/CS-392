# Process Control

## Creating a Child Process

```C
// Creates a child process
pid_t fork();
```

The child is copy of the parent (calling) process and both the parent and child resume execution in the instruction following fork() but a different value is returned in each case: 

- `0` -> in the child process
- `Child PID` -> in the parent process

```C
int main() {        
    pid_t pid;        
    int w = 100;        
    if ((pid = fork()) < 0) {                
        perror("fork");                
        return -1;       
    } else if (pid == 0) {
        /* child */                
        w = 200;        
    } else {
        /* parent */                
        w = -100;        
    }        
    printf("I am %d, child of %d, w = %d\n", getpid(), getppid(), w);        
    return 0;
}
```

## File Sharing

The child process inherits the all the file descriptors of its parent. 

![](/lectures/images/process-file-sharing.png)

## Waiting For Children

```C
// Wait for the status of a child process to change
pid_t wait(int *status);
```

Return the pid of the child. The status contains information on the state change. 

## Zombie Processes

A zombie process or defunct process is a process that has completed execution but still has an entry in the process table. This occurs when child processes exit but the parent has yet to read the exit status via `wait()`. Once the exit status is read via the wait system call, the zombie's entry is removed from the process table and it is said to be "reaped". A child process always first becomes a zombie before being removed from the resource table. Processes that stay zombies for a long time are generally an error and cause a resource leak.

**Always wait for your children!**

## Orphan Processes 

An orphan process is a computer process whose parent process has finished or terminated, though it remains running itself.

## Exec Functions

The `exec()` family of functions replaces the current process image with a new process image.

```C
int execl(const char *pathname, const char *arg0, ... /* (char *)0 */ );
int execv(const char *pathname, char *const argv []);
int execle(const char *pathname, const char *arg0, ... /* (char *)0, char *const envp[] */ );
int execve(const char *pathname, char *const argv[], char *const envp []);
int execlp(const char *filename, const char *arg0, ... /* (char *)0 */ );
int execvp(const char *filename, char *const argv []);
```

## System Function

```C
// Execute the shell command and return
int system(const char *command);
```

Forks and invokes `execl("/bin/sh", "sh", "-c", command, (char *) 0);`