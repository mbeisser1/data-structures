# Question 2 — C vs C++ (study cards)

Synthesized from [`questions.md`](../questions.md) — `### 2. Explain the *difference* between *C* and *C++*?`  
Deck: `CPP::01-Basics` · Tags: `q02`, `c-vs-cpp`

---

## Card 1 — Main question (summary)

**Front:** Explain the difference between C and C++.

**Back:**

- **C (1970s, Bell Labs)** — built for system programming; still widely used for OS kernels, embedded code, and low-level work.
- **C++ (1980s)** — started as a C extension with OOP; now a **multi-paradigm** language (procedural, OOP, generic, functional features).
- **Big picture:** C++ is largely **C-compatible** at the syntax level but adds classes, overloading, stronger abstractions, exceptions, and a much larger standard library.

*Source: opening bullets under `### 2`.*

---

## Card 2 — Paradigms

**Front:** How do C and C++ differ in programming paradigms?

**Back:**

- **C** — primarily **procedural** (functions + modules).
- **C++** — **multi-paradigm**: procedural, object-oriented, generic (templates), and functional-style features (e.g. lambdas, `constexpr`).

---

## Card 3 — Function overloading

**Front:** Does C support function overloading? How does C++?

**Back:**

- **C** — **no** overloading; one function name = one signature in a scope.
- **C++** — **yes**; same name, different parameter lists (types/count/order).

```cpp
// C++ function overloading example
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
```

---

## Card 4 — Memory management

**Front:** How does memory management differ between C and C++?

**Back:**

- **C** — manual **`malloc()` / `free()`** (and `calloc`, `realloc`); you track lifetime yourself.
- **C++** — **`new` / `delete`**, plus **RAII**, **smart pointers**, and destructors for automated cleanup.

```cpp
// C++ smart pointer example
#include <memory>
std::unique_ptr<int> ptr = std::make_unique<int>(42);
```

---

## Card 5 — Code organization

**Front:** How is code organized differently in C vs C++?

**Back:**

- **C** — functions and modules (`.c` / `.h` translation units).
- **C++** — same foundation, plus **classes**, **objects**, **inheritance**, and other OOP structure for grouping data and behavior.

---

## Card 6 — Standard libraries

**Front:** How do the C and C++ standard libraries compare?

**Back:**

- **C** — **C Standard Library** (`stdio.h`, `stdlib.h`, `string.h`, …).
- **C++** — **C++ Standard Library**, which **includes C headers** (often as `<cstdio>` etc.) and adds **containers**, **algorithms**, **streams**, and more.

---

## Card 7 — Header files

**Front:** How do header file conventions differ between C and C++?

**Back:**

- **C** — headers commonly use the **`.h`** suffix (`stdio.h`).
- **C++** — prefers **extensionless** standard headers (`<iostream>`, `<vector>`); C-style `.h` headers still work for C compatibility.

---

## Card 8 — Type safety and templates

**Front:** How does type safety differ between C and C++?

**Back:**

- **C** — basic compile-time type checking.
- **C++** — **stronger** checking plus **templates** for generic, type-safe code at compile time.

```cpp
// C++ template example
template <typename T>
T max(T a, T b) { return (a > b) ? a : b; }
```

---

## Card 9 — Object-oriented features

**Front:** Does C support OOP? What does C++ add?

**Back:**

- **C** — **no native OOP** (no classes, inheritance, or polymorphism as language features).
- **C++** — full **OOP**: **classes**, **inheritance**, **polymorphism**, **encapsulation** (access specifiers).

---

## Card 10 — Exception handling

**Front:** How do C and C++ handle errors and exceptions?

**Back:**

- **C** — **no native exceptions**; errors via return codes, `errno`, `setjmp`/`longjmp`, etc.
- **C++** — **`try` / `catch` / `throw`** and standard exception types.

```cpp
// C++ exception handling example
try {
    // code that might throw an exception
} catch (const std::exception& e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
}
```

---

## Card 11 — Boolean type

**Front:** How do C and C++ represent boolean values?

**Back:**

- **C** — traditionally **integers** (`0` = false, non-zero = true); `_Bool` / `bool` in C99+.
- **C++** — built-in **`bool`** with keywords **`true`** and **`false`**.

---

## Card 12 — Standardization

**Front:** What are the current language standards for C and C++ (per this material)?

**Back:**

- **C** — **C17** (ISO/IEC 9899:2018); **C23** in development.
- **C++** — **C++20** published; **C++23** nearing completion at time of source doc.

---

## Card 13 — Synthesis (interview)

**Front:** In about 60 seconds, explain the main differences between C and C++.

**Back:**

- **History:** C for systems (1970s); C++ as C’s evolution with OOP (1980s+).
- **Paradigm:** C procedural; C++ multi-paradigm.
- **Language features:** overloading, classes/OOP, templates, `bool`, exceptions.
- **Memory:** C `malloc`/`free`; C++ `new`/`delete`, RAII, smart pointers.
- **Library & headers:** C library vs larger C++ STL; `<iostream>` vs `stdio.h` style.
- **Standards:** C17 / C23 vs C++20 / C++23.

---

## Card index

| ID | Kind | Section | Code in answer |
|----|------|---------|----------------|
| q02-001 | summary | Main question | — |
| q02-002 | contrast | Paradigms | — |
| q02-003 | contrast | Function overloading | yes |
| q02-004 | contrast | Memory management | yes |
| q02-005 | contrast | Code organization | — |
| q02-006 | contrast | Standard libraries | — |
| q02-007 | contrast | Header files | — |
| q02-008 | contrast | Type safety | yes |
| q02-009 | contrast | OOP | — |
| q02-010 | contrast | Exception handling | yes |
| q02-011 | contrast | Boolean type | — |
| q02-012 | fact | Standardization | — |
| q02-013 | synthesis | Full answer | — |
