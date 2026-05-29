#!/usr/bin/env python3
"""Replace placeholder Show hints with entries from show_hints_q11_50.json."""

import json
import re
from pathlib import Path

REPO = Path(__file__).resolve().parents[3]
MOCHI = REPO / "docs" / "mochi"
SKIP = {"cpp-basics-and-language-features", "standard-template-library", "scripts"}
PLACEHOLDER = "Implement the pattern described on the concept card"

_HINTS_PATH = Path(__file__).with_name("show_hints_q11_50.json")
HINTS: dict[str, str] = {}
if _HINTS_PATH.exists():
    HINTS = json.loads(_HINTS_PATH.read_text())


def main() -> None:
    if not HINTS:
        print("Missing show_hints_q11_50.json")
        return
    fixed = 0
    for path in sorted(MOCHI.rglob("q*.md")):
        if path.parent.name in SKIP:
            continue
        cards = path.read_text().split("\n%%%MOCHI_CARD%%%\n")
        last_concept: str | None = None
        changed = False
        for i, card in enumerate(cards):
            parts = card.split("\n---\n", 1)
            if len(parts) < 2:
                continue
            front = parts[0].strip().split("\n")[0]
            if PLACEHOLDER in front:
                key = last_concept if last_concept in HINTS else None
                if key:
                    cards[i] = card.replace(front, HINTS[key], 1)
                    fixed += 1
                    changed = True
            if not front.startswith("Show ") and not front.lower().startswith("in about 60"):
                last_concept = front
        if changed:
            path.write_text("\n%%%MOCHI_CARD%%%\n".join(cards))
    print(f"Fixed {fixed} placeholder fronts")


if __name__ == "__main__":
    main()
