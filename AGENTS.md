## Agent skills

### Issue tracker

Issues live as markdown files under `.scratch/<feature>/`. See `docs/agents/issue-tracker.md`.

### Triage labels

Default triage label vocabulary: `needs-triage`, `needs-info`, `ready-for-agent`, `ready-for-human`, `wontfix`. See `docs/agents/triage-labels.md`.

### Domain docs

Single-context layout: one `GLOSSARY.md` plus `docs/adr/` at the repo root. See `docs/agents/domain.md`.

## 42 Norm Compliance

This project follows the 42 School Norm (v4.1), documented in `wiki/42-school/the-norm.md`. Compliance is checked with `norminette`.

Run norminette on the push_swap source files (not the `ft_printf` library):

```
norminette push_swap.h *.c
```

All `.c` and `.h` files under the repo root must pass with no errors before the work is considered complete.

