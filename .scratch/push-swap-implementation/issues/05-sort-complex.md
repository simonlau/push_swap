# 05: sort_complex: radix LSD/MSD (O(n log n))

**What to build:** sort_complex orders a Stack larger than one hundred elements using a bit-by-bit radix sort (LSD or MSD), running enough bit passes to cover the largest absolute value's bit length rather than a fixed 32 passes. Used in the high-disorder regime (disorder ≥ 0.5).

**Blocked by:** 01: Stack primitives & Operations

**Status:** ready-for-agent

- [ ] A Stack of more than 100 elements sorts to ascending order
- [ ] Radix passes cover the bit length of the max absolute value (not fixed at 32)
- [ ] Only the eleven operations are used; each prints its name to stdout
- [ ] Existing `test_sort_complex` tests pass
