How do you create and manage threads using `std::thread`? #q62 #std-thread #concurrency

---
Create a **`std::thread`** with a **callable** (function, lambda, functor).

**Always** **`join()`** or **`detach()`** before destruction — otherwise **`std::terminate`**.

%%%MOCHI_CARD%%%
Show creating and joining `std::thread`. How do you start a worker thread and wait for it to finish? #q62 #std-thread #concurrency

---
```cpp
#include <iostream>
#include <thread>

void threadFunction() {
    std::cout << "Hello from thread\n";
}

int main() {
    std::thread t(threadFunction);
    t.join();
    return 0;
}
```

%%%MOCHI_CARD%%%
What is the difference between `join()` and `detach()`? #q62 #std-thread #concurrency

---

**`join()`**

- Blocks until the thread **finishes**
- Reclaims thread resources
- Preferred — you can observe completion

**`detach()`**

- Thread runs **independently**
- No way to wait for it — risky for lifetime of captured data
- **Avoid** unless you have a clear shutdown strategy

Check **`t.joinable()`** before join/detach.

%%%MOCHI_CARD%%%
Show creating threads with functions and arguments. How do you pass arguments to a thread function safely? #q62 #std-thread #concurrency

---
```cpp
#include <iostream>
#include <thread>

void threadFunction(int x, std::string str) {
    std::cout << "Received: " << x << ", " << str << std::endl;
}

int main() {
    std::thread t(threadFunction, 42, "Hello");
    t.join();
    return 0;
}
```

%%%MOCHI_CARD%%%
How do you synchronize shared data with `std::thread`? #q62 #std-thread #concurrency

---

- Use **`std::lock_guard`**, **`std::unique_lock`**, or **`std::scoped_lock`** (C++17) for RAII locking
- **Condition variables** coordinate waiting/signaling under the same mutex
- **Threads are move-only** — transfer ownership with **`std::move`**

%%%MOCHI_CARD%%%
Show synchronizing shared data with threads. How do you protect a shared counter while multiple threads increment? #q62 #std-thread #concurrency

---
```cpp
#include <mutex>

std::mutex mtx;
int sharedResource = 0;

void threadFunction() {
    std::lock_guard<std::mutex> lock(mtx);
    sharedResource++;
}
```

%%%MOCHI_CARD%%%
What are best practices for `std::thread`? #q62 #std-thread #concurrency

---

- Prefer **`std::jthread`** (C++20) — auto-join on destruction
- Use **`std::async`** when you need return values via **`future`**
- **Avoid detached threads** — hard to debug, lifetime bugs
- **`try`/`catch`** inside thread functions — uncaught exceptions terminate the program
- Always synchronize **shared mutable state**

%%%MOCHI_CARD%%%
In about 60 seconds, explain `std::thread`. #q62 #std-thread #concurrency

---

- Construct with callable → thread starts
- **`join`** to wait; **`detach`** to fire-and-forget (rarely)
- **Move-only** ownership
- Protect shared data with **mutexes**; prefer **`jthread`** or **`async`** when they fit
