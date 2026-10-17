title: Implement 42 school push_swap stack sorter
labels: ready-for-agent
---

## Problem Statement

The push_swap program is currently a skeleton of stubs. It does not parse command-line arguments, build a stack, apply any of the eleven stack operations, sort the stack, or print operations as they run. From the user's perspective, running the program does nothing useful: it exits immediately without sorting anything, without reporting errors on invalid input, and without producing any operation output.

## Solution

Implement the complete push_swap program: a command-line tool that takes a list of integers as arguments, validates them strictly, builds a stack, sorts the values using a second stack and the eleven allowed operations, prints each operation to stdout as it executes, and exits cleanly. Invalid input (duplicates, non-numeric values, integer overflow) is rejected with an "Error" message on stderr and a non-zero exit code. The program computes a disorder metric (0 to 1) and selects one of four sorting strategies per §VI.3.3: simple (O(n²)), medium (O(n√n)), complex (O(n log n)), or adaptive (disorder-based regime dispatch).

## User Stories

1. As a user, I want to pass a list of integers as command-line arguments, so that the program knows which values to sort.
2. As a user, I want duplicate values to be rejected with "Error" on stderr and exit code 1, so that invalid input does not produce incorrect sorting.
3. As a user, I want non-numeric input to be rejected with "Error" on stderr and exit code 1, so that malformed arguments are caught early.
4. As a user, I want integer overflow to be rejected with "Error" on stderr and exit code 1, so that out-of-range values are not silently wrapped.
5. As a user, I want empty input (no arguments) to be handled gracefully with no sorting performed and no error, so that running the program with nothing to sort is a no-op.
6. As a user, I want a single integer argument to result in no operations and a clean exit, since one element is already sorted.
7. As a user, I want two integer arguments to be sorted with the minimal number of operations, so that the simplest case is optimal.
8. As a user, I want each stack operation (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr) to print its name to stdout as it executes, so that I can see and count the operations performed.
9. As a user, I want the program to use only the eleven allowed operations to sort stack a using stack b, so that the output conforms to the push_swap rules.
10. As a user, I want stacks of five or fewer elements to be sorted with direct swaps and rotations, so that small cases are handled optimally without complex logic.
11. As a user, I want stacks of five to one hundred elements to be sorted using a chunk-based approach (√n chunks) that pushes elements to stack b, sorts them, and pushes them back, so that medium cases are efficient.
12. As a user, I want stacks larger than one hundred elements to be sorted using a radix sort (LSD/MSD) that processes integers bit by bit, so that large cases scale well.
13. As a user, I want the program to compute the disorder metric (0 to 1) before sorting and select the strategy per regime: disorder < 0.2 uses simple (O(n²)), 0.2 ≤ disorder < 0.5 uses medium (O(n√n)), disorder ≥ 0.5 uses complex (O(n log n)), so that the algorithm matches the input's sortedness.
14. As a user, I want the program to minimize the total number of operations, targeting roughly under 700 operations for one hundred numbers and under 5500 operations for five hundred numbers, so that it meets the 42 school grading criteria.
15. As a user, I want the program to free all allocated memory before exiting, so that there are no memory leaks.
16. As a user, I want the checker bonus program to remain available as a stub for future implementation, so that the bonus target in the build system continues to compile.
17. As a user, I want the README.md to document the strategy rationale, internal techniques per disorder regime, and a brief complexity argument, so that the design decisions are transparent per §VI.3.3.

## Implementation Decisions

