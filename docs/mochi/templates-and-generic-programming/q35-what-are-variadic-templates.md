What are variadic templates? #q35 #variadic-templates #templates-generic

---
**Variadic templates** (C++11) accept a **variable number** of template arguments — types and/or values — enabling flexible utilities like **`std::tuple`**, **`make_unique`**, and **`std::visit`**.

%%%MOCHI_CARD%%%
What is the syntax for variadic templates? #q35 #variadic-templates #templates-generic

---
```cpp
template <typename... Ts>
void myFunction(Ts... args);
```

- **`Ts...`** — **parameter pack** (zero or more types)
- **`args...`** — function parameter pack
- C++17+: non-type packs too: `template <auto... Values>`

%%%MOCHI_CARD%%%
Show fold expressions with variadic templates. #q35 #variadic-templates #templates-generic

---
```cpp
template <typename... Ts>
void printAll(Ts... args) {
    (std::cout << ... << args) << '\n';  // C++17 fold
}

template <typename... Ts>
auto sum(Ts... args) {
    return (... + args);
}

printAll(1, 2.0, "three");
```

**Recursive unpacking** (pre-C++17 style):

```cpp
template <typename T>
void print(T arg) { std::cout << arg << '\n'; }

template <typename T, typename... Ts>
void print(T first, Ts... rest) {
    std::cout << first << ' ';
    print(rest...);
}
```

%%%MOCHI_CARD%%%
How is perfect forwarding used with variadic templates? #q35 #variadic-templates #templates-generic

---
```cpp
template <typename... Args>
void wrapper(Args&&... args) {
    someFunction(std::forward<Args>(args)...);
}
```

- **`Args&&...`** — universal references
- **`std::forward`** preserves lvalue/rvalue-ness through the call chain

%%%MOCHI_CARD%%%
In about 60 seconds, explain variadic templates. #q35 #variadic-templates #templates-generic

---

- **`typename... Ts`** / **`Ts... args`** — variable argument count
- **Fold expressions** (C++17) simplify pack operations
- Powers **`tuple`**, **`make_shared`**, **`async`**, **`visit`**
- Combine with **`std::forward`** for perfect forwarding
