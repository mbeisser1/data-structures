# Mochi study cards

Converted from [`questions.md`](../questions.md). [Mochi](https://mochi.cards/) cards are **Markdown**; flashcard sides are split with `---` on its own line ([card docs](https://mochi.cards/docs/cards/)).

**How cards are built:** see [`CONVERSION.md`](CONVERSION.md) for the decomposition strategy, prompt template, and coverage checklist.

## Deck folders (by TOC section)

| TOC section | Folder | Questions |
| --- | --- | --- |
| C++ Basics and Language Features | [`cpp-basics-and-language-features/`](cpp-basics-and-language-features/) | 1–10 |
| Memory Management and Pointers | [`memory-management-and-pointers/`](memory-management-and-pointers/) | 11–20 |
| Object-Oriented Programming Concepts | [`object-oriented-programming-concepts/`](object-oriented-programming-concepts/) | 21–30 |
| Templates and Generic Programming | [`templates-and-generic-programming/`](templates-and-generic-programming/) | 31–40 |
| Exception Handling | [`exception-handling/`](exception-handling/) | 41–50 |
| Standard Template Library (STL) | [`standard-template-library/`](standard-template-library/) | 51–60 |
| Concurrency and Multithreading | [`concurrency-and-multithreading/`](concurrency-and-multithreading/) | 61–70 |
| C++11 and Beyond Features | [`cpp11-and-beyond-features/`](cpp11-and-beyond-features/) | 71–80 |
| Advanced C++ Concepts | [`advanced-cpp-concepts/`](advanced-cpp-concepts/) | 81–90 |
| Performance and Optimization | [`performance-and-optimization/`](performance-and-optimization/) | 91–100 |

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

All **100 questions** are synthesized from [`questions.md`](../questions.md).

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

## Object-Oriented Programming Concepts (questions 21–30)

| # | File | Cards |
| --- | --- | --- |
| 21 | [`q21-what-is-inheritance-in-c-explain-its-types.md`](object-oriented-programming-concepts/q21-what-is-inheritance-in-c-explain-its-types.md) | 5 |
| 22 | [`q22-what-is-polymorphism-and-how-is-it-implemented-in-c.md`](object-oriented-programming-concepts/q22-what-is-polymorphism-and-how-is-it-implemented-in-c.md) | 6 |
| 23 | [`q23-explain-the-concept-of-virtual-functions-in-c.md`](object-oriented-programming-concepts/q23-explain-the-concept-of-virtual-functions-in-c.md) | 6 |
| 24 | [`q24-what-is-a-pure-virtual-function.md`](object-oriented-programming-concepts/q24-what-is-a-pure-virtual-function.md) | 5 |
| 25 | [`q25-what-is-an-abstract-class-in-c.md`](object-oriented-programming-concepts/q25-what-is-an-abstract-class-in-c.md) | 5 |
| 26 | [`q26-explain-the-diamond-problem-in-multiple-inheritance-and-how-to-solve-it.md`](object-oriented-programming-concepts/q26-explain-the-diamond-problem-in-multiple-inheritance-and-how-to-solve-it.md) | 5 |
| 27 | [`q27-what-is-function-hiding-in-c.md`](object-oriented-programming-concepts/q27-what-is-function-hiding-in-c.md) | 5 |
| 28 | [`q28-explain-the-concept-of-friend-functions-and-classes.md`](object-oriented-programming-concepts/q28-explain-the-concept-of-friend-functions-and-classes.md) | 6 |
| 29 | [`q29-what-is-the-difference-between-composition-and-inheritance.md`](object-oriented-programming-concepts/q29-what-is-the-difference-between-composition-and-inheritance.md) | 5 |
| 30 | [`q30-what-is-raii-resource-acquisition-is-initialization-in-c.md`](object-oriented-programming-concepts/q30-what-is-raii-resource-acquisition-is-initialization-in-c.md) | 5 |

## Templates and Generic Programming (questions 31–40)

| # | File | Cards |
| --- | --- | --- |
| 31 | [`q31-what-are-templates-in-c.md`](templates-and-generic-programming/q31-what-are-templates-in-c.md) | 5 |
| 32 | [`q32-explain-the-difference-between-function-templates-and-class-templates.md`](templates-and-generic-programming/q32-explain-the-difference-between-function-templates-and-class-templates.md) | 5 |
| 33 | [`q33-what-is-template-specialization.md`](templates-and-generic-programming/q33-what-is-template-specialization.md) | 4 |
| 34 | [`q34-how-does-template-metaprogramming-work-in-c.md`](templates-and-generic-programming/q34-how-does-template-metaprogramming-work-in-c.md) | 5 |
| 35 | [`q35-what-are-variadic-templates.md`](templates-and-generic-programming/q35-what-are-variadic-templates.md) | 5 |
| 36 | [`q36-explain-the-concept-of-type-traits-in-c.md`](templates-and-generic-programming/q36-explain-the-concept-of-type-traits-in-c.md) | 5 |
| 37 | [`q37-what-is-sfinae-substitution-failure-is-not-an-error.md`](templates-and-generic-programming/q37-what-is-sfinae-substitution-failure-is-not-an-error.md) | 5 |
| 38 | [`q38-how-do-you-implement-a-type-safe-container-using-templates.md`](templates-and-generic-programming/q38-how-do-you-implement-a-type-safe-container-using-templates.md) | 4 |
| 39 | [`q39-what-are-the-advantages-and-disadvantages-of-using-templates.md`](templates-and-generic-programming/q39-what-are-the-advantages-and-disadvantages-of-using-templates.md) | 3 |
| 40 | [`q40-explain-the-concept-of-template-argument-deduction.md`](templates-and-generic-programming/q40-explain-the-concept-of-template-argument-deduction.md) | 5 |

## Exception Handling (questions 41–50)

| # | File | Cards |
| --- | --- | --- |
| 41 | [`q41-what-is-exception-handling-in-c.md`](exception-handling/q41-what-is-exception-handling-in-c.md) | 5 |
| 42 | [`q42-explain-the-try-catch-and-throw-keywords.md`](exception-handling/q42-explain-the-try-catch-and-throw-keywords.md) | 5 |
| 43 | [`q43-what-is-the-purpose-of-the-noexcept-specifier.md`](exception-handling/q43-what-is-the-purpose-of-the-noexcept-specifier.md) | 5 |
| 44 | [`q44-how-do-you-create-custom-exception-classes.md`](exception-handling/q44-how-do-you-create-custom-exception-classes.md) | 5 |
| 45 | [`q45-what-happens-if-an-exception-is-not-caught.md`](exception-handling/q45-what-happens-if-an-exception-is-not-caught.md) | 5 |
| 46 | [`q46-explain-the-concept-of-exception-safety.md`](exception-handling/q46-explain-the-concept-of-exception-safety.md) | 5 |
| 47 | [`q47-what-is-the-difference-between-synchronous-and-asynchronous-exceptions.md`](exception-handling/q47-what-is-the-difference-between-synchronous-and-asynchronous-exceptions.md) | 4 |
| 48 | [`q48-how-do-you-handle-constructor-failures-using-exceptions.md`](exception-handling/q48-how-do-you-handle-constructor-failures-using-exceptions.md) | 4 |
| 49 | [`q49-what-is-the-purpose-of-std-exception-and-its-derived-classes.md`](exception-handling/q49-what-is-the-purpose-of-std-exception-and-its-derived-classes.md) | 5 |
| 50 | [`q50-how-do-you-implement-a-stack-unwinding-mechanism.md`](exception-handling/q50-how-do-you-implement-a-stack-unwinding-mechanism.md) | 5 |

## Standard Template Library (questions 51–60)

| # | File | Cards |
| --- | --- | --- |
| 51 | [`q51-what-is-the-standard-template-library-stl.md`](standard-template-library/q51-what-is-the-standard-template-library-stl.md) | 6 |
| 52 | [`q52-explain-the-difference-between-vector-and-list-in-stl.md`](standard-template-library/q52-explain-the-difference-between-vector-and-list-in-stl.md) | 5 |
| 53 | [`q53-what-are-the-associative-containers-in-stl.md`](standard-template-library/q53-what-are-the-associative-containers-in-stl.md) | 5 |
| 54 | [`q54-how-does-an-unordered-map-work-internally.md`](standard-template-library/q54-how-does-an-unordered-map-work-internally.md) | 5 |
| 55 | [`q55-what-is-the-difference-between-set-and-multiset.md`](standard-template-library/q55-what-is-the-difference-between-set-and-multiset.md) | 5 |
| 56 | [`q56-explain-the-concept-of-iterators-in-stl.md`](standard-template-library/q56-explain-the-concept-of-iterators-in-stl.md) | 6 |
| 57 | [`q57-what-are-function-objects-functors-in-stl.md`](standard-template-library/q57-what-are-function-objects-functors-in-stl.md) | 6 |
| 58 | [`q58-how-do-you-use-algorithms-like-sort-find-and-binary-search-in-stl.md`](standard-template-library/q58-how-do-you-use-algorithms-like-sort-find-and-binary-search-in-stl.md) | 5 |
| 59 | [`q59-what-is-the-purpose-of-std-pair-and-std-tuple.md`](standard-template-library/q59-what-is-the-purpose-of-std-pair-and-std-tuple.md) | 5 |
| 60 | [`q60-explain-the-concept-of-allocators-in-stl.md`](standard-template-library/q60-explain-the-concept-of-allocators-in-stl.md) | 6 |

## Concurrency and Multithreading (questions 61–70)

| # | File | Cards |
| --- | --- | --- |
| 61 | [`q61-what-is-multithreading-in-c.md`](concurrency-and-multithreading/q61-what-is-multithreading-in-c.md) | 5 |
| 62 | [`q62-how-do-you-create-and-manage-threads-using-std-thread.md`](concurrency-and-multithreading/q62-how-do-you-create-and-manage-threads-using-std-thread.md) | 6 |
| 63 | [`q63-explain-the-concept-of-mutex-and-its-types-in-c.md`](concurrency-and-multithreading/q63-explain-the-concept-of-mutex-and-its-types-in-c.md) | 5 |
| 64 | [`q64-what-is-a-deadlock-and-how-can-it-be-prevented.md`](concurrency-and-multithreading/q64-what-is-a-deadlock-and-how-can-it-be-prevented.md) | 5 |
| 65 | [`q65-how-do-you-use-condition-variables-for-thread-synchronization.md`](concurrency-and-multithreading/q65-how-do-you-use-condition-variables-for-thread-synchronization.md) | 5 |
| 66 | [`q66-what-is-the-purpose-of-std-atomic.md`](concurrency-and-multithreading/q66-what-is-the-purpose-of-std-atomic.md) | 5 |
| 67 | [`q67-explain-the-difference-between-std-async-and-std-thread.md`](concurrency-and-multithreading/q67-explain-the-difference-between-std-async-and-std-thread.md) | 5 |
| 68 | [`q68-what-is-a-thread-pool-and-how-would-you-implement-one.md`](concurrency-and-multithreading/q68-what-is-a-thread-pool-and-how-would-you-implement-one.md) | 5 |
| 69 | [`q69-how-do-you-handle-race-conditions-in-c.md`](concurrency-and-multithreading/q69-how-do-you-handle-race-conditions-in-c.md) | 6 |
| 70 | [`q70-explain-the-concept-of-memory-ordering-in-c-concurrency.md`](concurrency-and-multithreading/q70-explain-the-concept-of-memory-ordering-in-c-concurrency.md) | 6 |

## C++11 and Beyond Features (questions 71–80)

| # | File | Cards |
| --- | --- | --- |
| 71 | [`q71-what-are-lambda-expressions-in-c.md`](cpp11-and-beyond-features/q71-what-are-lambda-expressions-in-c.md) | 5 |
| 72 | [`q72-explain-the-auto-keyword-and-type-inference.md`](cpp11-and-beyond-features/q72-explain-the-auto-keyword-and-type-inference.md) | 5 |
| 73 | [`q73-what-is-uniform-initialization-in-cpp11.md`](cpp11-and-beyond-features/q73-what-is-uniform-initialization-in-cpp11.md) | 5 |
| 74 | [`q74-how-does-range-based-for-loop-work.md`](cpp11-and-beyond-features/q74-how-does-range-based-for-loop-work.md) | 5 |
| 75 | [`q75-what-are-delegating-constructors.md`](cpp11-and-beyond-features/q75-what-are-delegating-constructors.md) | 5 |
| 76 | [`q76-explain-the-concept-of-rvalue-references.md`](cpp11-and-beyond-features/q76-explain-the-concept-of-rvalue-references.md) | 5 |
| 77 | [`q77-what-is-perfect-forwarding-in-c.md`](cpp11-and-beyond-features/q77-what-is-perfect-forwarding-in-c.md) | 5 |
| 78 | [`q78-how-do-you-use-std-chrono-for-time-related-operations.md`](cpp11-and-beyond-features/q78-how-do-you-use-std-chrono-for-time-related-operations.md) | 5 |
| 79 | [`q79-what-are-the-improvements-in-smart-pointers-introduced-in-cpp11.md`](cpp11-and-beyond-features/q79-what-are-the-improvements-in-smart-pointers-introduced-in-cpp11.md) | 5 |
| 80 | [`q80-explain-the-concept-of-constexpr.md`](cpp11-and-beyond-features/q80-explain-the-concept-of-constexpr.md) | 6 |

## Advanced C++ Concepts (questions 81–90)

| # | File | Cards |
| --- | --- | --- |
| 81 | [`q81-what-is-crtp-curiously-recurring-template-pattern.md`](advanced-cpp-concepts/q81-what-is-crtp-curiously-recurring-template-pattern.md) | 5 |
| 82 | [`q82-explain-the-concept-of-type-erasure-in-c.md`](advanced-cpp-concepts/q82-explain-the-concept-of-type-erasure-in-c.md) | 5 |
| 83 | [`q83-what-are-fold-expressions-in-cpp17.md`](advanced-cpp-concepts/q83-what-are-fold-expressions-in-cpp17.md) | 4 |
| 84 | [`q84-how-do-you-implement-a-singleton-pattern-in-c.md`](advanced-cpp-concepts/q84-how-do-you-implement-a-singleton-pattern-in-c.md) | 5 |
| 85 | [`q85-what-is-the-purpose-of-std-optional.md`](advanced-cpp-concepts/q85-what-is-the-purpose-of-std-optional.md) | 4 |
| 86 | [`q86-explain-the-concept-of-concepts-in-cpp20.md`](advanced-cpp-concepts/q86-explain-the-concept-of-concepts-in-cpp20.md) | 5 |
| 87 | [`q87-what-are-coroutines-in-cpp20.md`](advanced-cpp-concepts/q87-what-are-coroutines-in-cpp20.md) | 5 |
| 88 | [`q88-how-do-you-use-std-variant-and-std-visit.md`](advanced-cpp-concepts/q88-how-do-you-use-std-variant-and-std-visit.md) | 4 |
| 89 | [`q89-what-is-the-purpose-of-std-any.md`](advanced-cpp-concepts/q89-what-is-the-purpose-of-std-any.md) | 5 |
| 90 | [`q90-explain-the-concept-of-modules-in-cpp20.md`](advanced-cpp-concepts/q90-explain-the-concept-of-modules-in-cpp20.md) | 5 |

## Performance and Optimization (questions 91–100)

| # | File | Cards |
| --- | --- | --- |
| 91 | [`q91-what-is-cache-coherence-and-how-does-it-affect-cpp-program-performance.md`](performance-and-optimization/q91-what-is-cache-coherence-and-how-does-it-affect-cpp-program-performance.md) | 4 |
| 92 | [`q92-how-do-you-optimize-memory-usage-in-cpp-programs.md`](performance-and-optimization/q92-how-do-you-optimize-memory-usage-in-cpp-programs.md) | 5 |
| 93 | [`q93-explain-the-concept-of-branch-prediction-and-its-impact-on-performance.md`](performance-and-optimization/q93-explain-the-concept-of-branch-prediction-and-its-impact-on-performance.md) | 5 |
| 94 | [`q94-what-is-loop-unrolling-and-when-is-it-beneficial.md`](performance-and-optimization/q94-what-is-loop-unrolling-and-when-is-it-beneficial.md) | 4 |
| 95 | [`q95-how-do-you-profile-cpp-code-for-performance-optimization.md`](performance-and-optimization/q95-how-do-you-profile-cpp-code-for-performance-optimization.md) | 5 |
| 96 | [`q96-what-is-the-difference-between-constexpr-and-inline-functions-in-terms-of-performance.md`](performance-and-optimization/q96-what-is-the-difference-between-constexpr-and-inline-functions-in-terms-of-performance.md) | 5 |
| 97 | [`q97-explain-the-concept-of-false-sharing-and-how-to-avoid-it.md`](performance-and-optimization/q97-explain-the-concept-of-false-sharing-and-how-to-avoid-it.md) | 5 |
| 98 | [`q98-how-do-you-optimize-code-for-modern-cpu-architectures-e-g-simd-instructions.md`](performance-and-optimization/q98-how-do-you-optimize-code-for-modern-cpu-architectures-e-g-simd-instructions.md) | 5 |
| 99 | [`q99-what-are-some-techniques-for-reducing-compile-times-in-large-cpp-projects.md`](performance-and-optimization/q99-what-are-some-techniques-for-reducing-compile-times-in-large-cpp-projects.md) | 5 |
| 100 | [`q100-how-do-you-implement-and-use-lock-free-data-structures-for-better-concurrency-performance.md`](performance-and-optimization/q100-how-do-you-implement-and-use-lock-free-data-structures-for-better-concurrency-performance.md) | 6 |
