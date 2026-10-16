# 06: Strategy dispatch & main orchestration

**What to build:** The size-based dispatch that routes to sort_simple, sort_medium, or sort_complex depending on Stack size, wired through select_strategy and into main: parse arguments, build the Stack, select and run the strategy, free the Stack, and exit. End-to-end: valid input sorts and prints operations (exit 0); invalid input prints "Error" (exit 1).

**Blocked by:** 01: Stack primitives & Operations, 02: Parsing & Validation, 03: Sort_simple, 04: Sort_medium, 05: Sort_complex

**Status:** ready-for-agent

- [ ] select_strategy dispatches to the correct sort function by stack size
- [ ] main builds the Stack, runs the selected sort, frees memory, exits 0 on success
- [ ] Invalid input prints "Error" to stderr and exits 1 without sorting
- [ ] End-to-end runs sort correctly across small, medium, and large inputs
- [ ] Existing `test_strategy` tests pass; full `make test` suite is green
