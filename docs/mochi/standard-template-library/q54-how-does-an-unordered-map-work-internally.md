How does an `unordered_map` work internally? #q54 #unordered-map #stl

---
**`std::unordered_map`** is a **hash table** of key-value pairs.

**Steps on insert/lookup:**

1. **Hash function** maps key → hash code
2. Hash code selects a **bucket**
3. Store or search in that bucket’s chain

**Average O(1)** insert, find, erase; **worst O(n)** if all keys collide.

%%%MOCHI_CARD%%%
How does `unordered_map` handle hash collisions? #q54 #unordered-map #stl

---

**Separate chaining** (typical in libstdc++/libc++):

- Each bucket holds a **linked list** (or similar) of entries sharing that bucket

**Open addressing** (less common in standard implementations):

- Probe for next free slot in the bucket array

**Internal picture:**

```
[Bucket 0] -> (Key1, Val1) -> (Key2, Val2)
[Bucket 1] -> (Key3, Val3)
[Bucket 2] -> (Key4, Val4) -> (Key5, Val5)
```

%%%MOCHI_CARD%%%
What are load factor and rehashing in `unordered_map`? #q54 #unordered-map #stl

---

- **Load factor** = `size / bucket_count`
- When load exceeds a threshold (~**1.0**), **rehash**:
  1. Increase bucket count
  2. Recompute hashes
  3. Redistribute all elements

Rehashing can **invalidate iterators** but references to elements usually remain valid (until erase).

Inspect with **`bucket_count()`**, **`load_factor()`**, **`max_load_factor()`**.

%%%MOCHI_CARD%%%
Show basic `unordered_map` operations. Insert `"apple"`, `"banana"`, `"cherry"` via `[]`, `insert`, and `emplace`; find `"banana"`, iterate, erase `"cherry"`, then print `size`, `bucket_count`, and `load_factor`. #q54 #unordered-map #stl

---
```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> umap;

    umap["apple"] = 5;
    umap.insert({"banana", 3});
    umap.emplace("cherry", 7);

    if (umap.find("banana") != umap.end()) {
        std::cout << "Found banana: " << umap["banana"] << std::endl;
    }

    for (const auto& [key, value] : umap) {
        std::cout << key << ": " << value << std::endl;
    }

    umap.erase("cherry");

    std::cout << "Size: " << umap.size() << std::endl;
    std::cout << "Bucket count: " << umap.bucket_count() << std::endl;
    std::cout << "Load factor: " << umap.load_factor() << std::endl;

    return 0;
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain `unordered_map` internals. #q54 #unordered-map #stl

---

- **Hash → bucket → chain** for key-value pairs
- **Collisions** handled by chaining (usually)
- **Rehash** when load factor grows — more buckets, recompute hashes
- Average **O(1)**; need good hash + equality; watch worst-case collisions
