What is perfect forwarding in C++? #q77 #perfect-forwarding #cpp11-beyond

---
**Perfect forwarding** passes arguments to another function **preserving lvalue/rvalue** and **const** qualification — no extra copies.

Core tools:

- **Forwarding reference** — **`T&&`** in a deduced template context
- **`std::forward<T>(arg)`** — conditional cast to correct reference type

%%%MOCHI_CARD%%%
What is the difference between forwarding and rvalue references? #q77 #perfect-forwarding #cpp11-beyond

---

**Rvalue reference** — `void f(int&&)` — only binds to rvalues

**Forwarding reference** — `template<typename T> void f(T&&)` — binds to **both** lvalues and rvalues; **`T`** deduced accordingly

**`std::forward<T>(x)`** restores the original value category when passing on.

%%%MOCHI_CARD%%%
Show perfect forwarding with overload resolution. #q77 #perfect-forwarding #cpp11-beyond

---
```cpp
#include <iostream>
#include <utility>

void process(int& x) {
    std::cout << "lvalue reference: " << x << std::endl;
}

void process(int&& x) {
    std::cout << "rvalue reference: " << x << std::endl;
}

template<typename T>
void perfect_forward(T&& x) {
    process(std::forward<T>(x));
}

int main() {
    int a = 5;
    perfect_forward(a);              // lvalue
    perfect_forward(10);             // rvalue
    perfect_forward(std::move(a));   // rvalue
    return 0;
}
```

%%%MOCHI_CARD%%%
What are benefits and pitfalls of perfect forwarding? #q77 #perfect-forwarding #cpp11-beyond

---

**Benefits**

- Avoid redundant copies
- Preserve **const**
- Generic wrappers (factories, **`emplace`**, **`make_unique`**)

**Pitfalls**

- Don’t confuse **`T&&`** template param with concrete **`int&&`**
- Forward **each** argument: `f(std::forward<T1>(a), std::forward<T2>(b))`
- **Initializer lists** and special types may deduce unexpectedly

%%%MOCHI_CARD%%%
In about 60 seconds, explain perfect forwarding. #q77 #perfect-forwarding #cpp11-beyond

---

- **`T&&` + template deduction** = forwarding reference
- **`std::forward<T>(arg)`** passes through lvalue or rvalue unchanged
- Powers **`emplace`**, wrapper templates, **`make_shared`**
- Always forward with **`std::forward`**, not **`std::move`**, in generic code
