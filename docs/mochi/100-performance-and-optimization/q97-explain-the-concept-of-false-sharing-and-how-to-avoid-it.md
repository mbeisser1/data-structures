Explain the concept of false sharing and how to avoid it. #q97 #false-sharing #performance

---
**False sharing** is a performance issue when multiple threads, each with its **own cache**, access **independent data** in the **same cache line** — causing excessive **cache invalidations** even though the data is not logically shared.

%%%MOCHI_CARD%%%
How does false sharing happen? #q97 #false-sharing #performance

---

1. Thread A writes **`data[i]`**, thread B writes **`data[j]`**
2. **`i`** and **`j`** fall in the **same cache line**
3. Each write invalidates the line on the other core
4. Throughput collapses despite no logical data race

Common with **adjacent counters** or array elements split across threads.

%%%MOCHI_CARD%%%
How do you avoid false sharing? #q97 #false-sharing #performance

---

**Padding / alignment**

```cpp
struct PaddedInt {
    int value;
    char padding[60];  // ~64-byte cache line
};
alignas(std::hardware_destructive_interference_size) int data1;
```

**Other tactics**

- **`thread_local`** counters, merge at end
- **Structure of arrays** with spacing for per-thread fields
- Separate hot atomics by cache line

Check target arch — some CPUs use **128-byte** lines.

%%%MOCHI_CARD%%%
Show threads modifying adjacent array regions. Why can two threads writing different indices still slow each other down? #q97 #false-sharing #performance

---
```cpp
#include <thread>
#include <vector>

constexpr int arraySize = 10000;
std::vector<int> data(arraySize);

void modifyElements(int start, int end) {
    for (int i = start; i < end; ++i) {
        data[i] = i;
    }
}

int main() {
    std::thread t1(modifyElements, 0, arraySize / 2);
    std::thread t2(modifyElements, arraySize / 2, arraySize);
    t1.join();
    t2.join();
    return 0;
}
```

Boundary elements may share a cache line — pad partitions or use per-thread padded slots.

%%%MOCHI_CARD%%%
Show avoiding false sharing with alignment. How do you keep independent counters on separate cache lines? #q97 #false-sharing #performance

---
```cpp
struct alignas(64) PaddedInt {
    std::atomic<int> value;
    char padding[60];
};

alignas(std::hardware_destructive_interference_size) int counter_a;
alignas(std::hardware_destructive_interference_size) int counter_b;
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain false sharing. #q97 #false-sharing #performance

---

- Unrelated writes, **same cache line** → coherence storm
- Fix with **padding**, **`alignas(64)`**, **thread-local** aggregation
- Distinct from true sharing — different variables, accidental line overlap
- Profile multi-threaded counters first suspect
