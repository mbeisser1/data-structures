How do you use `std::variant` and `std::visit`? #q88 #variant-visit #advanced-cpp

---
**`std::variant<Ts...>`** (C++17) is a **type-safe union** — holds **one** of several types at a time.

```cpp
std::variant<int, float, std::string> var;
var = 3.14f;
var = "Hello";
```

Track active type with **`index()`**, **`holds_alternative<T>`**.

%%%MOCHI_CARD%%%
How do you access values in a `std::variant`? #q88 #variant-visit #advanced-cpp

---
```cpp
if (std::holds_alternative<std::string>(var)) {
    std::cout << std::get<std::string>(var);
}

if (auto str = std::get_if<std::string>(&var)) {
    std::cout << *str;
}
```

**`std::get<T>`** throws **`bad_variant_access`** on wrong type.

**`get_if`** returns pointer or **`nullptr`**.

%%%MOCHI_CARD%%%
Show `std::visit` for type dispatch. #q88 #variant-visit #advanced-cpp

---
```cpp
std::visit([](const auto& val) {
    std::cout << val;
}, var);

struct Visitor {
    void operator()(int i) { std::cout << "Int: " << i; }
    void operator()(float f) { std::cout << "Float: " << f; }
    void operator()(const std::string& s) { std::cout << "String: " << s; }
};

std::visit(Visitor{}, var);
```

**`visit`** can take **multiple variants** — callback gets one arg per variant.

%%%MOCHI_CARD%%%
In about 60 seconds, explain variant and visit. #q88 #variant-visit #advanced-cpp

---

- **`variant`** = discriminated union, one active type
- **`get`/`get_if`** to access; check type first
- **`visit`** = overload set dispatch on active alternative
- Alternative to inheritance + virtual for closed type sets
