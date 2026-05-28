<!-- Markdown2Anki source: converted from q02-c-vs-cpp-cards.md -->
<!-- Run: md2anki -f docs/anki/md2anki/q02-c-vs-cpp-cards.md -->

## - [Main question (summary)]

Explain the difference between C and C++.

## B [Answer]

- **C (1970s, Bell Labs)** — built for system programming; still widely used for OS kernels, embedded code, and low-level work.

- **C++ (1980s)** — started as a C extension with OOP; now a **multi-paradigm** language (procedural, OOP, generic, functional features).
- **Big picture:** C++ is largely **C-compatible** at the syntax level but adds classes, overloading, stronger abstractions, exceptions, and a much larger standard library.

---

## - [Paradigms]

How do C and C++ differ in programming paradigms?

## B [Answer]

- **C** — primarily **procedural** (functions + modules).

- **C++** — **multi-paradigm**: procedural, object-oriented, generic (templates), and functional-style features (e.g. lambdas, `constexpr`).

---

## - [Function overloading]

Does C support function overloading? How does C++?

## B [Answer]

- **C** — **no** overloading; one function name = one signature in a scope.

- **C++** — **yes**; same name, different parameter lists (types/count/order).

```cpp
// C++ function overloading example
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
```

---

## - [Memory management]

How does memory management differ between C and C++?

## B [Answer]

- **C** — manual **`malloc()` / `free()`** (and `calloc`, `realloc`); you track lifetime yourself.

- **C++** — **`new` / `delete`**, plus **RAII**, **smart pointers**, and destructors for automated cleanup.

```cpp
// C++ smart pointer example
#include <memory>
std::unique_ptr<int> ptr = std::make_unique<int>(42);
```

---

## - [Code organization]

How is code organized differently in C vs C++?

## B [Answer]

- **C** — functions and modules (`.c` / `.h` translation units).

- **C++** — same foundation, plus **classes**, **objects**, **inheritance**, and other OOP structure for grouping data and behavior.

---

## - [Standard libraries]

How do the C and C++ standard libraries compare?

## B [Answer]

- **C** — **C Standard Library** (`stdio.h`, `stdlib.h`, `string.h`, …).

- **C++** — **C++ Standard Library**, which **includes C headers** (often as `<cstdio>` etc.) and adds **containers**, **algorithms**, **streams**, and more.

---

## - [Header files]

How do header file conventions differ between C and C++?

## B [Answer]

- **C** — headers commonly use the **`.h`** suffix (`stdio.h`).

- **C++** — prefers **extensionless** standard headers (`<iostream>`, `<vector>`); C-style `.h` headers still work for C compatibility.

---

## - [Type safety and templates]

How does type safety differ between C and C++?

## B [Answer]

- **C** — basic compile-time type checking.

- **C++** — **stronger** checking plus **templates** for generic, type-safe code at compile time.

```cpp
// C++ template example
template <typename T>
T max(T a, T b) { return (a > b) ? a : b; }
```

---

## - [Object-oriented features]

Does C support OOP? What does C++ add?

## B [Answer]

- **C** — **no native OOP** (no classes, inheritance, or polymorphism as language features).

- **C++** — full **OOP**: **classes**, **inheritance**, **polymorphism**, **encapsulation** (access specifiers).

---

## - [Exception handling]

How do C and C++ handle errors and exceptions?

## B [Answer]

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

## - [Boolean type]

How do C and C++ represent boolean values?

## B [Answer]

- **C** — traditionally **integers** (`0` = false, non-zero = true); `_Bool` / `bool` in C99+.

- **C++** — built-in **`bool`** with keywords **`true`** and **`false`**.

---

## - [Standardization]

What are the current language standards for C and C++ (per this material)?

## B [Answer]

- **C** — **C17** (ISO/IEC 9899:2018); **C23** in development.

- **C++** — **C++20** published; **C++23** nearing completion at time of source doc.

---

## - [Synthesis (interview)]

In about 60 seconds, explain the main differences between C and C++.

## B [Answer]

- **History:** C for systems (1970s); C++ as C’s evolution with OOP (1980s+).

- **Paradigm:** C procedural; C++ multi-paradigm.
- **Language features:** overloading, classes/OOP, templates, `bool`, exceptions.
- **Memory:** C `malloc`/`free`; C++ `new`/`delete`, RAII, smart pointers.
- **Library & headers:** C library vs larger C++ STL; `<iostream>` vs `stdio.h` style.
- **Standards:** C17 / C23 vs C++20 / C++23.

