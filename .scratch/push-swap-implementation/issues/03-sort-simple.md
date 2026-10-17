# 03: sort_simple: selection/min-max extraction (O(n²))

**What to build:** sort_simple orders a Stack of five or fewer elements using selection/min-max extraction, minimizing the number of operations. Only swaps and rotations are used. This is the base case the adaptive strategy routes to when disorder < 0.2.

**Blocked by:** 01: Stack primitives & Operations

**Status:** ready-for-agent

- [ ] A Stack of 0 or 1 element sorts with zero operations
- [ ] A Stack of 2–5 elements sorts to ascending order using selection/min-max extraction
- [ ] Only swaps and rotations are used; each prints its name to stdout
- [ ] Operation count is minimal for small inputs
- [ ] Existing `test_sort_simple` tests pass
