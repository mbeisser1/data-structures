Explain the difference between `std::async` and `std::thread`. #q67 #async-vs-thread #concurrency

---

Both **`std::thread`** and **`std::async`** enable **concurrent execution** in C++11+, but with distinct features and use cases.

**`std::thread`**

- **Low-level** threading tool tied to a hardware thread (on most systems)
- **Direct control** — thread starts **immediately** on construction
- Return values need **`join`** plus **`promise`/`future`** or shared state
- Uncaught exception → **`std::terminate`**

**`std::async`**

- **Higher-level** task-based parallelism (often uses a **thread pool**)
- Returns **`std::future`** for the result directly
- **Launch policies:** `async`, `deferred`, or default (either)
- Exceptions propagate to the **`future`**, rethrown on **`get()`**

%%%MOCHI_CARD%%%
Show basic `std::thread` usage. How do you start background work and wait for it to complete? #q67 #async-vs-thread #concurrency

---
```cpp
#include <iostream>
#include <thread>

void backgroundTask() {
    std::cout << "Running on a background thread\n";
}

int main() {
    std::thread t(backgroundTask);
    t.join();
    return 0;
}
```

%%%MOCHI_CARD%%%
Show basic `std::async` usage. How do you launch a task and retrieve its result? #q67 #async-vs-thread #concurrency

---
```cpp
#include <iostream>
#include <future>

int computeResult() {
    return 42;
}

int main() {
    std::future<int> result = std::async(std::launch::async, computeResult);
    std::cout << "Result from async task: " << result.get() << "\n";
    return 0;
}
```

%%%MOCHI_CARD%%%
When should you choose `thread` vs `async`? #q67 #async-vs-thread #concurrency

---

**Prefer `std::thread` when:**

- Fine-grained thread control needed
- Long-running worker threads
- Platform-specific thread features

**Prefer `std::async` when:**

- Task with **return value** or exception propagation
- Short-lived parallel work
- You want simpler lifecycle management

**C++20:** **`std::jthread`** auto-joins — bridges some `thread` pain points.

%%%MOCHI_CARD%%%
In about 60 seconds, explain async vs thread. #q67 #async-vs-thread #concurrency

---

- **`thread`** = raw thread, manual join, no built-in result
- **`async`** = task + **`future`**, deferred or async launch
- **`async`** handles exceptions via **`future::get()`**
- Use **`async`** for task parallelism; **`thread`** for persistent workers