- **Modules to build or modify**: stack management (initialization, freeing, append), operation primitives (the eleven stack mutations), parsing and validation (argument parsing, duplicate detection, overflow detection), sorting algorithms (selection/min-max extraction small sort, chunk-based medium sort with √n chunks, radix LSD/MSD large sort, disorder-based adaptive dispatch), disorder metric computation, and program orchestration (argument handling, stack filling, strategy invocation, cleanup, exit codes).
- **Stack representation**: Keep the existing array-based stack structure (a fixed-capacity array of integers with size and capacity counts) rather than switching to a linked list.
- **Validation semantics**: Reject duplicates, non-numeric input, and integer overflow by printing "Error" to stderr and exiting with code 1; no sorting is attempted on invalid input. Per project input contract, the stack will not contain duplicate values or invalid ints, so validation is a safety gate rather than the expected failure path.
- **Operation output**: Print each operation's name to stdout at the moment it is executed, one per line.
- **Sorting algorithm mix**: Implement four sorting functions — selection/min-max extraction sort for five or fewer elements, chunk-based push-to-b-then-sort-push-back with √n chunks for five to one hundred elements, bit-by-bit radix sort (LSD/MSD) for more than one hundred elements, and disorder-based adaptive dispatch that routes to the appropriate one by measured disorder regime. Size boundaries are kept flexible (e.g., via compile-time constants) rather than hardcoded literals.
- **Disorder metric**: compute_disorder returns inversion count divided by total pairs, a value between 0 (already sorted) and 1 (worst case), measured before any moves are made.
- **Adaptive dispatch thresholds**: disorder < 0.2 → simple (O(n²)); 0.2 ≤ disorder < 0.5 → medium (O(n√n)); disorder ≥ 0.5 → complex (O(n log n)), per §VI.3.3 complexity targets.
- **Chunk count for medium sort**: Make the chunk count adaptive to stack size (√n chunks) rather than a fixed number.
- **Radix pass count for complex sort**: Run enough bit passes to cover the bit length of the largest absolute value in the stack, rather than a fixed 32 passes.
- **Move-count budgets**: Target approximately under 700 operations for one hundred numbers and under 5500 operations for five hundred numbers, consistent with 42 school reference points; these are guidance targets, not hard enforced limits.
- **main orchestration**: Parse arguments, initialize and fill the stack, compute disorder, select and run the strategy, free the stack, and return zero on success or one on validation failure.
- **Checker bonus**: Leave the checker program and its utilities as stubs for future bonus implementation; do not remove them from the build system.
- **README documentation**: Document the strategy rationale, internal techniques used in each disorder regime, and a brief complexity argument (upper bounds for time and space within the Push_swap operation model) in README.md, per §VI.3.3.
- **No file paths or code snippets are included in this spec**, per the spec template convention, to avoid encoding implementation details that may change.

## Testing Decisions

- **What makes a good test**: Tests should verify external behavior only — correct sorted output, correct operation names and counts printed to stdout, correct "Error" messages and exit codes on invalid input, and absence of memory leaks — without asserting on internal implementation details such as specific array indices or intermediate stack states.
- **Modules to test**: stack management, each of the eleven operation primitives, argument parsing and validation, all four sorting algorithms, the strategy dispatch, disorder metric computation, utils (abs/min/max helpers), and end-to-end program behavior via main.
- **Prior art for tests**: The codebase already contains a `tests/` directory with one test file per module (test_stack, test_ops_swap, test_ops_push, test_ops_rotate, test_ops_reverse_rotate, test_parser, test_sort_simple, test_sort_medium, test_sort_complex, test_sort_adaptive, test_strategy, test_utils) and a shared `tst.h` test framework. These existing test files are the preferred seams and should be filled in rather than creating new test infrastructure. The Makefile already has a `test` target that builds and runs all `test_*.c` files against the non-main object files plus the ft_printf library.
- **Highest seam**: The program end-to-end via main (arguments in, operations to stdout, exit code out) is the highest seam, supplemented by per-module tests through the existing tst framework seams. Existing test files are preferred over new ones.

## Out of Scope

- Implementing the checker bonus program (remains a stub for future work).
- Any graphical interface, file I/O beyond stdout/stderr, or network interaction.
- Changing the stack representation from array-based to linked list.
- Enforcing move-count budgets as hard failures; they are guidance targets only.
- Modifying the ft_printf library or other build dependencies.

## Further Notes

- The project glossary (`GLOSSARY.md` at the repo root) defines the canonical terms used throughout this spec: Stack, Operation, Validation, Strategy, Sort_simple, Sort_medium, Sort_complex, Sort_adaptive, Disorder, Push_swap, Checker. Implementers should use this vocabulary consistently.
- No ADRs were created for this feature; no existing decision met all three criteria (hard to reverse, surprising without context, result of a real trade-off). The array-based stack is already visible in the public header, and the algorithm mix is the standard push_swap approach.
- The local-markdown issue tracker convention is in force: this spec is published as a markdown file under `.scratch/push-swap-implementation/` with the `ready-for-agent` triage label applied.
