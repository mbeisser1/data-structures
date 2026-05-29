What are fold expressions in C++17? #q83 #fold-expressions #advanced-cpp

---
**Fold expressions** reduce a **parameter pack** with a single binary operator — concise alternative to recursive templates.

**Four forms:**

- Unary right: **`(pack op ...)`**
- Unary left: **`(... op pack)`**
- Binary right: **`(pack op ... op init)`**
- Binary left: **`(init op ... op pack)`**

%%%MOCHI_CARD%%%
Show fold expressions for sum, logical AND, and printing. #q83 #fold-expressions #advanced-cpp

---
```cpp
template <typename... Args>
auto sum(Args... args) {
    return (... + args);  // unary left fold
}

template <typename... Args>
bool are_all_true(Args... args) {
    return (... && args);
}

template <typename... Args>
void display_args(Args... args) {
    ((std::cout << args << ' '), ...);  // unary right fold
    std::cout << '\n';
}
```

**`sum(1, 2, 3, 4, 5)`** → 15.

%%%MOCHI_CARD%%%
What are empty pack and binary fold rules? #q83 #fold-expressions #advanced-cpp

---

**Empty pack:**

- **`&&`** → **`true`**
- **`||`** → **`false`**
- **`,`** → **`void()`**
- Other operators → **ill-formed**

**Binary fold** adds initial value:

```cpp
template<typename... Args>
auto sum_with_initial(int initial, Args... args) {
    return (initial + ... + args);
}
```

C++17 guarantees **left-to-right** evaluation for folds.

%%%MOCHI_CARD%%%
In about 60 seconds, explain fold expressions. #q83 #fold-expressions #advanced-cpp

---

- **`(... + args)`** folds a variadic pack
- Replaces recursive **`sum<T...>`** boilerplate
- Know **empty-pack** defaults for **`&&`/`||`**
- Comma fold useful for **`(f(args), ...)`** side effects
