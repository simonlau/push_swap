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

## Allowed Functions

Besides the functions provided by `libftprintf.a` (compiled from `ft_printf/libft/`), the only permitted C library functions in push_swap source are:

- `read`
- `write`
- `malloc`
- `free`
- `exit`

Reuse libft functions wherever possible instead of reimplementing them. Useful libft functions for this project include `ft_atoi`, `ft_isdigit`, `ft_itoa`, `ft_putnbr_fd`, `ft_strlen`, `ft_strncmp`, `ft_split`, `ft_calloc`, `ft_strdup`, and `ft_strchr` — all declared in `ft_printf/libft/libft.h`. Include `ft_printf/libft/libft.h` where needed; `libftprintf.a` is linked automatically by the Makefile.

Do not call any other libc functions (e.g., `printf`, `atoi`, `itoa`, `calloc` directly). Use `write` for output and `ft_*` equivalents from libft for everything else.

