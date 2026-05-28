#!/usr/bin/env bash
# Build Anki CSV from study markdown via Markdown2Anki (pipx).
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

if ! command -v md2anki >/dev/null 2>&1; then
  echo "md2anki not found. Install with:" >&2
  echo "  pipx install Markdown2Anki" >&2
  echo "  md2anki   # first run: guided setup + import markdown2anki.apkg" >&2
  exit 1
fi

if [[ $# -eq 0 ]]; then
  set -- docs/anki/q01-cpp-features-cards.md \
           docs/anki/q02-c-vs-cpp-cards.md \
           docs/anki/q03-oop-cpp-cards.md
fi

for src in "$@"; do
  python3 scripts/cards_md_to_md2anki.py "$src"
  md_file="$ROOT/docs/anki/md2anki/$(basename "${src%.md}").md"
  md2anki -f "$md_file"
  echo "Import basic_anki_cards.csv from: $(pwd)"
done
