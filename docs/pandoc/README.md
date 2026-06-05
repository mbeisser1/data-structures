# PDF export for `questions-pdf.md`

Build a print-ready PDF with:

- **Title page** → **TOC with page numbers** → **body** on separate pages
- **Section breaks**: each `##` part (e.g. “C++ Basics…”) starts on a new page
- **Question breaks**: each `###` question starts on a new page
- **Footer page numbers** only (no title/date/URL header)
- **Code blocks**: bordered box, line-wrapped, kept on one page when they fit

## Install (Debian/Ubuntu)

```bash
sudo apt install pandoc texlive-xetex texlive-latex-extra
```

Optional if build fails on missing LaTeX files:

```bash
sudo apt install texlive-fonts-recommended texlive-latex-recommended
```

## Build

From the repo root:

```bash
./scripts/build-questions-pdf.sh
```

Output: [`docs/questions-pdf.pdf`](../questions-pdf.pdf) (rebuild to refresh; last build ~170 pages at 0.75in margins).

Source: [`docs/questions-pdf.md`](../questions-pdf.md) — title is in [`pdf.yaml`](pdf.yaml), not duplicated in the markdown.

## Typography and layout

| Element | Font | Size |
|---------|------|------|
| Body | Latin Modern Roman (LaTeX default) | 11pt |
| Code blocks | DejaVu Sans Mono (`Scale=0.85`) | ~9.4pt |
| Margins | `geometry` in `pdf.yaml` | 0.75in all sides |

Each `####` section heading is underlined in the PDF (e.g. <u>Commonly Used Algorithms</u>). `#####` sub-headings are unchanged.

**Page layout**

1. Page 1 — title (`100 C++ interview questions (devinterview.io)`)
2. Following pages — auto-generated table of contents with page numbers
3. New page — first `##` part; each later `##` part starts on a new page (`\subsection` in LaTeX)
4. Each `###` question starts on a new page (`\subsubsection` in LaTeX)

**Code blocks**

- Gray border + light fill (`mdframed`)
- Long lines wrap (`fvextra` `breaklines` / `breakanywhere`)
- Blocks shorter than one page are not split (`needspace`)

## Config files

| File | Role |
|------|------|
| [`pdf.yaml`](pdf.yaml) | Pandoc defaults (title, TOC, margins, `xelatex`) |
| [`pdf-header.tex`](pdf-header.tex) | Footer, page breaks, code box, line wrap |
| [`markdown-pdf.css`](markdown-pdf.css) | Fallback CSS for VS Code **Markdown PDF** |

## Fallback: VS Code Markdown PDF

The workspace [`.vscode/settings.json`](../../.vscode/settings.json) uses `markdown-pdf.css` with an empty header template and centered footer page number.

Limitations vs Pandoc: no TOC page numbers, no title/section page-break logic.

## Editing

After changing `questions-pdf.md`, re-run `./scripts/build-questions-pdf.sh`.

To sync from the main Q&A doc, update `questions-pdf.md` manually (no auto-sync script yet).
