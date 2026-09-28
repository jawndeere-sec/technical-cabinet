# Legacy macOS ARM64 build artifacts

These executables were present in the original learning directory and are retained as historical artifacts.

They are not authoritative proof that the current source still builds:

- binaries can outlive the source revision that produced them;
- they are specific to macOS on Apple Silicon;
- the original compiler commands and versions were not recorded;
- `legacy-testclasses` originally had the misleading filename `testclasses.cpp` despite being a Mach-O executable.

Run `make verify` for a fresh build of the current examples. `SHA256SUMS` records the retained artifacts exactly.
