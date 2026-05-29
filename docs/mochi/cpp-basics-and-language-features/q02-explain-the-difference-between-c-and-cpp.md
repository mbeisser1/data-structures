Explain the difference between C and C++. #q02 #c-vs-cpp

---

- **C (1970s, Bell Labs)** — built for system programming; still widely used for:
  - **OS kernels**
  - **Embedded code**
  - **Low-level** work
- **C++ (1980s)** — started as a C extension with OOP; now a **multi-paradigm** language:
  - **Procedural**
  - **OOP**
  - **Generic** (templates)
  - **Functional** features
- **Big picture:** C++ is largely **C-compatible** at the syntax level but adds:
  - **Classes**
  - **Overloading**
  - Stronger **abstractions**
  - **Exceptions**
  - A much larger **standard library**

%%%MOCHI_CARD%%%
How do C and C++ differ in programming paradigms? #q02 #c-vs-cpp

---

- **C** — primarily **procedural** (functions + modules).
- **C++** — **multi-paradigm**:
  - **Procedural**
  - **Object-oriented**
  - **Generic** (templates)
  - **Functional-style** (e.g. lambdas, `constexpr`)

%%%MOCHI_CARD%%%
Does C support function overloading? How does C++? #q02 #c-vs-cpp

---

- **C** — **no** overloading; one function name = one signature in a scope.
- **C++** — **yes**; same name, different parameter lists (types/count/order).

```cpp
// C++ function overloading example
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
```

%%%MOCHI_CARD%%%
How does memory management differ between C and C++? #q02 #c-vs-cpp

---

- **C** — manual dynamic allocation; you track lifetime yourself:
  - **`malloc()` / `free()`**
  - **`calloc()`**
  - **`realloc()`**
- **C++** — **`new` / `delete`**, plus automated cleanup via:
  - **RAII**
  - **Smart pointers**
  - **Destructors**

```cpp
// C++ smart pointer example
#include <memory>
std::unique_ptr<int> ptr = std::make_unique<int>(42);
```

%%%MOCHI_CARD%%%
How is code organized differently in C vs C++? #q02 #c-vs-cpp

---

- **C** — functions and modules (`.c` / `.h` translation units).
- **C++** — same foundation, plus OOP structure for grouping data and behavior:
  - **Classes**
  - **Objects**
  - **Inheritance**

%%%MOCHI_CARD%%%
How do the C and C++ standard libraries compare? #q02 #c-vs-cpp

---

- **C** — **C Standard Library**:
  - **`stdio.h`**
  - **`stdlib.h`**
  - **`string.h`**
- **C++** — **C++ Standard Library** (includes C headers, often as `<cstdio>` etc.) plus:
  - **Containers**
  - **Algorithms**
  - **Streams**

%%%MOCHI_CARD%%%
How do header file conventions differ between C and C++? #q02 #c-vs-cpp

---

- **C** — headers commonly use the **`.h`** suffix (`stdio.h`).
- **C++** — prefers **extensionless** standard headers (`<iostream>`, `<vector>`); C-style `.h` headers still work for C compatibility.

%%%MOCHI_CARD%%%
How does type safety differ between C and C++? #q02 #c-vs-cpp

---

- **C** — basic compile-time type checking.
- **C++** — **stronger** checking plus **templates** for generic, type-safe code at compile time.

```cpp
// C++ template example
template <typename T>
T max(T a, T b) { return (a > b) ? a : b; }
```

%%%MOCHI_CARD%%%
Does C support OOP? What does C++ add? #q02 #c-vs-cpp

---

- **C** — **no native OOP** (no language features for):
  - **Classes**
  - **Inheritance**
  - **Polymorphism**
- **C++** — full **OOP**:
  - **Classes**
  - **Inheritance**
  - **Polymorphism**
  - **Encapsulation** (access specifiers)

%%%MOCHI_CARD%%%
How do C and C++ handle errors and exceptions? #q02 #c-vs-cpp

---

- **C** — **no native exceptions**; errors via:
  - **Return codes**
  - **`errno`**
  - **`setjmp` / `longjmp`**
- **C++** — exception handling via:
  - **`try`**
  - **`catch`**
  - **`throw`**
  - Standard exception types

```cpp
// C++ exception handling example
try {
    // code that might throw an exception
} catch (const std::exception& e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
}
```

%%%MOCHI_CARD%%%
How do C and C++ represent boolean values? #q02 #c-vs-cpp

---

- **C** — traditionally **integers** (`0` = false, non-zero = true); `_Bool` / `bool` in C99+.
- **C++** — built-in **`bool`** with keywords **`true`** and **`false`**.

%%%MOCHI_CARD%%%
What are the current language standards for C and C++ (per this material)? #q02 #c-vs-cpp

---

- **C** — **C17** (ISO/IEC 9899:2018); **C23** in development.
- **C++** — **C++20** published; **C++23** nearing completion at time of source doc.

%%%MOCHI_CARD%%%
In about 60 seconds, explain the main differences between C and C++. #q02 #c-vs-cpp

---

- **History:** C for systems (1970s); C++ as C’s evolution with OOP (1980s+).
- **Paradigm:** C procedural; C++ multi-paradigm.
- **Language features:**
  - **Overloading**
  - **Classes / OOP**
  - **Templates**
  - **`bool`**
  - **Exceptions**
- **Memory:**
  - C: **`malloc` / `free`**
  - C++: **`new` / `delete`**
  - C++: **RAII**
  - C++: **Smart pointers**
- **Library & headers:** C library vs larger C++ STL; `<iostream>` vs `stdio.h` style.
- **Standards:** C17 / C23 vs C++20 / C++23.
