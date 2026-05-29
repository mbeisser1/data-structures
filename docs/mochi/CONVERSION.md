# Converting `questions.md` to Mochi cards

How Mochi flashcard files in this repo are produced from [`questions.md`](../questions.md), and how to keep coverage high when adding new questions.

See also [`README.md`](README.md) for import instructions and file layout.

---

## Sources and scope

| Source | Used for | Role |
| --- | --- | --- |
| [`docs/questions.md`](../questions.md) | Q1–100 | **Canonical content** — headings, prose, bullets, code blocks |
| [Mochi docs](https://mochi.cards/docs/cards/) | All files | **Import format** — `---` for front/back, custom delimiter between cards |

**One question → one file**, named after the TOC entry:

```text
docs/mochi/<toc-section>/qNN-slug-from-question-title.md
```

Example: `### 17. How does reference counting work in shared_ptr?` → `q17-how-does-reference-counting-work-in-shared-ptr.md`

---

## Mochi file format (hard constraints)

```markdown
Front question (markdown OK) #qNN #topic-tag #section-tag

---

Back answer (lists, **bold**, `code`, fenced blocks)

%%%MOCHI_CARD%%%
Next front question #qNN #topic-tag #section-tag

---

Next back answer
```

Rules learned from import:

- **No leading `%%%MOCHI_CARD%%%`** — Mochi treats text before the first delimiter as a card, producing blank cards on batch import.
- **No trailing delimiter** at EOF.
- **No HTML comments** — they appear on imported cards.
- **Tags inline on the front line** — e.g. `#q17 #shared-ptr #memory-pointers`.
- **Blank line after `---`** before list backs (markdownlint + readability).

---

## Card decomposition strategy

Each `### N. Question` section in `questions.md` is treated as a **mini-chapter**. Cards are carved out by **heading level and content type**, not by copying the whole answer onto one card.

### Typical card set per question (4–6 cards)

| Card type | Front pattern | Source in `questions.md` |
| --- | --- | --- |
| **Definition / overview** | “What is X?” / main question text | Intro paragraph under `### N.` |
| **Mechanism / subtopic** | “What is the control block?” / “How do X and Y differ?” | `####` / `#####` subsections |
| **Code sample** | “Show an example of …” | Every ` ```cpp ` block worth testing |
| **Best practices / pitfalls** | “How do you prevent …?” / “What are performance notes?” | “Key Points”, “Best Practices”, “Performance Considerations”, etc. |
| **Synthesis (60s)** | “In about 60 seconds, explain …” | Compressed recap of all bullets from that question |

### Example: Q17 mapping

| `questions.md` section | Mochi card |
| --- | --- |
| Intro paragraph (reference counting definition) | Card 1 — overview |
| `#### Code Example` (`use_count()` demo) | Card 2 — code (copied verbatim) |
| `##### Separate Control Block` + control-block bullet list | Card 3 — control block |
| `#### Performance Considerations` + `#### Thread Safety` | Card 4 — perf / thread-safety |
| (synthesized) | Card 5 — 60-second recap |

---

## Prompt template

Use this when asking an agent (or yourself) to convert a batch of questions:

```text
Create Mochi flashcard files for questions [N–M] from docs/questions.md.

TOC section: [section name]
Output folder: docs/mochi/[section-slug]/

For each ### N. question in questions.md:
1. One .md file per question, named qNN-slug-from-title.md
2. Split into atomic flashcards using Mochi format (see docs/mochi/README.md)
3. Map each #### / ##### subsection to its own card where it makes sense
4. Include code samples from questions.md on dedicated "Show an example…" cards
5. End each file with an "In about 60 seconds…" synthesis card
6. Tags on every front: #qNN #topic-tag #section-tag
7. Lists of 3+ items → bullet lists (not comma-separated prose)
8. Do NOT put MOCHI_CARD delimiter before the first card or after the last
9. Preserve technical accuracy; compress prose for flashcard backs, don't invent facts
10. Update docs/mochi/README.md card counts
```

Follow-up prompts that refined the existing decks:

- *“Individual files for Q1–10”* → file-per-question layout
- *“Fix blank cards”* → delimiter placement rule
- *“Add code samples from questions.md to Q11–20”* → explicit code-extraction pass
- *“Prefer bullets for 3+ list items”* → formatting pass on backs

---

## Ensuring coverage of `questions.md`

This is **structured extraction**, not a full verbatim dump. Coverage is enforced by a checklist per question.

### Step A — Read the full question block

For each `### N.`, read until the next `### N+1.` (or next `##` section). That block is the **coverage boundary**.

### Step B — Inventory content units

Scan for:

- Intro / definition paragraphs
- Numbered or bulleted lists
- `####` / `#####` subheadings
- Fenced ` ```cpp ` blocks
- “Key Points”, “Best Practices”, “Modern C++”, “Thread Safety”, etc.

Each unit should land on **at least one card** (definition card, list card, or synthesis card).

### Step C — Assign cards

```text
Intro paragraph          → Card 1 (definition)
Each major #### section  → 1 card (or split if long)
Each code block          → 1 "Show example" card (back = code + 1–2 bullets of context)
Lists / key points       → Bullets on relevant cards
Everything important     → Repeated in synthesis card
```

### Step D — Synthesis card as coverage safety net

The **“In about 60 seconds…”** card at the end is deliberate: it forces a second pass over all subsections. If something important only appeared once deep in the source, it should still appear in the recap.

### Step E — Code fidelity

For Q11–20, code blocks were **copied from `questions.md`**, not rewritten. Comments may be trimmed; structure and APIs stay the same.

### Step F — Card count sanity check

[`README.md`](README.md) tracks cards per file. A question with 4 subsections + 2 code blocks + synthesis ≈ 5–7 cards. If a rich `questions.md` section yields only 3 cards, something was likely skipped.

---

## What is intentionally compressed or omitted

Not everything in `questions.md` becomes its own card:

| Often skipped as standalone cards | Why |
| --- | --- |
| Very long “comprehensive” demo code (e.g. Q4’s full `MyClass` example) | Too large for one back; concepts already covered in bullet cards |
| Redundant prose that repeats bullet lists | Merged into list cards |
| Deep tangents belonging to other questions | Belongs in a different Q file |

The goal is **most/all concepts and code that matter for recall**, not a 1:1 line mapping.

---

## Formatting conventions (study UX)

- **Bold** key terms on backs (`**control block**`, **`shared_ptr`**)
- **Bullets** for 3+ related items
- **Nested bullets** for control-block fields, smart-pointer types, etc.
- **Short fronts** — one clear question per card
- **Code on its own card** when the question is “show me how”

### Concept + code (two cards)

When a subsection has both an idea and a code sample, use **two cards** — do not replace the concept question with `Show …`:

| Card | Front | Back |
| --- | --- | --- |
| **Concept** | The subsection question (e.g. “What is the relationship between a class and an object?”) | Prose and/or bullets only |
| **Code follow-on** | `Show …` + hint clause | Fenced `cpp` block only (or code + minimal output note) |

Example pair (Q03):

```markdown
What is the relationship between a class and an object in C++? #q03 #oop

---
A **`class`** is the **blueprint**; an **object** is a **specific instance** …

%%%MOCHI_CARD%%%
Show a class and object example. Define `Car` with private `model`/`year` … #q03 #oop

---
```cpp
class Car { … };
```
```

Q02 already follows this (concept card, then `Show` card with code only).

### Code card fronts (title + hint)

Code-recall cards use a **two-part front**:

```text
Show [original title]. [Hint clause: scaffold without revealing the tested mechanism.]
```

| Include in hint | Avoid in hint |
| --- | --- |
| Named types from the snippet (`IsEven`, `SimpleAllocator`) | The mechanism under test (`operator()`, `iterator_traits` if that is the recall target) |
| Algorithm + container (`remove_if` on `vector<int>`) | Full solution or copied back text |
| Input data and **expected outcome** | Naming the exact member/function that is the answer |

Example:

```markdown
Show a unary predicate functor with `std::remove_if`. Implement `IsEven` as a callable that returns true for even integers; use it to remove evens from `nums` and erase the tail. #q57 #functors #stl
```

The reader knows struct name, predicate role, and algorithm — but must still produce **`operator()`** themselves.

Example (control block — prefer bullets over comma-separated prose):

```markdown
- Separate **control block** holds:
  - **Strong count**
  - **Weak count**
  - Pointer to managed object
  - Optional custom **deleter**
```

---

## Reusable workflow for new questions (Q21+)

1. Read `### N.` through the next `###` in `questions.md`
2. List: intro, subheadings, bullets, code blocks
3. Draft 4–7 card fronts (definition → subtopics → code → synthesis)
4. Write backs from source text (compress, don’t paraphrase away meaning)
5. Copy code blocks verbatim where they exist
6. Apply Mochi format + tags + bullet rule
7. Update [`README.md`](README.md) card count
8. Import preview in Mochi — check for blank cards and comment leakage

---

## Current coverage (Q1–100) — complete

| Range | Coverage |
| --- | --- |
| **Q1–10** | Good — code cards use **Show … + hint** (Q51–60 pattern); Q02 splits concept vs code; Q04 includes access-specifier hierarchy example |
| **Q11–20** | Good — subsections + code samples + synthesis; main prose captured |
| **Q21–30** | Good — hand-crafted OOP section with code samples + synthesis cards |
| **Q31–40** | Good — hand-crafted templates section with code samples + synthesis cards |
| **Q41–50** | Good — hand-crafted exception handling section with code samples + synthesis cards |
| **Q51–60** | Good — hand-crafted STL section with code samples + synthesis cards |
| **Q61–70** | Good — hand-crafted concurrency section with code samples + synthesis cards |
| **Q71–80** | Good — hand-crafted C++11+ section with code samples + synthesis cards |
| **Q81–90** | Good — hand-crafted advanced C++ section with code samples + synthesis cards |
| **Q91–100** | Good — hand-crafted performance section with code samples + synthesis cards |

For **full** coverage (every code sample, every “Key Points” bullet as its own card), run an audit: one checklist row per `####` heading and per ` ```cpp ` block per question.
