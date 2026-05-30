How do you handle race conditions in C++? #q69 #race-conditions #concurrency

---
A **race condition** occurs when multiple threads access **shared data** concurrently, **at least one thread modifies** the data, and access is **unsynchronized** — leading to unpredictable behavior and hard-to-reproduce bugs.

**Fixes:**

- **Mutexes** — exclusive access to critical sections
- **Atomics** — lock-free updates to single variables
- **Reduce sharing** — design away shared mutable state

%%%MOCHI_CARD%%%
Show preventing races with a mutex. How do you make a shared counter increment thread-safe? #q69 #race-conditions #concurrency

---
```cpp
std::mutex m;
int shared_data = 0;

void increment() {
    std::lock_guard<std::mutex> lock(m);
    shared_data++;
}
```

%%%MOCHI_CARD%%%
Show preventing races with an atomic. How do you increment without a mutex when only one variable is shared? #q69 #race-conditions #concurrency

---
```cpp
std::atomic<int> counter(0);

void increment_atomic() {
    counter++;
}
```

%%%MOCHI_CARD%%%
What advanced techniques address race conditions? #q69 #race-conditions #concurrency

---

- **Memory ordering** on atomics — `release`/`acquire` pairs
- **Lock-free structures** — CAS loops (e.g. lock-free stack)
- **`thread_local`** — per-thread copies, no cross-thread race
- **High-level APIs** — **`async`/`future`**, message passing
- **`scoped_lock`** (C++17) when locking multiple mutexes

%%%MOCHI_CARD%%%
Show combining atomics and mutexes. When might you use an atomic for a fast count and a mutex for related state? #q69 #race-conditions #concurrency

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
