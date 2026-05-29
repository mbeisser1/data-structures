Explain the difference between `vector` and `list` in STL. #q52 #vector-vs-list #stl

---

**Memory layout**

- **`vector`** — contiguous dynamic array; reallocation may **invalidate iterators**
- **`list`** — doubly linked list; **iterators stay valid** after insert/erase elsewhere

**Access**

- **`vector`** — **O(1)** random access
- **`list`** — **O(n)** to reach index *i*

%%%MOCHI_CARD%%%
Compare insertion and deletion: `vector` vs `list`. #q52 #vector-vs-list #stl

---

**`vector`**

- **O(1) amortized** at **`back`**
- **O(n)** in the middle/end (element shifting)

**`list`**

- **O(1)** insert/erase **anywhere**, given an iterator to the position

**Memory:** `vector` is more compact and cache-friendly; `list` has per-node pointer overhead.

%%%MOCHI_CARD%%%
When should you choose `vector` vs `list`? #q52 #vector-vs-list #stl

---

**Prefer `vector` when:**

- Frequent **random access**
- Mostly **push_back** / pop from back
- Size known or rarely changes

**Prefer `list` when:**

- Frequent **insert/erase in the middle**
- Iterator stability matters during mutation

**Default rule:** start with **`vector`** unless profiling shows list wins.

%%%MOCHI_CARD%%%
Show performance difference inserting at the beginning. Write a template `measureInsertionTime` that inserts 100,000 elements at `begin()`; time the same pattern on both `vector` and `list`. #q52 #vector-vs-list #stl

---
```cpp
#include <iostream>
#include <vector>
#include <list>
#include <chrono>

template<typename T>
void measureInsertionTime(T& container) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; ++i) {
        container.insert(container.begin(), i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken: " << diff.count() << " seconds\n";
}

int main() {
    std::vector<int> vec;
    std::list<int> lst;

    std::cout << "Vector insertion time:\n";
    measureInsertionTime(vec);

    std::cout << "List insertion time:\n";
    measureInsertionTime(lst);

    return 0;
}
```

**List wins** for repeated front insertions; **vector** pays O(n) shifts each time.

%%%MOCHI_CARD%%%
In about 60 seconds, explain vector vs list. #q52 #vector-vs-list #stl

---

- **`vector`** = contiguous, fast index, cheap back growth
- **`list`** = linked nodes, stable iterators, cheap middle edits
- **`vector`** is the default; use **`list`** only when iterator stability or middle churn demands it
