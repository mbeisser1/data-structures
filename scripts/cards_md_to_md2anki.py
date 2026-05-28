#!/usr/bin/env python3
"""Convert docs/anki/q*-cards.md study files to Markdown2Anki format."""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

# Reuse parsers from cards_md_to_anki_txt.py logic (inlined minimally)
FRONT_RE = re.compile(r"^\*\*Front:\*\*\s*(.+)$", re.MULTILINE)
BACK_RE = re.compile(r"^\*\*Back:\*\*\s*(.*)$", re.MULTILINE)
CARD_SECTIONS_RE = re.compile(
    r"^## Card \d+ — ([^\n]+)\n(.*?)(?=\n---\n|\n## Card |\n## Optional |\n## Card index|\Z)",
    re.DOTALL | re.MULTILINE,
)


def parse_cards(text: str) -> list[tuple[str, str, str]]:
    """Return (label, front, back) per card."""
    cards: list[tuple[str, str, str]] = []
    for label, body in CARD_SECTIONS_RE.findall(text):
        if "**Front:**" not in body:
            continue
        label = label.strip()
        fm = FRONT_RE.search(body)
        bm = BACK_RE.search(body)
        if not fm or not bm:
            continue
        front = fm.group(1).strip()
        back_parts: list[str] = []
        if bm.group(1).strip():
            back_parts.append(bm.group(1).strip())
        rest = body[bm.end() :].strip()
        if rest:
            back_parts.append(rest)
        back_raw = "\n\n".join(back_parts)
        back_raw = re.split(r"\n\*Source:", back_raw, maxsplit=1)[0].strip()
        cards.append((label, front, back_raw))
    return cards


def to_md2anki(cards: list[tuple[str, str, str]]) -> str:
    blocks: list[str] = []
    for label, front, back in cards:
        # Markdown2Anki: ## - removes front tab on flip; ## B = back tab
        blocks.append(f"## - [{label}]\n\n{front}\n\n## B [Answer]\n\n{back}\n")
    return "\n---\n\n".join(blocks) + "\n"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("markdown", type=Path)
    parser.add_argument(
        "-o",
        "--output",
        type=Path,
        help="Output .md for md2anki (default: docs/anki/md2anki/<stem>.md)",
    )
    args = parser.parse_args()
    text = args.markdown.read_text(encoding="utf-8")
    cards = parse_cards(text)
    if not cards:
        print(f"No cards in {args.markdown}", file=sys.stderr)
        return 1
    out = args.output or Path("docs/anki/md2anki") / f"{args.markdown.stem}.md"
    out.parent.mkdir(parents=True, exist_ok=True)
    header = (
        f"<!-- Markdown2Anki source: converted from {args.markdown.name} -->\n"
        f"<!-- Run: md2anki -f {out} -->\n\n"
    )
    out.write_text(header + to_md2anki(cards), encoding="utf-8")
    print(f"Wrote {len(cards)} cards to {out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
