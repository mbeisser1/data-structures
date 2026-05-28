<!-- Markdown2Anki source: converted from q01-cpp-features-cards.md -->
<!-- Run: md2anki -f docs/anki/md2anki/q01-cpp-features-cards.md -->

## - [Main question (summary)]

What are the main features of C++?

## B [Answer]

C++ builds on C with additional capabilities. Its feature set supports many programming styles—especially procedural, object-oriented, and generic programming—so you can choose the right approach for the problem.

---

## - [Efficiency]

How does C++ allow developers to write efficient code?

## B [Answer]

- **Low-level access** — pointers and direct memory control when you need it

- **Resource management** — smart pointers and RAII (deterministic cleanup in destructors)
- **Inline functions** — avoid call overhead for small hot paths
- **Move semantics** — transfer resources instead of copying when possible

---

## - [Flexibility in types]

How does C++ balance type safety with flexibility?

## B [Answer]

- **Strong typing** — catches many errors at compile time

- **`auto`** — type inference so you write less redundant type noise
- **Concepts (C++20)** — express requirements on template parameters clearly

---

## - [Multiple paradigms]

What programming paradigms does C++ support?

## B [Answer]

- **Procedural** — functions, control flow (C-style)

- **Object-oriented** — classes, inheritance, polymorphism
- **Functional-style** — lambdas, `constexpr`, immutability where useful
- **Generic programming** — templates (and concepts) for type-parametric code

---

## - [Standard Library]

What role does the C++ Standard Library play?

## B [Answer]

- **Rich utilities** — containers, algorithms, I/O, and more out of the box

- **Modular headers** — e.g. `<algorithm>` for reusable algorithmic building blocks
- **Ranges (C++20)** — compose algorithms in a more declarative style

---

## - [Code reusability]

How does C++ help you reuse code across types and projects?

## B [Answer]

- **Inheritance** — share behavior through base/derived class hierarchies

- **Composition** — build types by embedding other objects (“has-a”)
- **Association** — relate objects via members and links without full ownership

---

## - [Polymorphism]

What kinds of polymorphism does C++ provide?

## B [Answer]

- **Compile-time** — templates and concepts (resolved when compiled)

- **Run-time** — virtual functions and `dynamic_cast` (resolved while the program runs)

---

## - [Memory management]

How does C++ approach memory management?

## B [Answer]

- **Stack vs. heap** — automatic storage for locals; dynamic allocation when needed

- **Smart pointers** — `unique_ptr`, `shared_ptr`, `weak_ptr` for ownership discipline
- **RAII** — tie resource lifetime to object lifetime (acquire in constructor, release in destructor)

---

## - [Modern features]

What are some important modern C++ features (especially C++20)?

## B [Answer]

- **Coroutines** — simpler structure for async / cooperative multitasking

- **Modules** — cleaner large-scale organization and faster builds than header-only sprawl
- **`constexpr`** — more work done at compile time (performance + compile-time checks)

---

## - [Synthesis (interview)]

In about 60 seconds, what are the main features of C++ and why do they matter?

## B [Answer]

- Evolved from **C** with **multi-paradigm** support (procedural, OOP, generic, functional touches)

- **Efficiency**: low-level control, RAII, moves, inlining
- **Type system**: strong types, `auto`, concepts
- **STL** + **modern C++20** (ranges, coroutines, modules)
- **Reuse & polymorphism** at compile time and run time
- **Memory**: stack/heap, smart pointers, RAII

