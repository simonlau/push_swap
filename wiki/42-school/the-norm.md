# The Norm (42 School Coding Standard)

> Sources: 42 School, Unknown
> Raw: [the norm v4.1](../../raw/42-school/2026-10-16-the-norm-v4.1.md)
> Updated: 2026-10-16 — when the article's knowledge content last changed. Set to the creation date initially; refresh only on content changes, not typo or formatting fixes.

## Overview

The Norm is the mandatory coding standard at 42 School for all C projects in the Common Core. Version 4.1 enforces strict rules on naming, formatting, function design, and file organization. Compliance is checked by the `norminette` tool (open source, Python), though some subjective rules are only caught during human code review (marked with *(*)* in the original document).

## Key Rules

### Naming

- Structures: `s_` prefix; typedefs: `t_`; unions: `u_`; enums: `e_`; globals: `g_`
- All identifiers use `snake_case` — lowercase, digits, underscore only
- No non-ASCII characters (except in string/char literals)
- Global variables must be `const` or `static` unless explicitly allowed

### Formatting

- **Max 25 lines** per function (excluding braces)
- **Max 80 columns** per line (comments included; tabs count as their visual width)
- Indent with **real tabs** (4-char width, ASCII 9) — not spaces
- Braces on their own line (except in struct/enum/union declarations)
- One instruction per line; one variable declaration per line
- Empty line between declarations and function body; no other empty lines in functions
- Pointers: asterisk stuck to variable name (`char *str`, not `char* str`)
- Operators separated by exactly one space; line continuations start with the operator

### Functions

- **Max 4 named parameters**
- **Max 5 variables** per function
- No-argument functions must use `void` in prototype
- Parameters in prototypes must be named
- Return value must be parenthesized (unless void)
- One tab between return type and function name

### Structures and Types

- Space between keyword and name: `struct s_foo`, `enum e_bar`, `typedef ... t_baz`
- Struct names indented on the same column within their scope
- Structures cannot be declared in `.c` files

### Headers

- Allowed: includes, declarations, defines, prototypes, macros
- Include guard required: `FT_FOO_H` for `ft_foo.h`
- No including `.c` files anywhere
- No unused includes

### Macros and Preprocessor

- `#define` only for literal/constant values
- No multiline macros; macro names all uppercase
- Preprocessor directives indented within `#if`/`#ifdef`/`#ifndef` blocks
- No preprocessor instructions outside global scope

### Forbidden Constructs

- `for` loops
- `do...while` loops
- `switch` / `case`
- `goto`
- Ternary operator (`?:`)
- Variable-length arrays (VLAs)
- Implicit type declarations

### Comments

- No comments inside function bodies
- Comments must be English and useful
- Comments cannot justify bad function design

### Files and Makefiles

- No `.c` file includes another `.c` file
- **Max 5 function definitions** per `.c` file
- Makefile must have: `$(NAME)`, `clean`, `fclean`, `re`, `all` (default target)
- No unnecessary relinking
- All source files explicitly named (no wildcards like `*.c`)
- Non-system libraries (e.g., libft) must be compiled automatically

## See Also

- [push_swap](../push_swap.md)
- [Command Line Arguments in C](../c-programming/command-line-arguments.md)
- [Variadic Functions in C](../c-programming/variadic-functions.md)
