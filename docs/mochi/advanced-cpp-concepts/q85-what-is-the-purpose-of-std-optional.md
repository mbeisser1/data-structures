What is the purpose of `std::optional`? #q85 #std-optional #advanced-cpp

---
**`std::optional<T>`** (C++17) represents a value that **may or may not be present** — a type-safe alternative to sentinel values or raw pointers.

**Features:**

- Holds **`T`** or **empty** (`std::nullopt`)
- **Value semantics** — no ownership confusion like pointers
- Clear API: function **might not return** a value

%%%MOCHI_CARD%%%
What are common use cases for `std::optional`? #q85 #std-optional #advanced-cpp

---

**Fallible parsing / lookup:**

```cpp
std::optional<int> parse_integer(const std::string& str) {
    try {
        return std::stoi(str);
    } catch (const std::exception&) {
        return std::nullopt;
    }
}
```

**Optional parameters:**

```cpp
void process_data(int required, std::optional<int> optional = std::nullopt);
```

Prefer over **`nullptr`**, **`-1`**, or magic sentinels.

%%%MOCHI_CARD%%%
Show extracting middle name with `std::optional`. #q85 #std-optional #advanced-cpp

---
```cpp
std::optional<std::string> get_middle_name(const std::string& full_name) {
    size_t first_space = full_name.find(' ');
    if (first_space == std::string::npos) return std::nullopt;

    size_t last_space = full_name.rfind(' ');
    if (first_space == last_space) return std::nullopt;

    return full_name.substr(first_space + 1, last_space - first_space - 1);
}

// Usage:
if (auto middle = get_middle_name(name)) {
    std::cout << "Middle name: " << *middle << std::endl;
}
```

Also: **`opt.value()`**, **`opt.value_or(default)`**, **`opt.has_value()`**.

%%%MOCHI_CARD%%%
In about 60 seconds, explain `std::optional`. #q85 #std-optional #advanced-cpp

---

- **`optional<T>`** = maybe a **`T`**
- Return from **search/parse** that can fail
- Check with **`if (opt)`** then **`*opt`** or **`.value()`**
- C++23 **`expected`** extends this with error types
