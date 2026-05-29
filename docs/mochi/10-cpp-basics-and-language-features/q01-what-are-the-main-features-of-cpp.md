What are the main features of C++? #q01 #cpp-features

---
C++ builds on C with additional capabilities. Its feature set supports many programming styles:

- **Procedural** programming
- **Object-oriented** programming
- **Generic** programming

%%%MOCHI_CARD%%%
How does C++ allow developers to write efficient code? #q01 #cpp-features

---

- **Low-level access** — pointers and direct memory control when you need it
- **Resource management** — smart pointers and RAII (deterministic cleanup in destructors)
- **Inline functions** — avoid call overhead for small hot paths
- **Move semantics** — transfer resources instead of copying when possible

%%%MOCHI_CARD%%%
How does C++ balance type safety with flexibility? #q01 #cpp-features

---

- **Strong typing** — catches many errors at compile time
- **`auto`** — type inference so you write less redundant type noise
- **Concepts (C++20)** — express requirements on template parameters clearly

%%%MOCHI_CARD%%%
What programming paradigms does C++ support? #q01 #cpp-features

---

- **Procedural** — functions, control flow (C-style)
- **Object-oriented** — e.g.:
  - **Classes**
  - **Inheritance**
  - **Polymorphism**
- **Functional-style** — e.g.:
  - **Lambdas**
  - **`constexpr`**
  - **Immutability** where useful
- **Generic programming** — templates (and concepts) for type-parametric code

%%%MOCHI_CARD%%%
What role does the C++ Standard Library play? #q01 #cpp-features

---

- **Rich utilities** out of the box:
  - **Containers**
  - **Algorithms**
  - **I/O**
- **Modular headers** — e.g. `<algorithm>` for reusable algorithmic building blocks
- **Ranges (C++20)** — compose algorithms in a more declarative style

%%%MOCHI_CARD%%%
How does C++ help you reuse code across types and projects? #q01 #cpp-features

---

- **Inheritance** — share behavior through base/derived class hierarchies
- **Composition** — build types by embedding other objects (“has-a”)
- **Association** — relate objects via members and links without full ownership

%%%MOCHI_CARD%%%
What kinds of polymorphism does C++ provide? #q01 #cpp-features

---

- **Compile-time** — templates and concepts (resolved when compiled)
- **Run-time** — virtual functions and `dynamic_cast` (resolved while the program runs)

%%%MOCHI_CARD%%%
How does C++ approach memory management? #q01 #cpp-features

---

- **Stack vs. heap** — automatic storage for locals; dynamic allocation when needed
- **Smart pointers** for ownership discipline:
  - **`unique_ptr`**
  - **`shared_ptr`**
  - **`weak_ptr`**
- **RAII** — tie resource lifetime to object lifetime (acquire in constructor, release in destructor)

%%%MOCHI_CARD%%%
What are some important modern C++ features (especially C++20)? #q01 #cpp-features

---

- **Coroutines** — simpler structure for async / cooperative multitasking
- **Modules** — cleaner large-scale organization and faster builds than header-only sprawl
- **`constexpr`** — more work done at compile time (performance + compile-time checks)

%%%MOCHI_CARD%%%
In about 60 seconds, what are the main features of C++ and why do they matter? #q01 #cpp-features

---

- Evolved from **C** with **multi-paradigm** support:
  - **Procedural**
  - **OOP**
  - **Generic** programming
  - **Functional** touches
- **Efficiency:**
  - Low-level control
  - **RAII**
  - **Move** semantics
  - **Inlining**
- **Type system:**
  - Strong types
  - **`auto`**
  - **Concepts**
- **STL** + **modern C++20:**
  - **Ranges**
  - **Coroutines**
  - **Modules**
- **Reuse & polymorphism** at compile time and run time
- **Memory:**
  - Stack / heap
  - Smart pointers
  - **RAII**
