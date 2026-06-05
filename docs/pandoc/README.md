# PDF export for `questions-pdf.md`

Build a print-ready PDF with:

- **Title page** → **TOC with page numbers** → **body** on separate pages
- **Part titles** (`##`): each starts on a new page (after the preceding question); first `###` in the part flows on the same page as the title
- **Question breaks**: each later `###` question in a part starts on a new page
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
| `##` part titles | Latin Modern Roman, bold | `\LARGE` (~17pt) |
| `###` questions | Latin Modern Roman, bold | `\Large` (~14pt) |
| Code blocks | DejaVu Sans Mono (`Scale=0.85`) | ~9.4pt |
| Images | scaled to fit | max width = text width, max height = 85% page |
| Margins | `geometry` in `pdf.yaml` | 0.75in all sides |

Each `####` section heading is underlined in the PDF (e.g. <u>Commonly Used Algorithms</u>) and kept with the content that follows (e.g. a code block is not orphaned on the next page). `#####` sub-headings are unchanged.

**Page layout**

1. Page 1 — title (`100 C++ interview questions (devinterview.io)`)
2. Following pages — auto-generated table of contents with page numbers
3. Body — each `##` part title on a new page (after the previous question ends), with its first `###` question on the same page; later questions in that part start on new pages

**Code blocks**

- Gray border + light fill (`mdframed`)
- Long lines wrap (`fvextra` `breaklines` / `breakanywhere`)
- Blocks shorter than one page are not split (`needspace`)

## Config files

| File | Role |
|------|------|
| [`pdf.yaml`](pdf.yaml) | Pandoc defaults (title, TOC, margins, `xelatex`) |
| [`embed-images.lua`](embed-images.lua) | Decodes embedded `data:image/...` diagrams for PDF output |
| [`group-code-headings.lua`](group-code-headings.lua) | Keeps `####` headings with following code blocks (incl. intro text) |
| [`pdf-header.tex`](pdf-header.tex) | Footer, page breaks, heading sizes, image scale, code box |
| [`markdown-pdf.css`](markdown-pdf.css) | Fallback CSS for VS Code **Markdown PDF** |

## Fallback: VS Code Markdown PDF

The workspace [`.vscode/settings.json`](../../.vscode/settings.json) uses `markdown-pdf.css` with an empty header template and centered footer page number.

Limitations vs Pandoc: no TOC page numbers, no title/section page-break logic.

## Editing

After changing `questions-pdf.md`, re-run `./scripts/build-questions-pdf.sh`.

To sync from the main Q&A doc, update `questions-pdf.md` manually (no auto-sync script yet).
