Explain the concept of concepts in C++20. #q86 #concepts #advanced-cpp

---
**Concepts** constrain **template parameters** with readable, compile-time requirements — better errors and clearer APIs than SFINAE alone.

A **`concept`** is a named predicate on types; **`requires`** clauses check expressions and return types.

Violations produce **direct diagnostics** at the constraint, not deep in instantiation.

%%%MOCHI_CARD%%%
How do you define and combine concepts? #q86 #concepts #advanced-cpp

---

**Simple:** `concept Integral = std::is_integral_v<T>;`

**Compound:** `Integral<T> || std::floating_point<T>`

**Requires clause:** expression must compile and satisfy return-type constraints

```cpp
template <typename T>
concept Sortable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
    std::swap(a, b);
};
```

%%%MOCHI_CARD%%%
Show using concepts in templates. How do you constrain `gcd` and a print function to integral types only? #q86 #concepts #advanced-cpp

---
```cpp
#include <iostream>
#include <concepts>

template <std::integral T>
T gcd(T a, T b) {
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void print_number(std::integral auto x) {
    std::cout << x << std::endl;
}
```

Syntax: **`template<MyConcept T>`** or **`MyConcept auto`** parameter.

%%%MOCHI_CARD%%%
Show combining custom concepts. How do you build `Arithmetic` from simpler concepts? #q86 #concepts #advanced-cpp

---
```cpp
template <typename T>
concept Integral = std::is_integral_v<T>;

template <typename T>
concept Arithmetic = Integral<T> || std::floating_point<T>;
```

%%%MOCHI_CARD%%%
What are benefits of concepts? #q86 #concepts #advanced-cpp

---

- **Readable constraints** on templates
- **Shorter error messages**
- **Overload resolution** — constrain overload sets distinctly
- **Reusable** named requirements (`std::ranges`, `std::integral`, …)

Replaces many **`enable_if`** / SFINAE patterns.

%%%MOCHI_CARD%%%
In about 60 seconds, explain C++20 concepts. #q86 #concepts #advanced-cpp

---

- Named **`concept`** = compile-time predicate on types
- **`requires`** for expression-level checks
- Use on **`template<T>`**, **`auto` params**, class templates
- Better docs + errors than raw SFINAE
