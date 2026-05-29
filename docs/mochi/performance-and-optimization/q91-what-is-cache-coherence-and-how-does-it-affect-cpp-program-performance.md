What is cache coherence and how does it affect C++ program performance? #q91 #cache-coherence #performance

---
**Cache coherence** keeps **shared memory consistent** across CPU cores' private caches — required for correct multithreaded programs.

**Protocols:**

- **Snooping** — caches monitor the bus
- **Directory-based** — central tracker (scalable)
- **MESI** — Modified, Exclusive, Shared, Invalid states per cache line

Poor layout or sync can cause **false sharing** and unnecessary invalidations.

%%%MOCHI_CARD%%%
How does cache coherence impact C++ performance? #q91 #cache-coherence #performance

---

- **Memory model** — atomics and ordering matter for visibility
- **False sharing** — unrelated vars on same cache line → coherence traffic
- **Data locality** — layout affects cache hit rate
- **Sync overhead** — mutexes/atomics trigger coherence traffic on contention

Profile hot shared counters and pad per-thread data.

%%%MOCHI_CARD%%%
Show mitigating false sharing with padded atomics. #q91 #cache-coherence #performance

---
```cpp
struct alignas(64) PaddedInt {
    std::atomic<int> value;
    char padding[60];
};

void increment(PaddedInt& data, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        data.value.fetch_add(1, std::memory_order_relaxed);
    }
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
