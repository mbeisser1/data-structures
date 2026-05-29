Explain the concept of template argument deduction. #q40 #template-argument-deduction #templates-generic

---
**Template argument deduction (TAD)** lets the compiler **infer template parameters** from function arguments — less explicit type noise at call sites.

%%%MOCHI_CARD%%%
How does template argument deduction work? #q40 #template-argument-deduction #templates-generic

---

- **`template <typename T> void myFunc(T arg)`** — `T` deduced from the argument
- **Explicit args** in `<>` take precedence when provided
- Deduction sources:
  - **Function parameters** (primary)
  - **Explicit template arguments** (override)

```cpp
myFunc(5);        // T = int
myFunc<double>(5); // T = double (explicit)
```

**Rules to know:**

- **Non-deduced contexts** — some parameters cannot be inferred
- **`const`/`volatile`** handling during deduction
- **Reference collapsing** for forwarding references

%%%MOCHI_CARD%%%
What is class template argument deduction (CTAD)? #q40 #template-argument-deduction #templates-generic

---
```cpp
std::pair p(1, 2.5);  // deduced as std::pair<int, double>
```

- **CTAD** (C++17) extends deduction to **class templates**
- C++20 **concepts** constrain what can be deduced:

```cpp
template <std::integral T>
void integerFunc(T value) { /* ... */ }

integerFunc(42);    // OK
integerFunc(3.14);  // Error: not std::integral
```

%%%MOCHI_CARD%%%
Show deducing array size with a template. #q40 #template-argument-deduction #templates-generic

---
```cpp
#include <iostream>
#include <cstddef>

template <typename T, std::size_t N>
void processArray(T (&arr)[N]) {
    std::cout << "Array of size " << N << std::endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    processArray(arr);  // T = int, N = 5
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain template argument deduction. #q40 #template-argument-deduction #templates-generic

---

- Compiler **infers** template args from call arguments
- **CTAD** (C++17) for class templates like `pair`, `vector`
- **Concepts** (C++20) restrict valid deductions
- Reduces boilerplate; explicit `<T>` still needed sometimes
