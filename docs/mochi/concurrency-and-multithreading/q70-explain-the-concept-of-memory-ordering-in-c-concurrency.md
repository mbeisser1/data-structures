Explain the concept of memory ordering in C++ concurrency. #q70 #memory-ordering #concurrency

---
**Memory ordering** rules define **which writes become visible** to other threads and in what order — critical because CPUs and compilers **reorder** operations and use **per-core caches**.

**`std::atomic`** operations accept **`std::memory_order`** to trade **performance** for **synchronization strength**.

Without proper ordering, threads may see **stale or reordered** values.

%%%MOCHI_CARD%%%
What are the C++ memory orderings? #q70 #memory-ordering #concurrency

---

- **`relaxed`** — atomicity only, no ordering
- **`consume`** — deprecated; dependent-load ordering
- **`acquire`** — reads after this see prior **release** writes
- **`release`** — prior writes visible to subsequent **acquire** reads
- **`acq_rel`** — read-modify-write with both
- **`seq_cst`** — **sequential consistency** (default; strongest)

**Acquire/release** pair for handoff; **`seq_cst`** when in doubt.

%%%MOCHI_CARD%%%
Show relaxed ordering for a simple counter. #q70 #memory-ordering #concurrency

---
```cpp
std::atomic<int> counter(0);

void increment() {
    for (int i = 0; i < 1000; ++i) {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

// main: join threads, then
counter.load(std::memory_order_relaxed);
```

**Relaxed** is fine when the atomic itself is the only shared state.

%%%MOCHI_CARD%%%
Show acquire-release synchronization. #q70 #memory-ordering #concurrency

---
```cpp
std::atomic<bool> ready(false);
int data = 0;

void producer() {
    data = 42;
    ready.store(true, std::memory_order_release);
}

void consumer() {
    while (!ready.load(std::memory_order_acquire)) { }
    std::cout << "Data: " << data << std::endl;  // sees 42
}
```

**Release** publishes `data`; **acquire** ensures reads after load see those writes.

%%%MOCHI_CARD%%%
What is sequential consistency (`seq_cst`)? #q70 #memory-ordering #concurrency

---
```cpp
std::atomic<int> x(0), y(0);

void thread1() {
    x.store(1, std::memory_order_seq_cst);
    int r1 = y.load(std::memory_order_seq_cst);
}

void thread2() {
    y.store(1, std::memory_order_seq_cst);
    int r2 = x.load(std::memory_order_seq_cst);
}
```

**`seq_cst`** — all threads agree on a single global order of seq_cst ops.

**Default** for atomics — safest, sometimes slower than minimal ordering.

%%%MOCHI_CARD%%%
In about 60 seconds, explain memory ordering. #q70 #memory-ordering #concurrency

---

- CPUs reorder — atomics + memory order define visibility
- **`relaxed`** = counter only; **release/acquire** = publish/subscribe
- **`seq_cst`** = default, strongest, easiest to reason about
- Weaken ordering only with a clear happens-before story
