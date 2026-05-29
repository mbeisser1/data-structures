What is the purpose of `std::any`? #q89 #std-any #advanced-cpp

---
**`std::any`** (C++17) stores **any copyable type** in a type-safe container — runtime type erasure without a common base class.

Safer than **`void*`** — type checks on retrieval.

%%%MOCHI_CARD%%%
What operations does `std::any` provide? #q89 #std-any #advanced-cpp

---

- **`has_value()`** — empty or not
- **`type()`** — **`type_info`** of stored type
- **`reset()`** — clear
- **`emplace<T>(args...)`** — construct **`T`** in place
- **`std::any_cast<T>(a)`** — extract; throws **`bad_any_cast`** on mismatch

Value is **copied/moved** into the **`any`** (may heap-allocate).

%%%MOCHI_CARD%%%
Show using `std::any`. #q89 #std-any #advanced-cpp

---
```cpp
#include <any>
#include <iostream>
#include <string>

int main() {
    std::any data;

    data = 42;
    std::cout << std::any_cast<int>(data) << std::endl;

    data = std::string("Hello, std::any!");
    std::cout << std::any_cast<std::string>(data) << std::endl;

    struct Point { int x, y; };
    data.emplace<Point>(10, 20);
    const auto& point = std::any_cast<const Point&>(data);

    data.reset();

    try {
        std::any_cast<float>(data);
    } catch (const std::bad_any_cast& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
```

%%%MOCHI_CARD%%%
When should you use `std::any` vs `std::variant`? #q89 #std-any #advanced-cpp

---

**`std::variant`**

- Fixed set of alternatives — **compile-time** closed union
- Zero overhead dispatch with **`visit`**

**`std::any`**

- **Open** set of types at runtime
- Plugin/config bags, scripting bridges

Both prefer over **`void*`** when type safety matters.

%%%MOCHI_CARD%%%
In about 60 seconds, explain `std::any`. #q89 #std-any #advanced-cpp

---

- **Type-erased box** for any copyable value
- **`any_cast`** to retrieve — throws if wrong type
- **`emplace`**, **`reset`**, **`type()`** for management
- Use when alternative types aren’t known at compile time
