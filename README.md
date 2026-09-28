# Technical Cabinet

A central, reusable file cabinet for technical concepts I have actually studied, practiced, and verified.

This is not a linear course. Each sub-cabinet groups related mechanisms, personal explanations, and working examples so I can retrieve what I already learned instead of rebuilding it from first principles.

## Sub-cabinets

| Cabinet | Contents | Verification |
| --- | --- | --- |
| [C++](cabinets/cpp/README.md) | Language fundamentals, systems-oriented concepts, and reusable examples | `make -C cabinets/cpp verify` |

New sub-cabinets should be added only after several durable entries exist. Concepts belong in their primary home and should be cross-linked rather than copied into multiple cabinets.

## Verify everything

```bash
make verify
```

Each sub-cabinet owns its language- or domain-specific verification. The root command runs all of them.

## Website

The portfolio renders these canonical files under `/cabinet/`. Website presentation must not become a second copy of the notes.

## License

This cabinet is dedicated to the public domain under [CC0 1.0](LICENSE). Use, modify, and redistribute it without asking permission or providing attribution.

