Explain the concept of iterators in STL. #q56 #iterators #stl

---
**Iterators** are objects that **traverse and access** container elements — the glue between **containers** and **algorithms**.

**Advantages:**

- Generic algorithms work on any container with suitable iterators
- Enable **range-based for** (C++11)
- Consistent traversal interface
- Often avoid manual index bookkeeping

%%%MOCHI_CARD%%%
What are the STL iterator categories? #q56 #iterators #stl

---

1. **Input** — read-only, single-pass
2. **Output** — write-only, single-pass
3. **Forward** — multi-pass, one direction
4. **Bidirectional** — `++` and `--`
5. **Random access** — `+`, `-`, `[]`, `<`
6. **Contiguous** (C++17) — elements in contiguous memory (`vector`)

Stronger categories satisfy weaker category requirements.

%%%MOCHI_CARD%%%
Show detecting a random-access iterator category. #q56 #iterators #stl

---
```cpp
#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5};
    auto it = vec.begin();

    if constexpr(std::is_same_v<std::random_access_iterator_tag,
                 typename std::iterator_traits<decltype(it)>::iterator_category>) {
        std::cout << "Vector iterator is Random Access\n";
    }
}
```

%%%MOCHI_CARD%%%
Show regular, const, reverse, and algorithm iterators. #q56 #iterators #stl

---
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5};

    auto it = vec.begin();
    std::cout << "First element: " << *it << '\n';

    auto cit = vec.cbegin();
    // *cit = 10; // Error: read-only

    auto rit = vec.rbegin();
    std::cout << "Last element: " << *rit << '\n';

    std::for_each(vec.begin(), vec.end(), [](int& n) { n *= 2; });
}
```

Also: **move iterators** (`std::make_move_iterator`) transfer ownership (C++11).

%%%MOCHI_CARD%%%
What C++20 iterator concepts correspond to categories? #q56 #iterators #stl

---

- **`std::input_iterator`**
- **`std::output_iterator`**
- **`std::forward_iterator`**
- **`std::bidirectional_iterator`**
- **`std::random_access_iterator`**
- **`std::contiguous_iterator`**

Concepts give clearer algorithm requirements than category tags alone.

%%%MOCHI_CARD%%%
In about 60 seconds, explain STL iterators. #q56 #iterators #stl

---

- **Uniform pointer-like access** to container elements
- **Categories** limit which algorithms apply (e.g. `sort` needs random access)
- **`begin`/`end`**, **`cbegin`/`cend`**, **`rbegin`** — common iterator types
- C++20 **concepts** formalize iterator capabilities
