What is SFINAE (Substitution Failure Is Not An Error)? #q37 #sfinae #templates-generic

---
**SFINAE** means a **failed template substitution** during overload resolution **drops** that candidate instead of failing the whole compile — enabling **conditional templates** based on type properties.

%%%MOCHI_CARD%%%
Show SFINAE with `std::enable_if`. #q37 #sfinae #templates-generic

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

- **Concepts** — clearer syntax and **better error messages**
- **SFINAE** — still useful for advanced metaprogramming and legacy patterns

%%%MOCHI_CARD%%%
What is tag dispatching with SFINAE? #q37 #sfinae #templates-generic

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

- **Tag dispatch** — route to different implementations using trait “tags”

%%%MOCHI_CARD%%%
In about 60 seconds, explain SFINAE. #q37 #sfinae #templates-generic

---

- Bad substitution → **remove overload**, not hard error
- Enables **`enable_if`**, trait-based overload sets
- **Concepts** often replace SFINAE for readability
- Know both for templates and library design
