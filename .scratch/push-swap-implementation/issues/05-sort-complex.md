# 05: sort_complex: radix digit-by-digit (O(n log n))

**What to build:** sort_complex orders a Stack larger than one hundred elements using a digit-by-digit radix sort (LSD), running enough digit passes to cover the largest absolute value's digit length rather than a fixed pass count. Negative values are bias-shifted to non-negative so digit passes stay sign-agnostic. Used in the high-disorder regime (disorder ≥ 0.5).

**Blocked by:** 01: Stack primitives & Operations

**Status:** ready-for-agent

- [ ] A Stack of more than 100 elements sorts to ascending order
- [ ] Radix passes cover the digit length of the max absolute value (input-driven, not fixed at 32)
- [ ] Negative values sort correctly via bias shift; only the eleven operations are used, each prints its name to stdout
- [ ] Existing `test_sort_complex` tests pass
