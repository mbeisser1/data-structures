What is multithreading in C++? #q61 #multithreading #concurrency

---
**Multithreading** runs multiple **threads** concurrently within one process — sharing address space but having independent execution flow.

**Key concepts:**

- **Thread** — unit of CPU utilization
- **Concurrency** — tasks make progress over time (may interleave on one core)
- **Parallelism** — tasks run simultaneously on multiple cores

Useful for **CPU-bound** and **I/O-bound** work.

%%%MOCHI_CARD%%%
What C++11+ facilities support multithreading? #q61 #multithreading #concurrency

---

- **`std::thread`** — create/manage OS threads (`<thread>`)
- **`std::async`** — launch tasks, get **`std::future`** results
- **Atomics, mutexes, condition variables** — synchronization
- **Thread-safe standard components** — e.g. **`std::atomic`**, some stream guarantees

**Modern additions:** **`std::jthread`** (C++20), parallel algorithms (C++17), **`std::latch`/`barrier`** (C++20).

%%%MOCHI_CARD%%%
What mechanisms ensure thread safety? #q61 #multithreading #concurrency

---

- **Mutexes** — exclusive access to critical sections
- **Atomics** — lock-free updates with defined visibility
- **Lock-free algorithms** — avoid mutex deadlocks in hot paths

**Thread-safe** = safe concurrent use; **not thread-safe** = requires external synchronization.

%%%MOCHI_CARD%%%
Show a thread-safe counter with `std::atomic`. How do multiple threads increment a shared counter without data races? #q61 #multithreading #concurrency

---
```cpp
#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

std::atomic<int> counter(0);

void incrementCounter() {
    for (int i = 0; i < 100000; ++i) {
        counter++;  // Thread-safe increment
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(incrementCounter);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Counter: " << counter << std::endl;
    return 0;
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain multithreading in C++. #q61 #multithreading #concurrency

---

- Multiple **threads** share memory; coordinate with **mutexes/atomics**
- C++11+ **`<thread>`**, **`async`**, **`<atomic>`**
- Distinguish **concurrency** vs **parallelism**
- Protect shared mutable state — data races are undefined behavior
