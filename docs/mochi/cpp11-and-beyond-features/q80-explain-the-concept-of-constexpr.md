Explain the concept of `constexpr`. #q80 #constexpr #cpp11-beyond

---
**`constexpr`** marks values or functions evaluable at **compile time** when given compile-time inputs (C++11+, expanded in C++14/17/20).

Enables constants in templates, array sizes, and compile-time checks — with fallback to **runtime** when args are dynamic.

%%%MOCHI_CARD%%%
What are key rules for `constexpr`? #q80 #constexpr #cpp11-beyond

---

- **`constexpr` variables** must have literal type and constant initializer
- **`constexpr` functions** — C++11: single return; C++14+: loops, locals, multiple statements
- If args are compile-time constants, call is evaluated at compile time
- Otherwise behaves like a normal function at runtime

Related: **`consteval`** (must compile-time, C++20), **`constinit`** (static init, C++20).

%%%MOCHI_CARD%%%
Show a `constexpr` factorial function. #q80 #constexpr #cpp11-beyond

---
```cpp
#include <iostream>
#include <array>

constexpr int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    constexpr int fact5 = factorial(5);

    int n = 6;
    int fact6 = factorial(n);  // runtime OK

    constexpr std::array<int, factorial(4)> arr = {1, 2, 3, 4, 5, 6};

    std::cout << "5! = " << fact5 << std::endl;
    std::cout << "Size of arr: " << arr.size() << std::endl;

    return 0;
}
```

**`fact5`** and array size computed at compile time.

%%%MOCHI_CARD%%%
How did `constexpr` evolve across C++ standards? #q80 #constexpr #cpp11-beyond

---

- **C++11** — strict limits on function body
- **C++14** — relaxed constexpr functions (if, loops, variables)
- **C++17** — **`if constexpr`**, more library constexpr
- **C++20** — **`consteval`**, **`constinit`**, larger constexpr stdlib

**`if constexpr`** discards non-taken branches at compile time in templates.

%%%MOCHI_CARD%%%
What are benefits and limitations of `constexpr`? #q80 #constexpr #cpp11-beyond

---

**Benefits**

- **Performance** — work done at compile time
- **Type-safe constants** for templates/arrays
- **Compile-time errors** for invalid input

**Limitations**

- Not all operations allowed in constexpr contexts (I/O, heap, etc.)
- Heavy constexpr can **slow builds**
- Debugging compile-time evaluation is harder

%%%MOCHI_CARD%%%
In about 60 seconds, explain `constexpr`. #q80 #constexpr #cpp11-beyond

---

- **Compile-time evaluation** when possible
- **`constexpr int f(int n)`** for metaprogramming and constants
- C++14+ allows real function bodies; C++17 **`if constexpr`**
- Use for sizes, lookup tables, and static validation
