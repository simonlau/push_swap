# 07: compute_disorder disorder metric

**What to build:** A `compute_disorder(Stack *a)` function that measures how far Stack a is from being sorted, returning a value between 0 and 1. It counts every pair (i, j) with i < j where data[i] > data[j] (an inversion / "mistake") and divides by the total number of pairs. Per the subject: disorder is 0 when already sorted, 1 in the worst case, and must be measured before doing any moves. It feeds the adaptive strategy thresholds (disorder < 0.2 → simple; 0.2 ≤ disorder < 0.5 → medium; disorder ≥ 0.5 → complex) and the `--bench` output (disorder printed to stderr with two decimals).

**Blocked by:** 01: Stack primitives & Operations

**Status:** ready-for-agent

- [ ] compute_disorder returns 0 for an already-sorted Stack
- [ ] compute_disorder returns 1 for reverse-sorted input
- [ ] compute_disorder returns a value strictly between 0 and 1 for partially sorted input
- [ ] compute_disorder handles empty and single-element Stacks without division by zero
- [ ] compute_disorder only reads the Stack (measures before any moves)
- [ ] Edge cases: duplicate-free input (valid per subject); graceful on pathological sizes
