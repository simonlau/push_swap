# Issue tracker: Local markdown

Issues and specs for this repo live as markdown files under `.scratch/<feature>/` in this repo.

## Conventions

- **Create an issue**: create `.scratch/<feature>/<slug>.md` with a `title:` frontmatter field, then the issue body.
- **Read an issue**: read the `.scratch/<feature>/<slug>.md` file.
- **List issues**: list files under `.scratch/<feature>/` (and `.scratch/` top-level).
- **Comment on an issue**: append a dated entry to the issue file.
- **Apply / remove labels**: edit the `labels:` frontmatter field on the issue file.
- **Close**: add `status: closed` to the frontmatter, or prefix the filename with `closed-`.

## Pull requests as a request surface

**PRs as a request surface: no.**

## When a skill says "publish to the issue tracker"

Create a markdown file under `.scratch/<feature>/`.

## When a skill says "fetch the relevant ticket"

Read the corresponding `.scratch/<feature>/<slug>.md` file.
