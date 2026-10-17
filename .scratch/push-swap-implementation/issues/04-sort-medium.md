# 04: sort_medium: chunk-based with √n chunks (O(n√n))

**What to build:** sort_medium orders a Stack of five to one hundred elements using a chunk-based approach: push elements to Stack b in √n-sized chunks, sort them, then push them back to Stack a in order. Chunk count scales with stack size rather than being fixed. Used in the medium-disorder regime (0.2 ≤ disorder < 0.5).

**Blocked by:** 01: Stack primitives & Operations

**Status:** ready-for-agent

- [ ] A Stack of 5–100 elements sorts to ascending order
- [ ] Chunk count scales with stack size (√n chunks, not a fixed literal)
- [ ] Only the eleven operations are used; each prints its name to stdout
- [ ] Existing `test_sort_medium` tests pass
