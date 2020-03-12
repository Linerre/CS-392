# Compiling & Linking

Compiling is a process that transforms computer code written in one programming language (the source language) into another programming language (the target language).

## Compiling step by step

- The compiler pre-processes the directives by expanding `#include` and `#define`. 
- The preprocessed code is translated into assembly code which is then *assembled* into machine code.
- Object files are linked together to produce the final executable.

```bash
# main.c -> main.i -> main.s -> main.o
gcc -E main.c -o main.i
gcc -S main.i -o main.s
gcc main.s -o main.o
```

## Compiling with multiple files

Compiling is performed for each individual source file to produce **relocatable** object files which are then linked together to produce a single executable object file. 

*Linkers* are used to create modularity between code, thus a program can be written as a collectoin of smaller source files rather than one monolithic mass. Libraries of common functions can also be built due to this modular property. Modular code is also more *efficent* for both time and space. 

Since source files can be compiled separately (change one source file, compile, and then relink) modular code will compile faster. Additionally, library functions can be aggregated into a single file yet executable files and running memory images contain only code for the functions they actually use.

## What does `Linker` do?

### Symbol Resolution

Programs define and reference symbols (global variables and functions):
```C
void swap() {}     // define symbol swap 
swap();            // reference symbol swap 
int *xp = &x;      // define symbol xp, reference x 
```

Symbol definitions are stored in object file (by assembler) in symbol table. The symbol table is an array of structs where each entry includes name, size, and location of symbol. During the symbol resolution step, the linker associates each symbol reference with exactly **one** symbol definition.

### Relocation & Symbol Rules

At a high level, all the objects are *relocated* to a final executable and symbols are resolved using the compiler's symbol rules.

Program symbols are either strong or weak. 
- *Strong*: procedures and initialized globals 
- *Weak*: uninitialized globals

- Rule 1: Multiple strong symbols are not allowed
  - Each item can be defined only once
  - Otherwise: `Linker error`
- Rule 2: Given a strong symbol and multiple weak symbols, choose the strong symbol
  - References to the weak symbol resolve to the strong symbol
- Rule 3: If there are multiple weak symbols, pick an arbitrary one
  - Can override this with `gcc –fno-common`

## Compiling and linking libraries

Static libraries (`.a` archive files)
- Concatenate related relocatable object files into a single file with an index (called an *archive*)
- Linker tries to resolve unresolved external references by looking for the symbols in one or more archives
- If an archive member file resolves reference, link it  into the executable

Archiver
- Allows incremental updates
- Recompile function that changes and replace `.o` file in archive

### Using static libraries

Linker’s algorithm for resolving external references:

Scan for `.o` files and `.a` files in the command line order. During the scan, keep a list of the current unresolved references. As each new `.o` or `.a` file/obj is encountered, try to resolve each unresolved reference in the list against the symbols defined in obj. If any entries in the unresolved list at end of scan, then error.

### Shared libraries

Static libraries have the following disadvantages:
- Duplication in the stored executables (every function needs libc)
- Duplication in the running executables◦Minor bug fixes of system libraries require each application to explicitly relinkModern solution: 
Shared Libraries 
- Object files that contain code and data that are loaded and linked into an application dynamically, at either load-time or run-time (also called: dynamic link libraries, DLLs, `.so` files)
- Dynamic linking can occur when executable is first loaded and run (load-time linking)
- Common case for Linux, handled automatically by the dynamic linker (`ld-linux.so`)
- Standard C library (libc.so) usually dynamically linkedDynamic linking can also occur after program has begun (run-time linking: in Linux, this is done by calls to the `dlopen()` interface)
- Shared library routines can be shared by multiple processes.
