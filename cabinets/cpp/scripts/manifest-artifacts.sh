#!/usr/bin/env bash

set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$repo_root"

manifest="artifacts/macos-arm64/SHA256SUMS"

find artifacts/macos-arm64 -type f \
  ! -name README.md \
  ! -name SHA256SUMS \
  -print0 \
  | sort -z \
  | xargs -0 shasum -a 256 > "$manifest"

printf 'updated  %s\n' "$manifest"

