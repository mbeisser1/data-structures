How does template metaprogramming work in C++? #q34 #template-metaprogramming #templates-generic

---
**Template metaprogramming (TMP)** uses templates to perform **computations and code generation at compile time** — flexible, efficient, type-safe generic code.

%%%MOCHI_CARD%%%
What TMP techniques use templates at compile time? #q34 #template-metaprogramming #templates-generic

---

- **Template specialization** — custom logic per type/value
- **Type traits** — query type properties (`std::is_integral_v<T>`)
- **SFINAE** — enable/disable overloads based on type properties
- **`constexpr`** — compile-time functions and constants
- **Variadic templates** — packs and fold expressions

%%%MOCHI_CARD%%%
Show compile-time type checking with type traits. How does `process(T)` branch differently for integral vs other types? #q34 #template-metaprogramming #templates-generic

---
```cpp
#include <type_traits>

template <typename T>
void process(T value) {
    if constexpr (std::is_integral_v<T>) {
        // Integer-specific processing
    } else {
        // General processing
    }
}
```

%%%MOCHI_CARD%%%
Show a custom compile-time type trait. How do you specialize `is_void` for `void` only? #q34 #template-metaprogramming #templates-generic

---
```cpp
template <typename T>
struct is_void {
    static constexpr bool value = false;
};

template <>
struct is_void<void> {
    static constexpr bool value = true;
};
```

%%%MOCHI_CARD%%%
Show compile-time Fibonacci with templates. How do you compute `Fibonacci<N>::value` at compile time? #q34 #template-metaprogramming #templates-generic

---
```cpp
template<unsigned N>
struct Fibonacci {
    static constexpr unsigned value =
        Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template<>
struct Fibonacci<0> {
    static constexpr unsigned value = 0;
};

template<>
struct Fibonacci<1> {
    static constexpr unsigned value = 1;
};

static_assert(Fibonacci<10>::value == 55, "Fibonacci<10> should be 55");
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain template metaprogramming. #q34 #template-metaprogramming #templates-generic

---

- Templates + **`constexpr`** → **compile-time** computation
- **Specialization**, **type traits**, **SFINAE** select behavior by type
- Results: zero-cost abstractions, static checks (`static_assert`)
- Modern code often mixes TMP with **concepts** and **`if constexpr`**
