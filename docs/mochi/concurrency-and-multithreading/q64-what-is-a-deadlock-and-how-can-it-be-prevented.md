What is a deadlock and how can it be prevented? #q64 #deadlock #concurrency

---
A **deadlock** occurs when threads **block forever**, each waiting for a resource held by another — work stops and resources stay locked.

**Coffman conditions** (all four required):

1. **Mutual exclusion** — resource held exclusively
2. **Hold and wait** — hold one resource while waiting for another
3. **No preemption** — resources released only voluntarily
4. **Circular wait** — cycle of threads waiting on each other

Break **any one** condition to prevent deadlock.

%%%MOCHI_CARD%%%
What are common deadlock prevention strategies? #q64 #deadlock #concurrency

---

- **Lock ordering** — always acquire mutexes in a **fixed global order**
- **Try-lock with timeout** — back off and retry
- **`std::lock(m1, m2)`** / **`scoped_lock`** — lock multiple mutexes without deadlock
- **Request all resources at once** — eliminate hold-and-wait
- **Lock-free algorithms** — no locks → no lock deadlocks

Modern systems may **detect and recover** instead of preventing entirely.

%%%MOCHI_CARD%%%
Show resource ordering to prevent circular wait. How do you lock two resources in a consistent order from different call paths? #q64 #deadlock #concurrency

---
```cpp
#include <mutex>
#include <thread>

class Resource {
public:
    Resource(int id) : id_(id) {}
    void lock() { mutex_.lock(); }
    void unlock() { mutex_.unlock(); }
    int getId() const { return id_; }
private:
    std::mutex mutex_;
    int id_;
};

void useResources(Resource& r1, Resource& r2) {
    Resource& first = (r1.getId() < r2.getId()) ? r1 : r2;
    Resource& second = (r1.getId() < r2.getId()) ? r2 : r1;

    std::lock_guard<std::mutex> lock1(first.mutex_);
    std::lock_guard<std::mutex> lock2(second.mutex_);
    // Use resources...
}
```

%%%MOCHI_CARD%%%
What modern approaches reduce deadlock risk? #q64 #deadlock #concurrency

---

- **Lock-free / wait-free** data structures
- **Transactional memory** (where available)
- **Deadlock detection** — graph cycle detection, kill/restart threads
- **Avoid nested locks** when possible — minimize lock scope and duration

Prefer **`std::scoped_lock(m1, m2)`** over manual ordering when locking two mutexes.

%%%MOCHI_CARD%%%
In about 60 seconds, explain deadlock prevention. #q64 #deadlock #concurrency

---

- Deadlock = **circular wait** on locks
- **Consistent lock order** is the most practical fix
- **`std::lock`/`scoped_lock`** for multiple mutexes
- Shorter critical sections, fewer locks, lock-free where justified
