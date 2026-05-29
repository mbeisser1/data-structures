Explain the `auto` keyword and type inference. #q72 #auto #cpp11-beyond

---
**`auto`** lets the compiler **deduce a variable’s type** from its initializer (C++11).

```cpp
auto it = myMap.begin();  // instead of long iterator type
```

Deduction happens at **compile time** — not runtime dynamic typing.

%%%MOCHI_CARD%%%
What are key uses of `auto`? #q72 #auto #cpp11-beyond

---

- **Complex types** — iterators, nested templates
- **Range-based for** — `for (const auto& x : container)`
- **Refactoring safety** — type follows initializer if API changes
- **Return type deduction** (C++14) — `auto foo() { return x * y; }`
- **Non-type template param** (C++17) — `template<auto N>`

Always initialize **`auto`** variables — `auto x;` is invalid.

%%%MOCHI_CARD%%%
Show practical `auto` with vectors and iterators. #q72 #auto #cpp11-beyond

---
```cpp
#include <vector>
#include <string>

int main() {
    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};

    for (auto it = names.begin(); it != names.end(); ++it) {
        auto& name = *it;
        // Process name
    }

    for (const auto& name : names) {
        // Process name — no copy
    }

    return 0;
}
```

Prefer **`const auto&`** in range-for when you don’t need copies.

%%%MOCHI_CARD%%%
What are limitations of `auto`? #q72 #auto #cpp11-beyond

---

- Type must be deducible from **initializer**
- Can **obscure intent** if overused (`auto x = compute();`)
- **`auto` drops references** — `auto&` or `const auto&` to preserve
- **`auto&&`** with universal references in templates — forwarding context

Use **`decltype`** when you need an expression’s type without evaluating it.

%%%MOCHI_CARD%%%
In about 60 seconds, explain `auto`. #q72 #auto #cpp11-beyond

---

- **Compile-time type deduction** from initializer
- Cuts boilerplate for iterators and templates
- **`const auto&`** for read-only range loops
- C++14+ **`auto` return types**; don’t hide important types unnecessarily
