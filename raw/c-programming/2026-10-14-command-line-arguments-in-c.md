# Command Line Arguments in C

> Source: https://www.geeksforgeeks.org/cpp/command-line-arguments-in-c-cpp/
> Collected: 2026-10-14
> Published: 2026-07-03

Command Line Arguments in C are values passed to a C program when it is executed from the command line, allowing users to provide input without modifying the source code. They make programs more flexible by accepting dynamic input at runtime.

- Allow users to pass input values directly when running the program from the command line.
- Make programs more flexible and reusable by processing different inputs without changing the source code.

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    // argc → number of arguments
    // argv → array of arguments

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

**Output**

```
Hello, World!
```

**Explanation**

- The program checks whether a command-line argument is provided using argc.
- If a name is passed, it prints a personalized greeting; otherwise, it displays "Hello, World!" using the values stored in argv.

## Use of Command Line Arguments

Command-line arguments allow a program to receive input directly when it is executed, making it more flexible and reusable.

- They eliminate the need to modify the source code or prompt the user for input every time the program runs.
- They are useful for automation, scripting, and running the same program with different inputs.

## Working of Command-Line Arguments

Command-line arguments are passed to the main() function when the program starts and can be accessed using argc and argv.

- argc stores the total number of command-line arguments, while argv is an array containing each argument as a string.
- Arguments are separated by spaces, and values containing spaces should be enclosed in quotation marks.

### Example: Display Command-Line Arguments Passed to a C Program

To compile and run a C program in the command prompt, follow the steps written below:

- Save the program as Hello.c
- Open the command prompt window and compile the program using: `gcc Hello.c -o Hello`
- After successful compilation, run the program by writing the arguments: `Hello [arguments]`
- For example: `Hello Geeks at GeeksforGeeks`
- Press Enter and you will get the desired output

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
