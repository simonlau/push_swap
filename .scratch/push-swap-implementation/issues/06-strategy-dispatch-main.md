# 06: Strategy dispatch & main orchestration

**What to build:** The disorder-based dispatch that routes to sort_simple, sort_medium, or sort_complex depending on the Stack's measured disorder (disorder < 0.2 → simple; 0.2 ≤ disorder < 0.5 → medium; disorder ≥ 0.5 → complex), wired through select_strategy and into main: parse arguments, build the Stack, compute disorder, select and run the strategy, free the Stack, and exit. End-to-end: valid input sorts and prints operations (exit 0); invalid input prints "Error" (exit 1).

**Blocked by:** 01: Stack primitives & Operations, 02: Parsing & Validation, 03: Sort_simple, 04: Sort_medium, 05: Sort_complex, 07: compute_disorder disorder metric

**Status:** ready-for-agent

- [ ] compute_disorder is measured before any moves are made
- [ ] select_strategy dispatches to the correct sort function by disorder regime
- [ ] main builds the Stack, runs the selected sort, frees memory, exits 0 on success
- [ ] Invalid input prints "Error" to stderr and exits 1 without sorting
- [ ] End-to-end runs sort correctly across small, medium, and large inputs
- [ ] Existing `test_strategy` tests pass; full `make test` suite is green
