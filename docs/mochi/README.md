# Mochi study cards

Converted from `docs/anki/q*-cards.md` and `docs/questions.md`. [Mochi](https://mochi.cards/) cards are **Markdown**; flashcard sides are split with `---` on its own line ([card docs](https://mochi.cards/docs/cards/)).

## Deck folders (by TOC section)

| TOC section | Folder | Questions |
| --- | --- | --- |
| C++ Basics and Language Features | [`cpp-basics-and-language-features/`](cpp-basics-and-language-features/) | 1–10 |
| Memory Management and Pointers | [`memory-management-and-pointers/`](memory-management-and-pointers/) | 11–20 |

Each question has its **own `.md` file** with multiple cards inside (delimiter `%%%MOCHI_CARD%%%`).

## Import (single or multiple files)

1. Open **Mochi** (desktop or web).
2. Create or open a deck (suggested: **`CPP::01-Basics`**).
3. **Import** → **Markdown** → select one or more question files.
4. **Card delimiter:** `%%%MOCHI_CARD%%%` (`---` is front/back **inside** each card).
5. Confirm the preview, then import.

### Avoid blank cards

When Mochi splits on `%%%MOCHI_CARD%%%`, everything **before the first delimiter** becomes its own card. A delimiter on line 1 produces an **empty first card** — one blank per file when batch-importing (e.g. between Q6 and Q7).

- **Do not** put `%%%MOCHI_CARD%%%` before the first card in a file.
- Put it **only between** cards (after card 1’s back, before card 2’s front, etc.).
- **Do not** end a file with a trailing delimiter.

Review history and card order are **not** preserved on Markdown import ([import docs](https://mochi.cards/docs/import-and-export/importing/)).

## Format reference

```markdown
Front question (markdown OK) #tag1 #tag2

---

Back answer (lists, **bold**, `code`, etc.)

%%%MOCHI_CARD%%%
Next front question #tag1 #tag2

---

Next back answer
```

## C++ Basics and Language Features (questions 1–10)

| # | File | Cards |
| --- | --- | --- |
| 1 | [`q01-what-are-the-main-features-of-cpp.md`](cpp-basics-and-language-features/q01-what-are-the-main-features-of-cpp.md) | 10 |
| 2 | [`q02-explain-the-difference-between-c-and-cpp.md`](cpp-basics-and-language-features/q02-explain-the-difference-between-c-and-cpp.md) | 13 |
| 3 | [`q03-what-is-object-oriented-programming-in-cpp.md`](cpp-basics-and-language-features/q03-what-is-object-oriented-programming-in-cpp.md) | 9 |
| 4 | [`q04-what-are-the-access-specifiers-in-cpp.md`](cpp-basics-and-language-features/q04-what-are-the-access-specifiers-in-cpp.md) | 5 |
| 5 | [`q05-explain-the-concept-of-namespaces-in-cpp.md`](cpp-basics-and-language-features/q05-explain-the-concept-of-namespaces-in-cpp.md) | 6 |
| 6 | [`q06-what-is-the-difference-between-struct-and-class-in-cpp.md`](cpp-basics-and-language-features/q06-what-is-the-difference-between-struct-and-class-in-cpp.md) | 5 |
| 7 | [`q07-what-is-a-constructor-and-what-are-its-types-in-cpp.md`](cpp-basics-and-language-features/q07-what-is-a-constructor-and-what-are-its-types-in-cpp.md) | 5 |
| 8 | [`q08-explain-the-concept-of-destructors-in-cpp.md`](cpp-basics-and-language-features/q08-explain-the-concept-of-destructors-in-cpp.md) | 5 |
| 9 | [`q09-what-is-function-overloading-in-cpp.md`](cpp-basics-and-language-features/q09-what-is-function-overloading-in-cpp.md) | 4 |
| 10 | [`q10-what-is-operator-overloading-in-cpp.md`](cpp-basics-and-language-features/q10-what-is-operator-overloading-in-cpp.md) | 5 |

Questions 1–3 match the Anki study decks. Questions 4–20 are synthesized from [`questions.md`](../questions.md).

## Memory Management and Pointers (questions 11–20)

| # | File | Cards |
| --- | --- | --- |
| 11 | [`q11-what-is-dynamic-memory-allocation-in-cpp.md`](memory-management-and-pointers/q11-what-is-dynamic-memory-allocation-in-cpp.md) | 6 |
| 12 | [`q12-explain-the-difference-between-new-and-malloc.md`](memory-management-and-pointers/q12-explain-the-difference-between-new-and-malloc.md) | 5 |
| 13 | [`q13-what-is-a-memory-leak-and-how-can-it-be-prevented.md`](memory-management-and-pointers/q13-what-is-a-memory-leak-and-how-can-it-be-prevented.md) | 5 |
| 14 | [`q14-what-is-a-dangling-pointer.md`](memory-management-and-pointers/q14-what-is-a-dangling-pointer.md) | 5 |
| 15 | [`q15-explain-the-concept-of-smart-pointers-in-cpp.md`](memory-management-and-pointers/q15-explain-the-concept-of-smart-pointers-in-cpp.md) | 6 |
| 16 | [`q16-what-is-the-difference-between-unique-ptr-shared-ptr-and-weak-ptr.md`](memory-management-and-pointers/q16-what-is-the-difference-between-unique-ptr-shared-ptr-and-weak-ptr.md) | 5 |
| 17 | [`q17-how-does-reference-counting-work-in-shared-ptr.md`](memory-management-and-pointers/q17-how-does-reference-counting-work-in-shared-ptr.md) | 5 |
| 18 | [`q18-what-is-the-rule-of-three-in-cpp.md`](memory-management-and-pointers/q18-what-is-the-rule-of-three-in-cpp.md) | 4 |
| 19 | [`q19-what-is-the-rule-of-five-in-cpp.md`](memory-management-and-pointers/q19-what-is-the-rule-of-five-in-cpp.md) | 4 |
| 20 | [`q20-explain-move-semantics-in-cpp.md`](memory-management-and-pointers/q20-explain-move-semantics-in-cpp.md) | 5 |
