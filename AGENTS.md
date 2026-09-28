# Project guidance

This repository is Matt's reusable C++ file cabinet: concise personal explanations and working fragments organized for retrieval, not a linear textbook.

## Promotion rules

- Treat working code and observed behavior as source material; do not turn raw conversation transcripts into notes.
- Promote a concept only after Matt has used or deliberately studied it and approves the proposed update.
- Treat the existing concept notes as the style corpus. Mirror Matt's direct explanations, concrete analogies, selective emphasis, and humor without manufacturing a generic textbook voice.
- Handle the consolidation work after a learning milestone: reconstruct the mechanism from the code, debugging evidence, and conversation so Matt does not have to repeat the entire learn-practice-compile-fix cycle just to take notes.
- Ask Matt only about genuine ambiguity, personal judgment, or wording that cannot be recovered from the work itself.
- Do not force drawers into a curriculum or polish every note into an essay.
- Separate verified facts from intuition, platform-specific observations, and open questions.
- Prefer one focused example over a large project excerpt.
- Update `README.md` when adding or renaming a drawer.
- Run `make verify` before describing an example as verified.
- Do not commit, push, publish, or modify the portfolio repository without Matt's explicit request.

## Drawer shape

```text
concepts/concept-name/
├── notes.md
├── example-name.cpp
└── expected.txt        # optional; enables output verification
```

Empty example files are drafts and must not be presented as verified.
