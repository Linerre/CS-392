# IPC Shared Memory

A section of the physical memory that is shared by two processes. A section of the virtual memory of each process is allocated to the same piece of physical memory.

## Creating/Freeing Shared Memory

Interfaces: 
```C
// key: identification of ths shared memory
// size: size of the shared memory to be created (rounded up to PAGE_SIZE, usually 4096)
// flag: flags to control the behaviors of this interface
int shmget(key_t key, size_t size, int flag) 

key_t ftok(const char** pathname, int proj_id) 

// 'Attatches' the physical memory created by shmget() to the virtual memory of the process
// addr: a specific address to attatch to
// flag: flags to control the behaviors of this interface
void *shmat(int shm_id, const void *addr, int flag);
```

EX: Using two *independent* processes:
```C
// prog1.c
// creates a piece of shared memory
int main() {
    key_t key = ftok("/path", 1);
    int shm_id = shmget(key, 100, IPC_CREATE | 0666);

    char *p = shmat(shm_id, NULL, 0);

    // access memory by de-referencing the pointer...
    
    shmdt(p); // detatches 
    shmctl(shm_id, IPC_RMID, NULL); // deletes the memory
}
```

```C
// prog2.c
// uses existing shared memory
int main() {
    key_t key = ftok("/path", 1);
    int shm_id = shmget(key, 100, 0666); // does not re-create the memory

    char *p = shmat(shm_id, NULL, 0);

    // access memory by de-referencing the pointer... 

    shmdt(p); // detatches 
}
```

## Synchronizing Shared Memory

Use a piece of shared memory with a read and write value as well as the data.
 
Process 1
```C
while(true) {
    if (w == r) {
        *data = 0; // write data
        w++;
    }
}
```

Process 2
```C
while(true) {
    if (w - r == 1) {
        char a = *data; // read data
        r++;
    }
}
```
