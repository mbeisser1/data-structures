How do you handle race conditions in C++? #q69 #race-conditions #concurrency

---
A **race condition** occurs when multiple threads access shared data, **at least one writes**, and access is **unsynchronized** — leading to undefined behavior and flaky bugs.

**Fixes:**

- **Mutexes** — exclusive access to critical sections
- **Atomics** — lock-free updates to single variables
- **Reduce sharing** — design away shared mutable state

%%%MOCHI_CARD%%%
Show preventing races with mutex vs atomic. #q69 #race-conditions #concurrency

---
```cpp
// Mutex approach
std::mutex m;
int shared_data = 0;

void increment() {
    std::lock_guard<std::mutex> lock(m);
    shared_data++;
}

// Atomic approach
std::atomic<int> counter(0);

void increment_atomic() {
    counter++;
}
```

Use **`scoped_lock`** (C++17) when locking multiple mutexes.

%%%MOCHI_CARD%%%
What advanced techniques address race conditions? #q69 #race-conditions #concurrency

---

- **Memory ordering** on atomics — `release`/`acquire` pairs
- **Lock-free structures** — CAS loops (e.g. lock-free stack)
- **`thread_local`** — per-thread copies, no sharing
- **High-level APIs** — **`async`/`future`**, message passing

```cpp
thread_local int per_thread_counter = 0;  // no cross-thread race
```

%%%MOCHI_CARD%%%
Show combining atomics and mutexes in a counter. #q69 #race-conditions #concurrency

---
```cpp
class ThreadSafeCounter {
    std::atomic<int> fast_counter{0};
    mutable std::mutex m;
    int precise_counter{0};

public:
    void increment() {
        fast_counter++;
        std::lock_guard<std::mutex> lock(m);
        precise_counter++;
    }

    int get_fast_count() const {
        return fast_counter.load(std::memory_order_relaxed);
    }

    int get_precise_count() const {
        std::lock_guard<std::mutex> lock(m);
        return precise_counter;
    }
};
```

%%%MOCHI_CARD%%%
What are best practices for avoiding race conditions? #q69 #race-conditions #concurrency

---

- **Minimize shared mutable state**
- Prefer **`const`** data shared read-only
- Use **RAII locks** — never manual lock/unlock without care
- **Static analysis** (Clang thread safety attributes)
- Document thread-safety of types and functions

%%%MOCHI_CARD%%%
In about 60 seconds, explain handling race conditions. #q69 #race-conditions #concurrency

---

- Race = concurrent access + mutation + no sync → **UB**
- **Mutex** for invariants; **atomic** for single hot variables
- **`thread_local`** and message passing reduce sharing
- Prefer higher-level concurrency abstractions when possible
