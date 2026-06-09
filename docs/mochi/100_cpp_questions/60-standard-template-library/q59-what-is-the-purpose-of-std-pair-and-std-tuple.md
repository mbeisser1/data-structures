What is the purpose of `std::pair` and `std::tuple`? #q59 #pair-tuple #stl

---
**`std::pair`** and **`std::tuple`** are template classes for storing and handling **fixed collections of heterogeneous data** — each with distinct attributes and ideal use cases.

**`std::pair<T1,T2>`** (`<utility>`)

- Exactly **two** elements
- Access via **`.first`** and **`.second`**
- Lexicographic comparison operators

**`std::tuple<Ts...>`** (`<tuple>`)

- **Any number** of elements (compile-time fixed)
- Access via **`std::get<N>(t)`**
- C++17 **structured bindings**: `auto [a, b, c] = t;`

%%%MOCHI_CARD%%%
What are common use cases for `pair` and `tuple`? #q59 #pair-tuple #stl

---

**`std::pair`**

- **Map entries** and key-value returns
- **`insert` return values** (`iterator`, `bool`)
- Two-value function returns

**`std::tuple`**

- **Multiple return values** from one function
- Fixed heterogeneous records (status + value + message)

%%%MOCHI_CARD%%%
Show returning `pair` and `tuple` from functions. How do you return multiple values and unpack a tuple with structured binding? #q59 #pair-tuple #stl

---
```cpp
#include <iostream>
#include <utility>
#include <tuple>
#include <string>

std::pair<bool, int> divide(int a, int b) {
    if (b == 0) return {false, 0};
    return {true, a / b};
}

std::tuple<bool, double, std::string> process_data(double value) {
    if (value < 0) return {false, 0.0, "Error: Negative input"};
    double result = value * 2;
    return {true, result, "Success"};
}

int main() {
    auto div_result = divide(10, 2);
    if (div_result.first) {
        std::cout << "Division result: " << div_result.second << std::endl;
    }

    auto [success, result, message] = process_data(5.0);
    if (success) {
        std::cout << "Processed result: " << result
                  << ", Message: " << message << std::endl;
    }

    return 0;
}
```

%%%MOCHI_CARD%%%
How do you create and access pairs and tuples? #q59 #pair-tuple #stl

---
```cpp
// pair
auto p = std::make_pair(1, "hello");
// or C++17: std::pair p{1, "hello"};

// tuple
auto t = std::make_tuple(true, 3.14, std::string("ok"));
// or: std::tuple t{true, 3.14, std::string("ok")};

std::get<0>(t);           // by index
std::get<1>(p);           // error — pair uses .first/.second
```

**C++17 structured binding** works for both when element count is known.

%%%MOCHI_CARD%%%
In about 60 seconds, explain pair and tuple. #q59 #pair-tuple #stl

---

- **`pair`** = two typed slots, `.first`/`.second`
- **`tuple`** = N typed slots, `std::get<N>` or structured bindings
- Use for **multi-value returns** and lightweight grouped data
- **`map`** stores `pair<const Key, T>` internally
