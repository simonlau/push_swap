# 02: Parsing & Validation

**What to build:** Strict Validation of command-line arguments into a Stack: reject duplicate values, non-numeric input, and integer overflow by printing "Error" to stderr and exiting with code 1; empty input is a graceful no-op. This is the gate that decides whether sorting proceeds or the program errors out.

**Blocked by:** 01: Stack primitives & Operations

**Status:** ready-for-agent

- [ ] Valid numeric arguments parse into a Stack without error
- [ ] Duplicate values print "Error" to stderr and exit code 1
- [ ] Non-numeric input prints "Error" to stderr and exit code 1
- [ ] Integer overflow prints "Error" to stderr and exit code 1
- [ ] No arguments is a graceful no-op with no error
- [ ] Existing `test_parser` tests pass
