What is cache coherence and how does it affect C++ program performance? #q91 #cache-coherence #performance

---
**Cache coherence** is crucial in multi-core systems — it ensures **shared data remains consistent** across different CPU caches, essential for correct behavior in parallel programs.

**Protocols:**

- **Snooping** — caches monitor the bus
- **Directory-based** — central tracker (scalable)
- **MESI** — Modified, Exclusive, Shared, Invalid states per cache line

Poor layout or sync can cause **false sharing** and unnecessary invalidations.

%%%MOCHI_CARD%%%
How does cache coherence impact C++ performance? #q91 #cache-coherence #performance

---

- **Memory model** (C++11+) — understand ordering to prevent data races
- **False sharing** — different cores modify vars in the same cache line
- **Data locality** — padding/alignment improve cache utilization
- **Synchronization overhead** — coherence traffic under contention

Profile hot shared counters and pad per-thread data.

%%%MOCHI_CARD%%%
Show mitigating false sharing with padded atomics. How can per-thread counters avoid invalidating each other's cache lines? #q91 #cache-coherence #performance

---
```cpp
#include <atomic>
#include <thread>
#include <vector>
#include <iostream>

struct alignas(64) PaddedInt {
    std::atomic<int> value;
    char padding[60];
};

void increment(PaddedInt& data, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        data.value.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    const int num_threads = 4;
    std::vector<PaddedInt> data(num_threads);
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(increment, std::ref(data[i]), 10000000);
    }
    for (auto& t : threads) t.join();
    return 0;
}
```

Each thread updates its **own cache line** — avoids cross-core invalidation on adjacent ints.

%%%MOCHI_CARD%%%
In about 60 seconds, explain cache coherence. #q91 #cache-coherence #performance

---

- Multi-core caches must stay **consistent** on shared writes
- **False sharing** = performance killer on adjacent hot fields
- **Pad/align** per-thread counters; use **`memory_order`** appropriately
- Coherence traffic rises with **contended** shared memory
