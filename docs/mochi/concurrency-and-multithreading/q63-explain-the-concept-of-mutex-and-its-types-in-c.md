Explain the concept of mutex and its types in C++. #q63 #mutex #concurrency

---
A **mutex** (mutual exclusion) ensures **only one thread** holds a lock on a shared resource at a time — preventing **data races**.

**C++ mutex types:**

- **`std::mutex`** — basic exclusive lock
- **`std::recursive_mutex`** — same thread may lock repeatedly
- **`std::timed_mutex`** — **`try_lock_for`/`try_lock_until`**
- **`std::recursive_timed_mutex`** — recursive + timed
- **`std::shared_mutex`** (C++17) — many readers **or** one writer

%%%MOCHI_CARD%%%
Show basic `std::mutex` with `lock_guard`. How do you serialize access to a shared resource from multiple threads? #q63 #mutex #concurrency

---
```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

void sharedResourceAccess(int threadId) {
    std::lock_guard<std::mutex> lock(m);
    std::cout << "Thread " << threadId << " is accessing the shared resource.\n";
}

int main() {
    std::thread t1(sharedResourceAccess, 1);
    std::thread t2(sharedResourceAccess, 2);
    t1.join();
    t2.join();
    return 0;
}
```

%%%MOCHI_CARD%%%
When should you use `recursive_mutex` vs `timed_mutex`? #q63 #mutex #concurrency

---

**`std::recursive_mutex`**

- Same thread locks **multiple times** (nested calls)
- Must unlock equally many times
- Use sparingly — often a design smell

**`std::timed_mutex`**

- **`try_lock_for(duration)`** — avoid blocking forever
- Useful for deadlock avoidance or backoff strategies

%%%MOCHI_CARD%%%
Show `shared_mutex` for reader-writer locking. How can many readers share access while writers stay exclusive? #q63 #mutex #concurrency

---
```cpp
#include <shared_mutex>

std::shared_mutex sharedMutex;
int sharedData = 0;

void reader(int id) {
    std::shared_lock<std::shared_mutex> lock(sharedMutex);
    // read sharedData
}

void writer(int id) {
    std::unique_lock<std::shared_mutex> lock(sharedMutex);
    sharedData++;
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain mutex types. #q63 #mutex #concurrency

---

- **`mutex`** = exclusive critical section
- **`recursive_mutex`** = re-entrant locking
- **`timed_mutex`** = try with timeout
- **`shared_mutex`** = many readers, one writer
- Always pair with **RAII lock guards**
