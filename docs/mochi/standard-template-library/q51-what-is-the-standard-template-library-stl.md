What is the Standard Template Library (STL)? #q51 #stl-overview #stl

---
The **Standard Template Library (STL)** is a collection of **generic algorithms and data structures** — a core part of the C++ Standard Library for efficient, reusable code.

**Three primary components:**

- **Containers** — store collections (`vector`, `list`, `map`, …)
- **Algorithms** — operate on iterator ranges (`sort`, `find`, …)
- **Iterators** — traverse container elements uniformly

%%%MOCHI_CARD%%%
What are the advantages of using the STL? #q51 #stl-overview #stl

---

- **Performance** — highly optimized implementations
- **Reusability** — works with many types via templates
- **Reduced boilerplate** — abstracts low-level details
- **Standardization** — portable across compliant compilers
- **Type safety** — compile-time checking

%%%MOCHI_CARD%%%
What are the main STL container categories? #q51 #stl-overview #stl

---

**Sequence:** `vector`, `list`, `deque`

**Ordered associative:** `set`, `multiset`, `map`, `multimap`

**Unordered associative (C++11):** `unordered_set`, `unordered_map`, …

**Adaptors:** `stack`, `queue`, `priority_queue`

%%%MOCHI_CARD%%%
Show basic STL algorithm usage. #q51 #stl-overview #stl

---
```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {3, 1, 4, 1, 5, 9};

std::sort(v.begin(), v.end());

auto it = std::find(v.begin(), v.end(), 4);

int count = std::count_if(v.begin(), v.end(),
    [](int n) { return n % 2 == 0; });
```

%%%MOCHI_CARD%%%
What are the STL iterator categories? #q51 #stl-overview #stl

---

- **Input** — read-only, single-pass
- **Output** — write-only, single-pass
- **Forward** — multi-pass, one direction
- **Bidirectional** — forward and backward
- **Random access** — index-like (`+`, `-`, `[]`)

%%%MOCHI_CARD%%%
In about 60 seconds, explain the STL. #q51 #stl-overview #stl

---

- **Containers + iterators + algorithms** — the STL triad
- Generic, standard, and type-safe
- Pick container by access/insertion patterns; algorithms work via iterators
- Adaptors wrap underlying containers for LIFO/FIFO/priority behavior
