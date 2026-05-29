How does range-based for loop work? #q74 #range-for #cpp11-beyond

---
**Range-based for** iterates over any **range** with **`begin()`** and **`end()`**:

```cpp
for (declaration : expression)
    statement
```

The compiler desugars to iterator loops (or pointer arithmetic for arrays).

%%%MOCHI_CARD%%%
Show range-based for examples. #q74 #range-for #cpp11-beyond

---
```cpp
std::vector<int> vec = {1, 2, 3};
for (int num : vec) {
    std::cout << num << " ";
}

std::vector<std::string> words = {"Hello", "World"};
for (const auto& word : words) {
    std::cout << word << " ";
}

int arr[] = {4, 5, 6};
for (int num : arr) {
    std::cout << num << " ";
}
```

Works with **`std::begin`/`std::end`** for C arrays and custom types.

%%%MOCHI_CARD%%%
When should you use reference vs value in range-for? #q74 #range-for #cpp11-beyond

---

**Modify elements:**

```cpp
for (auto& elem : container) {
    elem *= 2;
}
```

**Read-only, avoid copies:**

```cpp
for (const auto& elem : container) { }
```

**Copy** (by value) only for cheap types or when you need a local copy.

%%%MOCHI_CARD%%%
What C++17/C++20 enhancements apply to range-for? #q74 #range-for #cpp11-beyond

---

**Structured bindings (C++17):**

```cpp
for (const auto& [key, value] : myMap) {
    std::cout << key << ": " << value << "\n";
}
```

**Init statement (C++20):**

```cpp
for (std::vector<int> vec = {1, 2, 3}; const auto& elem : vec) {
    std::cout << elem << " ";
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain range-based for. #q74 #range-for #cpp11-beyond

---

- **`for (decl : range)`** — syntactic sugar over iterators
- Needs **`begin`/`end`** on the expression
- Use **`const auto&`** for read-only; **`auto&`** to mutate
- C++17 **structured bindings** for maps/pairs
