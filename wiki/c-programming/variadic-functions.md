# Variadic Functions in C

> Sources: GeeksforGeeks, 2026-04-10
> Raw: [variadic functions in c](../../raw/c-programming/2026-10-14-variadic-functions-in-c.md)
> Updated: 2026-10-14 — when the article's knowledge content last changed. Set to the creation date initially; refresh only on content changes, not typo or formatting fixes.

## Overview

Variadic functions in C accept a variable number of arguments. They require at least one fixed parameter, followed by an ellipsis (`...`). The `<stdarg.h>` header provides the `va_list` type and four macros needed to access the variable arguments safely.

## Key Concepts

- **Syntax**: `return_type name(fixed_arg, ...);` — at least one fixed argument is mandatory before the ellipsis
- **va_list** — stores information needed to retrieve additional arguments
- **va_start(list, fixed_arg)** — initializes the `va_list` to begin traversing the variable arguments
- **va_arg(list, type)** — returns the next argument; must be called once per argument
- **va_end(list)** — releases resources associated with the `va_list`

> **Note:** It is important to not mix up the type of the arguments passed to `va_arg`.

## Usage

Variadic functions are useful when the number of arguments is unknown at compile time — for example, summing an arbitrary count of integers or printing values of mixed types.

## Example: Print Variable Arguments

```c
#include <stdio.h>
#include <stdarg.h>

void print(int n, ...)
{
    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++)
        printf("%d ", va_arg(args, int));
    printf("\n");
    va_end(args);
}

int main()
{
    print(3, 1, 2, 3);
    print(5, 1, 2, 3, 4, 5);
    return 0;
}
```

Output:

```
1 2 3
1 2 3 4 5
```

## Example: Sum of Given Numbers

```c
#include <stdarg.h>
#include <stdio.h>

int getSum(int n, ...)
{
    int sum = 0;
    va_list list;
    va_start(list, n);

    for (int i = 0; i < n; i++)
        sum += va_arg(list, int);

    va_end(list);
    return sum;
}

int main()
{
    printf("1 + 2 = %d\n", getSum(2, 1, 2));
    printf("3 + 4 + 5 = %d\n", getSum(3, 3, 4, 5));
    printf("6 + 7 + 8 + 9 = %d", getSum(4, 6, 7, 8, 9));
    return 0;
}
```

Output:

```
1 + 2 = 3
3 + 4 + 5 = 12
6 + 7 + 8 + 9 = 30
```

## Example: Mixed Argument Types

```c
#include <stdio.h>
#include <stdarg.h>

void print(int n, ...)
{
    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            printf("Integer: %d\n", va_arg(args, int));
        } else {
            printf("Float: %.2f\n", va_arg(args, double));
        }
    }
    va_end(args);
}

int main()
{
    print(4, 10, 3.14, 20, 2.71);
    return 0;
}
```

Output:

```
Integer: 10
Float: 3.14
Integer: 20
Float: 2.71
```

## See Also

- [Command Line Arguments in C](command-line-arguments.md)
