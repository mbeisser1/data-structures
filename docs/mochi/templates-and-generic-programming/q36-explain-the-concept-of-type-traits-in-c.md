Explain the concept of type traits in C++. #q36 #type-traits #templates-generic

---
**Type traits** query and transform type properties at **compile time** — usually from `<type_traits>`. Essential for **template metaprogramming** and conditional generic code.

%%%MOCHI_CARD%%%
What are commonly used type traits? #q36 #type-traits #templates-generic

---

**Categories:**

- **`std::is_integral<T>`**
- **`std::is_floating_point<T>`**
- **`std::is_arithmetic<T>`**
- **`std::is_void<T>`**

**Properties:**

- **`std::is_const<T>`**
- **`std::is_volatile<T>`**
- **`std::is_trivially_copyable<T>`**

**Relationships:**

- **`std::is_same<T, U>`**
- **`std::is_base_of<Base, Derived>`**

**Transformations:**

- **`std::remove_const<T>`**
- **`std::add_pointer<T>`**

%%%MOCHI_CARD%%%
Show type traits with `if constexpr`. #q36 #type-traits #templates-generic

---
```cpp
#include <type_traits>
#include <iostream>

template<typename T>
void print_type_info() {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "T is an integral type\n";
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "T is a floating-point type\n";
    } else {
        std::cout << "T is neither integral nor floating-point\n";
    }
}
```

- C++17: **`std::is_integral_v<T>`** instead of **`::value`**

%%%MOCHI_CARD%%%
Show a custom type trait. #q36 #type-traits #templates-generic

---
```cpp
template<typename T>
struct is_container {
    static constexpr bool value = false;
};

template<typename T>
struct is_container<std::vector<T>> {
    static constexpr bool value = true;
};

static_assert(is_container<std::vector<int>>::value);
static_assert(!is_container<int>::value);
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain type traits. #q36 #type-traits #templates-generic

---

- Compile-time type queries in **`<type_traits>`**
- Expose **`value`** or **`type`** aliases; C++17 **`_v`** / **`_t`** helpers
- Use with **`if constexpr`**, **SFINAE**, **concepts**
- You can write **custom traits** via partial specialization
