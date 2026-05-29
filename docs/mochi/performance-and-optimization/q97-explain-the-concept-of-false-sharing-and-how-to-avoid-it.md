Explain the concept of false sharing and how to avoid it. #q97 #false-sharing #performance

---
**False sharing** occurs when **different threads** write **different variables** that live on the **same cache line** (~64 bytes). Hardware enforces coherence per **line**, not per variable — cores ping-pong invalidations.

Logically independent data; physically shared cache line.

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

**Padding / alignment:**

```cpp
struct alignas(64) PaddedInt {
    int value;
    char padding[60];
};

alignas(std::hardware_destructive_interference_size) int data1;
```

**Other tactics:**

- **`thread_local`** counters, merge at end
- **Structure of arrays** with spacing for per-thread fields
- Separate hot atomics by cache line

Check target arch — some CPUs use **128-byte** lines.

%%%MOCHI_CARD%%%
Show threads modifying adjacent array regions. #q97 #false-sharing #performance

---
```cpp
std::vector<int> data(10000);

void modifyElements(int start, int end) {
    for (int i = start; i < end; ++i) {
        data[i] = i;
    }
}

// t1: [0, n/2), t2: [n/2, n) — boundary elements may share a cache line
```

Pad or align boundary partitions; or give each thread **own padded slot**.

%%%MOCHI_CARD%%%
In about 60 seconds, explain false sharing. #q97 #false-sharing #performance

---

- Unrelated writes, **same cache line** → coherence storm
- Fix with **padding**, **`alignas(64)`**, **thread-local** aggregation
- Distinct from true sharing — different variables, accidental line overlap
- Profile multi-threaded counters first suspect
