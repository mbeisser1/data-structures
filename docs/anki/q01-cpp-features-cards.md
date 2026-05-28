# Question 1 — Main features of C++ (study cards)

Synthesized from [`questions.md`](../questions.md) — `### 1. What are the main *features* of *C++*?`  
Deck: `CPP::01-Basics` · Tags: `q01`, `cpp-features`

Import via `scripts/extract_anki_cards.py` once markup is added, or copy into Anki manually.

---

## Card 1 — Main question (summary)

**Front:** What are the main features of C++?

**Back:** C++ builds on C with additional capabilities. Its feature set supports many programming styles—especially procedural, object-oriented, and generic programming—so you can choose the right approach for the problem.

*Source: intro paragraph immediately under `### 1`.*

---

## Card 2 — Efficiency

**Front:** How does C++ allow developers to write efficient code?

**Back:**

- **Low-level access** — pointers and direct memory control when you need it
- **Resource management** — smart pointers and RAII (deterministic cleanup in destructors)
- **Inline functions** — avoid call overhead for small hot paths
- **Move semantics** — transfer resources instead of copying when possible

---

## Card 3 — Flexibility in types

**Front:** How does C++ balance type safety with flexibility?

**Back:**

- **Strong typing** — catches many errors at compile time
- **`auto`** — type inference so you write less redundant type noise
- **Concepts (C++20)** — express requirements on template parameters clearly

---

## Card 4 — Multiple paradigms

**Front:** What programming paradigms does C++ support?

**Back:**

- **Procedural** — functions, control flow (C-style)
- **Object-oriented** — classes, inheritance, polymorphism
- **Functional-style** — lambdas, `constexpr`, immutability where useful
- **Generic programming** — templates (and concepts) for type-parametric code

---

## Card 5 — Standard Library

**Front:** What role does the C++ Standard Library play?

**Back:**

- **Rich utilities** — containers, algorithms, I/O, and more out of the box
- **Modular headers** — e.g. `<algorithm>` for reusable algorithmic building blocks
- **Ranges (C++20)** — compose algorithms in a more declarative style

---

## Card 6 — Code reusability

**Front:** How does C++ help you reuse code across types and projects?

**Back:**

- **Inheritance** — share behavior through base/derived class hierarchies
- **Composition** — build types by embedding other objects (“has-a”)
- **Association** — relate objects via members and links without full ownership

---

## Card 7 — Polymorphism

**Front:** What kinds of polymorphism does C++ provide?

**Back:**

- **Compile-time** — templates and concepts (resolved when compiled)
- **Run-time** — virtual functions and `dynamic_cast` (resolved while the program runs)

---

## Card 8 — Memory management

**Front:** How does C++ approach memory management?

**Back:**

- **Stack vs. heap** — automatic storage for locals; dynamic allocation when needed
- **Smart pointers** — `unique_ptr`, `shared_ptr`, `weak_ptr` for ownership discipline
- **RAII** — tie resource lifetime to object lifetime (acquire in constructor, release in destructor)

---

## Card 9 — Modern features

**Front:** What are some important modern C++ features (especially C++20)?

**Back:**

- **Coroutines** — simpler structure for async / cooperative multitasking
- **Modules** — cleaner large-scale organization and faster builds than header-only sprawl
- **`constexpr`** — more work done at compile time (performance + compile-time checks)

---

## Card 10 — Synthesis (interview)

**Front:** In about 60 seconds, what are the main features of C++ and why do they matter?

**Back:**

- Evolved from **C** with **multi-paradigm** support (procedural, OOP, generic, functional touches)
- **Efficiency**: low-level control, RAII, moves, inlining
- **Type system**: strong types, `auto`, concepts
- **STL** + **modern C++20** (ranges, coroutines, modules)
- **Reuse & polymorphism** at compile time and run time
- **Memory**: stack/heap, smart pointers, RAII

---

## Optional follow-ups (not in source bullets — add if you want extra cards)

| Front | Back |
|-------|------|
| How does RAII relate to C++ constructors and destructors? | Resources acquired in ctor, released in dtor; pairs with smart pointers for heap objects. |
| Give one compile-time vs one run-time polymorphism example. | Templates/concepts vs `virtual` + `override`. |

---

## Card index

| ID | Kind | Section |
|----|------|---------|
| q01-001 | summary | Main question |
| q01-002 | definition | Efficiency |
| q01-003 | definition | Flexibility in types |
| q01-004 | list | Multiple paradigms |
| q01-005 | definition | Standard Library |
| q01-006 | definition | Code reusability |
| q01-007 | contrast | Polymorphism |
| q01-008 | definition | Memory management |
| q01-009 | list | Modern features |
| q01-010 | synthesis | Full answer |
