#!/usr/bin/env bash

set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$repo_root"

cxx="${CXX:-clang++}"
cc="${CC:-clang}"
cxx_flags=(-std=c++20 -Wall -Wextra -Wpedantic -Werror)
c_flags=(-std=c17 -Wall -Wextra -Wpedantic -Werror)
build_root="build/verified"
compiled=0
skipped=0

rm -rf "$build_root"
mkdir -p "$build_root/concepts" "$build_root/snippets"

compile_cpp() {
  local source="$1"
  local output="$2"
  local expected="${source%.cpp}.expected.txt"

  mkdir -p "$(dirname "$output")"
  "$cxx" "${cxx_flags[@]}" "$source" -o "$output"
  printf 'verified  %s\n' "$source"
  compiled=$((compiled + 1))

  if [[ -f "$expected" ]]; then
    "$output" > "${output}.actual"
    diff -u "$expected" "${output}.actual"
    rm "${output}.actual"
    printf 'output    %s\n' "$expected"
  fi
}

while IFS= read -r -d '' source; do
  if [[ ! -s "$source" ]]; then
    printf 'draft     %s (empty example)\n' "$source"
    skipped=$((skipped + 1))
    continue
  fi

  concept="$(basename "$(dirname "$source")")"
  name="$(basename "${source%.cpp}")"
  compile_cpp "$source" "$build_root/concepts/$concept/$name"
done < <(find concepts -mindepth 2 -maxdepth 2 -name '*.cpp' -print0 | sort -z)

while IFS= read -r -d '' source; do
  name="$(basename "${source%.cpp}")"
  compile_cpp "$source" "$build_root/snippets/experiments/$name"
done < <(find snippets/experiments -maxdepth 1 -name '*.cpp' -print0 | sort -z)

while IFS= read -r -d '' source; do
  name="$(basename "${source%.c}")"
  mkdir -p "$build_root/snippets/rng"
  "$cc" "${c_flags[@]}" -c "$source" -o "$build_root/snippets/rng/$name.o"
  printf 'verified  %s\n' "$source"
  compiled=$((compiled + 1))
done < <(find snippets/rng -maxdepth 1 -name '*.c' -print0 | sort -z)

if command -v pkg-config >/dev/null 2>&1 && pkg-config --exists raylib; then
  mkdir -p "$build_root/snippets/raylib-3d"
  read -r -a raylib_cflags <<< "$(pkg-config --cflags raylib)"
  read -r -a raylib_libs <<< "$(pkg-config --libs raylib)"
  raylib_system_cflags=()

  for flag in "${raylib_cflags[@]}"; do
    if [[ "$flag" == -I* ]]; then
      raylib_system_cflags+=("-isystem" "${flag#-I}")
    else
      raylib_system_cflags+=("$flag")
    fi
  done

  "$cxx" "${cxx_flags[@]}" snippets/raylib-3d/main.cpp \
    "${raylib_system_cflags[@]}" \
    "${raylib_libs[@]}" \
    -o "$build_root/snippets/raylib-3d/game"
  printf 'verified  snippets/raylib-3d/main.cpp\n'
  compiled=$((compiled + 1))
else
  printf 'optional  snippets/raylib-3d/main.cpp (raylib not installed)\n'
  skipped=$((skipped + 1))
fi

printf '\n%d examples verified; %d drafts or optional examples skipped.\n' "$compiled" "$skipped"
