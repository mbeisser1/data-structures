What is SFINAE (Substitution Failure Is Not An Error)? #q37 #sfinae #templates-generic

---
**SFINAE** lets templates **gracefully handle substitution failures** during template argument deduction **without** failing the whole compile. The compiler **removes** the failed specialization from the overload set — enabling flexible template designs based on type traits.

%%%MOCHI_CARD%%%
Show SFINAE with `std::enable_if`. How do you route `print_number` to different overloads for integral vs floating-point types? #q37 #sfinae #templates-generic

---
```cpp
#include <type_traits>
#include <iostream>

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
void print_number(T value) {
    std::cout << "Integral: " << value << std::endl;
}

template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
void print_number(T value) {
    std::cout << "Floating-point: " << value << std::endl;
}

int main() {
    print_number(42);    // Integral overload
    print_number(3.14);  // Floating-point overload
    // print_number("hello");  // Error: no match
}
```

%%%MOCHI_CARD%%%
How do C++20 concepts compare to SFINAE? #q37 #sfinae #templates-generic

---

- **Concepts** — clearer syntax and **better error messages**
- **SFINAE** — still useful for advanced metaprogramming and legacy patterns

%%%MOCHI_CARD%%%
Show C++20 concepts replacing SFINAE. How do you write the same `print_number` dispatch with `std::integral` and `std::floating_point`? #q37 #sfinae #templates-generic

---
```cpp
#include <concepts>
#include <iostream>

template <std::integral T>
void print_number(T value) {
    std::cout << "Integral: " << value << std::endl;
}

template <std::floating_point T>
void print_number(T value) {
    std::cout << "Floating-point: " << value << std::endl;
}
```

%%%MOCHI_CARD%%%
What is tag dispatching with SFINAE? #q37 #sfinae #templates-generic

---

- **Tag dispatch** — route to different implementations using trait “tags” (e.g. `std::true_type` / `std::false_type`)

%%%MOCHI_CARD%%%
Show tag dispatching with SFINAE. How does `process(T)` choose different `process_impl` paths for integral vs non-integral types? #q37 #sfinae #templates-generic

---
```cpp
template <typename T>
void process_impl(T value, std::true_type) {
    std::cout << "Processing integral type\n";
}

template <typename T>
void process_impl(T value, std::false_type) {
    std::cout << "Processing non-integral type\n";
}

template <typename T>
void process(T value) {
    process_impl(value, std::is_integral<T>{});
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain SFINAE. #q37 #sfinae #templates-generic

---

- Bad substitution → **remove overload**, not hard error
- Enables **`enable_if`**, trait-based overload sets
- **Concepts** often replace SFINAE for readability
- Know both for templates and library design
