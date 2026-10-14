# Command Line Arguments in C

> Sources: GeeksforGeeks, 2026-07-03
> Raw: [command-line arguments in c](../../raw/c-programming/2026-10-14-command-line-arguments-in-c.md)
> Updated: 2026-10-14 — when the article's knowledge content last changed. Set to the creation date initially; refresh only on content changes, not typo or formatting fixes.

## Overview

Command line arguments are values passed to a C program at execution time, allowing users to provide input without modifying the source code. They enable programs to be more flexible and reusable by accepting dynamic input at runtime. The C language exposes them through two parameters of `main()`: `argc` (argument count) and `argv` (argument vector).

## Key Concepts

- **argc** — stores the total number of command-line arguments, including the program name itself
- **argv** — an array of strings, where each element is one command-line argument as a string
- **main signature** — `int main(int argc, char *argv[])` gives the program access to its arguments
- **Argument separation** — arguments are separated by spaces; values containing spaces must be enclosed in quotation marks

## Usage

Command-line arguments eliminate the need to modify source code or prompt the user for input each time the program runs. They are particularly useful for automation, scripting, and running the same program with different inputs.

## Example: Personalized Greeting

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        printf("Hello, %s!\n", argv[1]);
    }
    else
    {
        printf("Hello, World!\n");
    }

    return 0;
}
```

If a name is passed, the program prints a personalized greeting; otherwise it displays "Hello, World!" using the values stored in `argv`.

## Example: Display All Arguments

Compilation and execution:

```
gcc Hello.c -o Hello
Hello Geeks at GeeksforGeeks
```

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("No command-line arguments passed.\n");
    }
    else
    {
        for (int i = 0; i < argc; i++)
        {
            printf("Argument %d: %s\n", i, argv[i]);
        }
    }

    return 0;
}
```

## See Also

- [push_swap](../push_swap.md)
