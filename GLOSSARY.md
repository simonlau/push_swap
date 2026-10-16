# Push-swap

The context is the 42 school push_swap project: sorting a stack of integers using a second stack and a fixed set of eleven operations, minimizing the number of operations performed.

## Language

**Stack**:
A fixed-capacity array of integers with a size count, representing one of the two piles (a or b).
_Avoid_: pile, list, deque

**Operation**:
One of the eleven allowed instructions (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr) that mutates one or both stacks; each is printed to stdout when executed.
_Avoid_: instruction, command, move

**Validation**:
The pre-sort check that rejects duplicate values, non-numeric input, and integer overflow by printing "Error" to stderr and exiting with code 1.
_Avoid_: parsing, sanitization

**Strategy**:
The dispatch function that selects the appropriate sorting algorithm (simple, medium, complex, adaptive) based on stack size.
_Avoid_: algorithm selector, sorter

**Sort_simple**:
Direct sorting of five or fewer elements using only swaps and rotations.
_Avoid_: small sort, tiny sort

**Sort_medium**:
Chunk-based sorting that pushes elements to stack b in groups, sorts them, then pushes back.
_Avoid_: medium sort, bucket sort

**Sort_complex**:
Radix sort that processes integers bit by bit for stacks larger than 100 elements.
_Avoid_: large sort, radix-only sort

**Sort_adaptive**:
Size-based dispatch that routes to sort_simple, sort_medium, or sort_complex depending on element count.
_Avoid_: adaptive sort, hybrid sort

**Push_swap**:
The program that sorts stack a using stack b and the eleven operations, printing each operation as it runs.
_Avoid_: sorter, stack-sorter

**Checker**:
The bonus program that reads operations from stdin and verifies they sort stack a correctly, printing "OK" or "KO". Currently stubbed, reserved for future implementation.
_Avoid_: validator, verifier
