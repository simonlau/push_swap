# Push-swap

Team for 42 push swap.

## Overview

`push_swap` is a command-line stack sorter. It takes a list of integers as
arguments, validates them strictly (no duplicates, no non-numeric input, no
integer overflow), builds a stack, sorts the values using a second stack and
the eleven allowed stack operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`,
`rr`, `rra`, `rrb`, `rrr`), prints each operation to stdout as it executes,
then frees all memory and exits.

Invalid input is rejected with `Error` on stderr and exit code `1`; no
sorting is attempted. Empty input (no arguments) and a single integer are
no-ops that exit `0` cleanly.

## Adaptive sorting strategy

Before any move is made, the program measures the disorder of the input: the
number of inverted pairs divided by the total number of pairs. The result is a
value in `[0, 1]`, where `0` means already sorted and `1` means reverse
sorted. Based on this metric, one of three sorting strategies is selected
(`strategy.c:select_strategy`, also available standalone as
`sort_adaptive`):

| Disorder regime | Condition | Strategy | Technique |
|-----------------|-----------|----------|-----------|
| Low             | `d < 0.2` | `sort_simple` | Selection / min-max extraction: repeatedly move the smallest remaining element of `a` to `b`, then push it back. Best for nearly sorted and very small stacks. |
| Medium          | `0.2 <= d < 0.5` | `sort_medium` | Chunk-based: split the sorted value range into `sqrt(n)` chunks, rotate elements of each chunk to the top of `a` and push them to `b`, then push everything back in decreasing order. |
| High            | `d >= 0.5` | `sort_complex` | Radix sort (LSD, bit-by-bit): rank the values by their sorted order, then for each bit partition `a` (push values with the bit set to `b`, rotate otherwise) and collect them back. The number of bit passes covers the bit length of the largest rank, not a fixed 32. |

The thresholds `0.2` and `0.5` were chosen so the algorithm matches the
input's sortedness: cheap selection/extraction for nearly sorted inputs,
chunk-based shuffling for moderately scrambled inputs, and bit-by-bit radix
for heavily scrambled or large inputs. `main` measures the disorder once,
before any operation runs, derives the strategy, and dispatches through
`select_strategy`; `sort_adaptive` performs the same measurement and dispatch
internally.

## Complexity

All sorting happens inside the push_swap operation model, where the only
primitives are the eleven stack mutations and each operation prints one line.

- **Time**: bounded by the number of operations emitted.
  - Simple: `O(n^2)` operations in the worst case (min-max extraction scans
    the stack per extracted element). Fine for `n <= 5` and nearly sorted data.
  - Medium: `O(n * sqrt(n))` operations (`sqrt(n)` chunks, each element
    rotated and pushed a bounded number of times). Target: under ~700
    operations for one hundred numbers.
  - Complex: `O(n * b)` operations where `b` is the bit length of the largest
    rank (one radix pass per bit, `n` operations per pass). Target: under
    ~5500 operations for five hundred numbers.

- **Space**: `O(n)` — two integer arrays (stack `a` and stack `b`) plus a
  temporary sorted copy used by the medium and complex sorts. All allocated
  memory is freed before exit; there are no leaks.

These move-count figures are guidance targets consistent with the 42 school
reference points, not hard-enforced limits.

## Building

```
make           # build push_swap
make bonus     # also build the checker stub
make test      # build and run the per-module test suite
make clean     # remove object files and test binaries
make fclean    # also remove the binaries
make re        # rebuild from scratch
```

## Testing

The `tests/` directory holds one test file per module (stack, operations,
parser, utils, sort_simple, sort_medium, sort_complex, sort_adaptive,
strategy) using the shared `tst.h` framework. Tests assert external behavior
only: sorted output, valid operation names and counts, correct `Error`
messages and exit codes, and absence of memory leaks.

## Notes

- The stack is array-based (fixed-capacity array with size/capacity counts),
  not a linked list.
- The checker bonus program and its utilities remain stubs for future bonus
  implementation and are kept in the build system.
