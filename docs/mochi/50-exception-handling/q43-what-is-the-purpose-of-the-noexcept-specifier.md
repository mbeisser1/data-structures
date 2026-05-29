What is the purpose of the `noexcept` specifier? #q43 #noexcept #exceptions

---
**`noexcept`** declares that a function **will not throw** (or throws only under a condition). Purposes:

- **Optimization** — compiler can skip exception-handling tables
- **Documentation** — clear exception contract

- C++11: mostly informative
- **C++17+:** violating **`noexcept`** → **`std::terminate`**

%%%MOCHI_CARD%%%
What are the forms of `noexcept`? #q43 #noexcept #exceptions

---

- **`void f() noexcept;`** — unconditionally non-throwing
- **`void f() noexcept(condition);`** — non-throwing only when `condition` is true

%%%MOCHI_CARD%%%
Show the forms of `noexcept`. How do you declare unconditional vs conditional non-throwing functions? #q43 #noexcept #exceptions

---
```cpp
void func1() noexcept;                        // Simple form
void func2() noexcept(sizeof(int) == 4);      // Conditional form
```

%%%MOCHI_CARD%%%
Show `noexcept` vs throwing functions. How do you mark `square` as non-throwing and handle a divide-by-zero error from `divide`? #q43 #noexcept #exceptions

---
```cpp
#include <iostream>
#include <stdexcept>

int square(int num) noexcept {
    return num * num;
}

int divide(int a, int b) {
    if (b == 0) throw std::runtime_error("Division by zero");
    return a / b;
}

int main() {
    std::cout << "Square of 5: " << square(5) << std::endl;
    try {
        std::cout << "10 / 0 = " << divide(10, 0) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
```

%%%MOCHI_CARD%%%
What are the benefits and best practices for `noexcept`? #q43 #noexcept #exceptions

---

**Benefits:**

- Enables **compiler optimizations**
- Supports **no-throw** error strategies
- Helps **move** operations participate in standard containers (move if `noexcept`)

**Best practices:**

- Use only when the function **truly** won’t throw
- Mark **move constructor/assignment** `noexcept` when possible
- Callees of a `noexcept` function should also be non-throwing
- Prefer **`noexcept`** over deprecated **`throw()`**

%%%MOCHI_CARD%%%
In about 60 seconds, explain `noexcept`. #q43 #noexcept #exceptions

---

- Promises **no exceptions escape** (C++17+ contract)
- Violation → **`std::terminate`**, not normal unwinding
- Use on **moves**, **`what()`**, and hot **no-fail** ops
- Documents intent and enables optimizations
