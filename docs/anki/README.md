# Anki study cards (Markdown2Anki)

Cards are authored as human-readable study markdown (`q*-cards.md`), then converted to [Markdown2Anki](https://github.com/Mochitto/Markdown2Anki) format and imported into Anki with the **Markdown2Anki** note type (split-screen, syntax highlighting, tabs).

## One-time setup (pipx)

Debian/Ubuntu blocks `pip install` on system Python (PEP 668). Use **pipx**:

```bash
sudo apt install pipx python3-venv   # once, if missing
pipx ensurepath                      # once; then reopen shell or: source ~/.bashrc
pipx install Markdown2Anki
md2anki                              # first run: guided setup → import markdown2anki.apkg
```

Confirm `md2anki` is on your PATH: `which md2anki` (usually `~/.local/bin/md2anki`).

Upgrade later: `pipx upgrade Markdown2Anki`

### No pipx / fallback: plain `.txt` import

Use the **legacy `.txt`** path (HTML in fields, Anki **Basic** note type). No `md2anki`, no custom note types:

```bash
python3 scripts/cards_md_to_anki_txt.py docs/anki/q01-cpp-features-cards.md
# → docs/anki/q01-cpp-features-cards.txt
```

In Anki: **File → Import** → pick the `.txt`, tab separator, **Allow HTML**.

Trade-off: no split-screen tabs or Pygments highlighting; code blocks are plain `<pre>` HTML.

Import **`markdown2anki.apkg`** from the folder `md2anki` chose at setup (double-click or **File → Import**). That installs the **Markdown2Anki** note types.

## Workflow in this repo

| Step | Command / file |
|------|----------------|
| Edit study cards | `docs/anki/q01-cpp-features-cards.md`, `q02-…`, `q03-…` |
| Convert to md2anki syntax | `python3 scripts/cards_md_to_md2anki.py docs/anki/q01-cpp-features-cards.md` |
| Output | `docs/anki/md2anki/q01-cpp-features-cards.md` (one file per question) |
| Build CSV for Anki | `md2anki -f docs/anki/md2anki/q01-cpp-features-cards.md` |
| Import | **File → Import** → `basic_anki_cards.csv` (comma separator, **Markdown2Anki** note type, **Allow HTML**) |

Regenerate all three decks (convert + `md2anki`):

```bash
./scripts/anki-md2anki.sh
```

Or one deck:

```bash
./scripts/anki-md2anki.sh docs/anki/q03-oop-cpp-cards.md
```

Manual steps only:

```bash
python3 scripts/cards_md_to_md2anki.py docs/anki/q01-cpp-features-cards.md
md2anki -f docs/anki/md2anki/q01-cpp-features-cards.md
```

Suggested deck on import: **`CPP::01-Basics`** (matches the `Deck:` line in each `q*-cards.md` header).

## Markdown2Anki card shape

Each card is separated by `---`. Front/back use tabs:

```markdown
## - [Short tab title]

Front question (markdown)

## B [Answer]

Back content (markdown, code fences, lists)

---
```

- `## -` — front tab (hidden when you flip to the back)
- `## B` — back tab
- Tab titles are plain text (no `**bold**` in the bracket label)

See the [project README](https://github.com/Mochitto/Markdown2Anki#usage) for clozes, images, Obsidian links, and themes.

## Files

| Study source | md2anki input | Cards |
|--------------|---------------|-------|
| `q01-cpp-features-cards.md` | `md2anki/q01-cpp-features-cards.md` | 10 |
| `q02-c-vs-cpp-cards.md` | `md2anki/q02-c-vs-cpp-cards.md` | 13 |
| `q03-oop-cpp-cards.md` | `md2anki/q03-oop-cpp-cards.md` | 9 |

## Other export paths

| Approach | Install | Notes |
|----------|---------|--------|
| **Markdown2Anki** (default) | `pipx install Markdown2Anki` | `docs/anki/md2anki/*.md` + custom note type |
| **Plain `.txt` import** | none | `scripts/cards_md_to_anki_txt.py` → `q*-cards.txt`, Anki **Basic** |
