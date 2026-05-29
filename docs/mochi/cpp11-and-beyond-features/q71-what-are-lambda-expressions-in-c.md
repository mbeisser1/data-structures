What are lambda expressions in C++? #q71 #lambdas #cpp11-beyond

---
A **lambda expression** defines an **unnamed function object** inline — ideal for short callbacks with STL algorithms.

**Syntax:** `[capture](parameters) specifiers -> return-type { body }`

- **Capture** — variables from enclosing scope
- **Parameters** — like a normal function
- **Return type** — optional (deduced if omitted)

%%%MOCHI_CARD%%%
What are lambda capture modes? #q71 #lambdas #cpp11-beyond

---

- **`[=]`** or **`[a, b]`** — capture by **value**
- **`[&]`** or **`[&a, &b]`** — capture by **reference**
- **Mixed** — **`[=, &x]`** or **`[&, y]`**
- **`[this]`** or **`[*this]`** (C++17) — capture current object

Captured variables become **members** of the closure object.

%%%MOCHI_CARD%%%
Show a basic lambda with `std::for_each`. How do you pass a lambda to an algorithm to process each element? #q71 #lambdas #cpp11-beyond

---
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {4, 1, 3, 5, 2};

    auto print = [](int n) { std::cout << n << ' '; };

    std::for_each(numbers.begin(), numbers.end(), print);

    return 0;
}
```

%%%MOCHI_CARD%%%
Show a lambda as a predicate. How can a captured lambda filter elements with `count_if`? #q71 #lambdas #cpp11-beyond

---
```cpp
#include <vector>
#include <algorithm>

int threshold = 3;
std::vector<int> numbers = {4, 1, 3, 5, 2};

auto count = std::count_if(numbers.begin(), numbers.end(),
    [threshold](int n) { return n > threshold; });
```

%%%MOCHI_CARD%%%
What modern lambda features were added after C++11? #q71 #lambdas #cpp11-beyond

---

- **Generic lambdas** (C++14): `[](auto x, auto y) { return x + y; }`
- **Init capture** (C++14): `[y = x + 1]() { return y; }`
- **`constexpr` lambdas** (C++17)
- **Template lambdas** (C++20): `[]<typename T>(T x) { ... }`

Use **`mutable`** to modify value-captured copies inside the lambda body.

%%%MOCHI_CARD%%%
In about 60 seconds, explain lambda expressions. #q71 #lambdas #cpp11-beyond

---

- Inline **function objects** with **capture list**
- **`[=]`/`[&]`** control how outer variables are stored
- Perfect for **`sort`**, **`for_each`**, **`find_if`**
- C++14+ adds **generic** and **init** captures
- Watch **`[&]`** lifetime if the lambda outlives the scope
