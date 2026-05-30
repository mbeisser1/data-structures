What is the difference between `set` and `multiset`? #q55 #set-vs-multiset #stl

---
**`std::set`** and **`std::multiset`** are associative containers that store **sorted keys**. The primary distinction is how they handle **duplicate elements** (typically **red-black tree**, **O(log n)**).

**`std::set`**

- **Unique keys only**
- Duplicate insert → **no effect** (insert returns `{iterator, false}`)

**`std::multiset`**

- **Duplicate keys allowed**
- Every insert **adds another** equal key

%%%MOCHI_CARD%%%
Show `set` vs `multiset` insertion behavior. What happens to `size()` when you insert a duplicate key into each? #q55 #set-vs-multiset #stl

---
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> s = {1, 2, 3};
    std::multiset<int> ms = {1, 2, 3};

    s.insert(2);  // No effect, 2 already exists
    ms.insert(2); // Adds another 2

    std::cout << "set size: " << s.size() << std::endl;        // 3
    std::cout << "multiset size: " << ms.size() << std::endl;  // 4

    return 0;
}
```

%%%MOCHI_CARD%%%
When should you use `set` vs `multiset`? #q55 #set-vs-multiset #stl

---

**`set`**

- Unique sorted collection
- Membership tests, ordered unique elements

**`multiset`**

- **Frequency counting** with sorted order
- Multiple equal keys (e.g. event timestamps with duplicates)

Both support **`count(key)`** — `set` returns 0 or 1; `multiset` returns how many match.

%%%MOCHI_CARD%%%
What is the performance of `set` and `multiset`? #q55 #set-vs-multiset #stl

---

- Underlying **balanced BST** → **O(log n)** insert, erase, find
- **Sorted iteration** in O(n)
- **C++20:** heterogeneous lookup — search with comparable types without converting to `key_type`

Same complexity; **`multiset`** may store more nodes when duplicates are common.

%%%MOCHI_CARD%%%
In about 60 seconds, explain set vs multiset. #q55 #set-vs-multiset #stl

---

- Both = **sorted associative** containers, tree-backed, O(log n)
- **`set`** = unique keys; **`multiset`** = duplicates OK
- Use **`set`** for uniqueness; **`multiset`** for sorted bags / counts
