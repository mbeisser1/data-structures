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

- **Fallible parsing / lookup** — return **`nullopt`** on failure
- **Optional parameters** — default to empty optional
- **Search results** — found vs not found without magic sentinels

Prefer over **`nullptr`**, **`-1`**, or magic sentinels.

%%%MOCHI_CARD%%%
Show `std::optional` for a fallible parse. How do you return “no value” when `stoi` fails? #q85 #std-optional #advanced-cpp

---
```cpp
#include <optional>
#include <string>

std::optional<int> parse_integer(const std::string& str) {
    try {
        return std::stoi(str);
    } catch (const std::exception&) {
        return std::nullopt;
    }
}
```

Check with **`if (opt)`**, then **`*opt`**, **`.value()`**, or **`.value_or(default)`**.

%%%MOCHI_CARD%%%
Show extracting a middle name with `std::optional`. When should a name parser return `nullopt` vs a substring? #q85 #std-optional #advanced-cpp

---
```cpp
#include <iostream>
#include <optional>
#include <string>

std::optional<std::string> get_middle_name(const std::string& full_name) {
    size_t first_space = full_name.find(' ');
    if (first_space == std::string::npos) return std::nullopt;

    size_t last_space = full_name.rfind(' ');
    if (first_space == last_space) return std::nullopt;

    return full_name.substr(first_space + 1, last_space - first_space - 1);
}

int main() {
    if (auto middle = get_middle_name("Alice Middle Smith")) {
        std::cout << "Middle name: " << *middle << std::endl;
    }
    return 0;
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain `std::optional`. #q85 #std-optional #advanced-cpp

---

- **`optional<T>`** = maybe a **`T`**
- Return from **search/parse** that can fail
- Check with **`if (opt)`** then **`*opt`** or **`.value()`**
- C++23 **`expected`** extends this with error types
