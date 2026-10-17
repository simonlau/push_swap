# 05: sort_complex: binary LSD radix on ranks (O(n log n))

**What to build:** sort_complex orders a Stack larger than one hundred elements using an in-place binary LSD radix sort. Values are rank-normalized first (rank = number of smaller elements), so negatives and arbitrary value ranges are handled without bias shifts, then bit passes run from least-significant to most-significant covering only the bits needed for the largest rank (input-driven, not a fixed 32). Elements are moved between the two stacks solely through the eleven operations (ra, pb, pa); the stacks are read freely for inspection. Used in the high-disorder regime (disorder ≥ 0.5).

**Blocked by:** 01: Stack primitives & Operations

**Status:** closed

- [x] A Stack of more than 100 elements sorts to ascending order
- [x] Radix passes are input-driven, covering the bit length of the largest rank (not fixed at 32)
- [x] Negative values sort correctly; only the eleven operations mutate the stacks, each prints its name to stdout
- [x] Existing `test_sort_complex` tests pass, plus a new test asserting only valid operations are emitted and the operation count stays O(n log n)
