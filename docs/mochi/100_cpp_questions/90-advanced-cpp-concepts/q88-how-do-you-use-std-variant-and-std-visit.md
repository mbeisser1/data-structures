How do you use `std::variant` and `std::visit`? #q88 #variant-visit #advanced-cpp

---
**`std::variant`** and **`std::visit`** (C++17) handle **sum types** / **discriminated unions** — **`variant`** is a **type-safe union**; **`visit`** performs **type-based dispatch** on the active alternative.

Assign alternatives with **`=`**; track active type with **`index()`**, **`holds_alternative<T>`**.

%%%MOCHI_CARD%%%
How do you access values in a `std::variant`? #q88 #variant-visit #advanced-cpp

---

- **`std::get<T>(var)`** — throws **`bad_variant_access`** on wrong type
- **`std::get_if<T>(&var)`** — pointer or **`nullptr`**
- **`holds_alternative<T>(var)`** — compile-time type check

Always know or check the active alternative before **`get`**.

%%%MOCHI_CARD%%%
Show `std::variant` basics. How do you assign and read `int` vs `std::string` from one variable? #q88 #variant-visit #advanced-cpp

---
```cpp
#include <iostream>
#include <string>
#include <variant>

int main() {
    std::variant<int, float, std::string> var;
    var = 42;
    std::cout << std::get<int>(var) << std::endl;

    var = "Hello";
    if (std::holds_alternative<std::string>(var)) {
        std::cout << std::get<std::string>(var) << std::endl;
    }

    if (auto str = std::get_if<std::string>(&var)) {
        std::cout << *str << std::endl;
    }
    return 0;
}
```

%%%MOCHI_CARD%%%
Show `std::visit` for type dispatch. How do you call different logic per active alternative without a manual switch? #q88 #variant-visit #advanced-cpp

---
```cpp
#include <iostream>
#include <string>
#include <variant>

std::variant<int, float, std::string> var = 3.14f;

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
