*Este proyecto ha sido creado como parte del currículo de 42 por jucortes.*

## Descripción

`get_next_line` is a utility function that reads a file descriptor one line at a time.
Each call to `get_next_line(int fd)` returns one line of text, stored in a
new `char` array allocated on the heap, ending in a newline character (except for the
last line, which ends without one) and a null byte (`\0`). When the end of file is
reached the function returns `NULL`.

The goal of this project is to become comfortable with two core C concepts:

- **Static variables** — a `static` variable keeps its value between calls to a
  function, which lets us remember *where we stopped reading* in a file descriptor
  across multiple `get_next_line` calls.
- **Manual memory management** — the line is built with `malloc` and it is the
  *caller* who must `free` it. No hidden global state and no leaks.

A line is read in chunks of `BUFFER_SIZE` bytes. `BUFFER_SIZE` and the buffer
reading are not hardcoded: the whole thing works for `BUFFER_SIZE` values of `1`,
`9999` and even `10000000`.

The **bonus** part keeps the reading state for several file descriptors at the same
time, using *a single static variable* (an array of pointers indexed by fd), so the
reader can interleave fds 3, 4 and 5 without losing track of each of them.

## Instrucciones

This project delivers **no binary and no `Makefile`**: the subject's "Archivos a
entregar" are only `get_next_line.c`, `get_next_line_utils.c` and
`get_next_line.h` (plus `get_next_line_bonus.c`, `get_next_line_bonus.h` and
`get_next_line_utils_bonus.c` for the bonus). `get_next_line` is meant to be
compiled together with whatever program uses it.

Compile it next to your own `main`, with the flags required by 42 and the
`BUFFER_SIZE` of your choice:

```sh
# mandatory part
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line.c get_next_line_utils.c tu_main.c -o gnl

# bonus part (several file descriptors at once)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line_bonus.c get_next_line_utils_bonus.c tu_main.c -o gnl_bonus
```

`-D BUFFER_SIZE=n` is optional: if it is not given, the header falls back to
`1024`, so the project also compiles with just
`cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c tu_main.c`.

Note that the mandatory and the bonus part both define `get_next_line`, so they
can never be linked into the same binary: pick one set of sources per build.

Then call the function from your program:

```c
#include "get_next_line.h"

char *line;
while ((line = get_next_line(0)) != NULL)   /* read from stdin */
{
    printf("%s", line);
    free(line);                             /* the caller owns the line */
}
```

> Note: no test driver is kept in this directory. The subject states that test
> programs are neither delivered nor evaluated, so `main.c` lives outside the
> repository: write your own and compile it alongside the sources as shown above.

### Verifying it

```sh
valgrind --leak-check=full --error-exitcode=9 ./gnl <fichero>   # 0 bytes at exit
norminette get_next_line*.c get_next_line*.h
```

## Recursos

- 42 Norme (official student's handbook, C).
- `man 3 read` — the `read` system call.
- [Beej's Guide to C](http://www.beej.us/guide/) — pointers, memory and statics.
- [linux man pages](https://man7.org/linux/man-pages/man3/read.3.html)

### Uso de la IA (IA usage)

IA was used as an *assistant during development and review*: proposing an initial
structure, explaining C concepts (static variables, the difference between stack and
heap, `malloc`/`free`) and helping to re-write the code until it passed the Norme and
`valgrind`. Every line of the final code was reviewed, understood and re-implemented
by me. I am able to explain the whole algorithm: the flow of `get_next_line`, the
role of the static variable, how the line is sliced out of the buffer, the `malloc`
of the line, and why the read buffer is allocated on the heap instead of the stack.

### Del algoritmo (algorithm justification)

Why this design, and why it scales from `BUFFER_SIZE = 1` to `10000000`:

1. **Static variable for the state.** A single `static char *save` (mandatory part)
   holds whatever bytes were read but not yet handed back. Between two calls to
   `get_next_line` the static variable keeps pointing at that saved data, so we never
   re-read or lose it. This is the heart of the project.

2. **Read into a heap buffer, never onto the stack.** A local
   `char buf[BUFFER_SIZE + 1]` would be an automatic (stack) allocation of
   `BUFFER_SIZE + 1` bytes. The Linux user stack is normally *limited* (`ulimit -s`,
   a few MiB at most). If `BUFFER_SIZE` is `10000000` that local array needs roughly
   **10 MiB on the stack and the program segfaults**. Instead the read buffer is
   allocated with `malloc` on the **heap** (`char *buf = malloc(BUFFER_SIZE + 1)`).
   That is why the function works for `1`, `42`, `9999` or `10000000` without any
   code change: the size only affects a heap allocation, never the stack.

3. **Line assembly.** Each loop: `read` `BUFFER_SIZE` bytes into the heap buffer,
   append them to the saved data, and check if a `\n` appeared. When a `\n` is found,
   we copy the bytes up to and including the `\n` into a **new** `malloc`'d line, and
   keep the rest in the static variable for the next call. The read buffer is then
   released.

4. **The bonus (multi-fd).** One `static` array
   `char *saves[GNL_MAX_FD]`, where index `fd` (up to `GNL_MAX_FD` = 512) holds the saved state of that file
   descriptor. Because the state lives in a single static variable (the array), the
   function honours the "one static variable" rule while being able to read from fd 3,
   then 4, then 5, interleaved, each remembering exactly where it left off and never
   returning another descriptor's line.

Memory discipline: the only long-lived allocation is the static saved line (needed for
the next call); every temporary buffer and every returned line is released, and the
caller frees the line it receives. There are no leaks (verified with `valgrind`) and
no unexpected termination (`-Werror` catches misuse at compile time).
