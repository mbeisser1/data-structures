How do you implement and use lock-free data structures for better concurrency performance? #q100 #lock-free #performance

---
**Lock-free** structures use **atomics** (especially **CAS**) so threads make progress without mutex blocking — better scalability under contention, no lock deadlocks.

Not wait-free in general — some threads may retry CAS loops.

%%%MOCHI_CARD%%%
What core mechanisms power lock-free code? #q100 #lock-free #performance

---

**Atomics:**

```cpp
counter.fetch_add(1, std::memory_order_relaxed);
```

**Compare-and-swap:**

```cpp
value.compare_exchange_strong(expected, new_value);
```

**Memory ordering** — **`release`/`acquire`** pairs publish/consume data safely.

%%%MOCHI_CARD%%%
Show producer/consumer flag synchronization. #q100 #lock-free #performance

---
```cpp
std::atomic<int> data(0);
std::atomic<bool> flag(false);

// Producer
data.store(42, std::memory_order_relaxed);
flag.store(true, std::memory_order_release);

// Consumer
while (!flag.load(std::memory_order_acquire)) {}
int result = data.load(std::memory_order_relaxed);
```

**Acquire** sees writes before **release** on the flag.

%%%MOCHI_CARD%%%
Show lock-free stack push with CAS loop. #q100 #lock-free #performance

---
```cpp
void push(const T& data) {
    Node* new_node = new Node(data);
    do {
        new_node->next = head.load(std::memory_order_relaxed);
    } while (!head.compare_exchange_weak(new_node->next, new_node,
                                         std::memory_order_release,
                                         std::memory_order_relaxed));
}
```

**ABA problem** and **safe memory reclamation** (hazard pointers, epochs) are real concerns for **`pop`**.

%%%MOCHI_CARD%%%
What are lock-free best practices? #q100 #lock-free #performance

---

- Prefer **`std::atomic`** over hand-rolled asm
- Design for **progress** without blocking
- Handle **ABA** and **reclamation** for dynamic nodes
- **Test heavily** under contention — lock-free bugs are subtle
- Use mutexes when complexity isn't justified

%%%MOCHI_CARD%%%
In about 60 seconds, explain lock-free structures. #q100 #lock-free #performance

---

- **CAS loops** instead of mutexes for hot shared structures
- **`memory_order`** defines visibility
- Hard problems: **ABA**, **memory reclamation**
- Great for queues/stacks at scale; mutex often simpler and fine
