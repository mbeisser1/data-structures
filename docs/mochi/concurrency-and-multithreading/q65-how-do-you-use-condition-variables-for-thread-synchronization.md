How do you use condition variables for thread synchronization? #q65 #condition-variable #concurrency

---
**`std::condition_variable`** lets threads **wait until a condition becomes true**, coordinated with a **`std::mutex`**.

**Pattern:**

```cpp
std::unique_lock<std::mutex> lock(mtx);
cv.wait(lock, []{ return condition; });  // wait with predicate
// condition is true — process shared state
```

Notifier sets state under the lock, then **`notify_one()`** or **`notify_all()`**.

%%%MOCHI_CARD%%%
What are the key `condition_variable` operations? #q65 #condition-variable #concurrency

---

- **`wait(lock)`** — wait until notified (must re-check condition)
- **`wait(lock, predicate)`** — wait until predicate true (handles spurious wakeups)
- **`wait_for`/`wait_until`** — timed wait (C++11)
- **`notify_one()`** — wake **one** waiter
- **`notify_all()`** — wake **all** waiters

Always use **`unique_lock`** (not `lock_guard`) — `wait` unlocks/relocks the mutex.

%%%MOCHI_CARD%%%
Show producer-consumer with condition variables. #q65 #condition-variable #concurrency

---
```cpp
std::queue<int> buffer;
const int max_buffer_size = 10;
std::mutex mtx;
std::condition_variable buffer_not_full;
std::condition_variable buffer_not_empty;

void producer(int id) {
    for (int i = 0; i < 20; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        buffer_not_full.wait(lock, []{ return buffer.size() < max_buffer_size; });
        buffer.push(i);
        lock.unlock();
        buffer_not_empty.notify_one();
    }
}

void consumer(int id) {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        buffer_not_empty.wait(lock, []{ return !buffer.empty(); });
        buffer.pop();
        lock.unlock();
        buffer_not_full.notify_one();
    }
}
```

Two CVs: wait when **full** (producer) or **empty** (consumer).

%%%MOCHI_CARD%%%
What are best practices for condition variables? #q65 #condition-variable #concurrency

---

- Always protect shared state with the **same mutex**
- Use the **predicate form** of `wait` — guards spurious wakeups
- **`notify_one`** when one thread can proceed; **`notify_all`** when many must re-check
- Set condition **before** notify, while holding the lock
- Prefer **`std::condition_variable_any`** with custom lockable types when needed

%%%MOCHI_CARD%%%
In about 60 seconds, explain condition variables. #q65 #condition-variable #concurrency

---

- **`wait`** atomically releases mutex and sleeps until notified
- **Predicate wait** = correct pattern for "queue non-empty" etc.
- **Producer/consumer** is the classic use case
- Mutex + shared flag/queue + **notify**
