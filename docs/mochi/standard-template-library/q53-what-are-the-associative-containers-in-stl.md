What are the associative containers in STL? #q53 #associative-containers #stl

---
**Associative containers** store **keys** (or key-value pairs) optimized for **fast lookup**.

**Ordered** (typically red-black tree, **O(log n)**):

- **`std::map`**, **`std::set`** — unique keys
- **`std::multimap`**, **`std::multiset`** — duplicate keys allowed

**Unordered** (hash table, **O(1) average**):

- **`std::unordered_map`**, **`std::unordered_set`**
- **`std::unordered_multimap`**, **`std::unordered_multiset`**

%%%MOCHI_CARD%%%
Show using `std::map`. #q53 #associative-containers #stl

---
```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> m{{1, "One"}, {2, "Two"}, {3, "Three"}};

    std::cout << "Third: " << m[3] << std::endl;

    for (const auto& [key, value] : m) {
        std::cout << key << ": " << value << std::endl;
    }

    return 0;
}
```

Elements are **sorted by key**.

%%%MOCHI_CARD%%%
Show using `std::unordered_set`. #q53 #associative-containers #stl

---
```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet = {1, 2, 3, 4, 5};

    mySet.insert(6);
    mySet.insert(7);

    if (mySet.contains(3)) {
        std::cout << "3 is in the set." << std::endl;
    }

    return 0;
}
```

**No sorted order** — hash-based average O(1) lookup.

%%%MOCHI_CARD%%%
What are key characteristics of ordered vs unordered associative containers? #q53 #associative-containers #stl

---

**Ordered**

- Sorted keys — good for **range queries** (`lower_bound`, ordered iteration)
- **O(log n)** operations

**Unordered**

- **Hash table** — faster average lookup/insert
- Requires **hash function** and **equality** for keys
- **Worst case O(n)** if many collisions

**Unique vs multi:** `map`/`set` reject duplicate keys; `multi*` allow duplicates.

%%%MOCHI_CARD%%%
In about 60 seconds, explain associative containers. #q53 #associative-containers #stl

---

- **Ordered** = tree, sorted, O(log n)
- **Unordered** = hash, average O(1)
- **set/map** = unique keys; **multi*** = duplicates OK
- Pick ordered for sorted ranges; unordered for speed when order doesn’t matter
