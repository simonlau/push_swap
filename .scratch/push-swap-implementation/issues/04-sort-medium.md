# 04: Sort_medium (5–100 elements)

**What to build:** Sort_medium that orders a Stack of five to one hundred elements using a chunk-based approach: push elements to Stack b in adaptive-sized chunks, sort them, then push them back to Stack a in order. Chunk count scales with stack size rather than being fixed.

**Blocked by:** 01: Stack primitives & Operations

**Status:** ready-for-agent

- [ ] A Stack of 5–100 elements sorts to ascending order
- [ ] Chunk count adapts to stack size (not a fixed literal)
- [ ] Only the eleven operations are used; each prints its name to stdout
- [ ] Existing `test_sort_medium` tests pass
