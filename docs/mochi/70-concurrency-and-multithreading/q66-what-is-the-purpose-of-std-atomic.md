What is the purpose of `std::atomic`? #q66 #std-atomic #concurrency

---
**`std::atomic`** handles **concurrent data access** and ensures **memory visibility** in multithreaded programs — achieving synchronization through **hardware and memory model** support, often more efficient than locks for simple operations.

**Purpose:**

- Prevent **data races** on a single variable
- Avoid mutex overhead for simple counters/flags
- Control **memory ordering** for performance vs correctness

Backed by hardware primitives (e.g. **compare-and-swap**).

%%%MOCHI_CARD%%%
What are key features of `std::atomic`? #q66 #std-atomic #concurrency

---

- **Thread safety** — operations are indivisible
- **Memory visibility** — stores visible to other threads per memory order
- **Efficiency** — often faster than mutex for single-word updates
- **Operations** — `load`, `store`, `fetch_add`, `compare_exchange_weak/strong`

Works on integral types, pointers, and user types meeting **`is_trivially_copyable`** requirements.

%%%MOCHI_CARD%%%
Show thread-safe increment with `std::atomic`. How do multiple threads safely increment the same counter? #q66 #std-atomic #concurrency

---
```cpp
#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> sharedValue(0);

void incrementSharedValue() {
    for (int i = 0; i < 1000000; ++i) {
        sharedValue.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    std::thread t1(incrementSharedValue);
    std::thread t2(incrementSharedValue);
    t1.join();
    t2.join();
    std::cout << "Final shared value: " << sharedValue.load() << std::endl;
    return 0;
}
```

%%%MOCHI_CARD%%%
What should you consider when using atomics? #q66 #std-atomic #concurrency

---

- Prefer **`fetch_add`**, **`compare_exchange`** over non-atomic read-modify-write
- Choose appropriate **`std::memory_order`** — default is **`seq_cst`** (strongest)
- **`memory_order_relaxed`** OK for independent counters
- Atomics **don’t compose** — protecting a struct may still need a mutex
- Complex invariants → mutex or careful lock-free design

%%%MOCHI_CARD%%%
In about 60 seconds, explain `std::atomic`. #q66 #std-atomic #concurrency

---

- **Lock-free** atomic ops on shared variables
- Prevents **data races** on that variable
- **`memory_order`** tunes synchronization cost
- Great for flags/counters; not a full replacement for mutexes on complex state
