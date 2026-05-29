What are coroutines in C++20? #q87 #coroutines #advanced-cpp

---
**Coroutines** are functions that can **suspend** and **resume** — structured async/generator code without callback pyramids.

**Keywords:**

- **`co_await`** — suspend until awaitable completes
- **`co_yield`** — produce a value (generators)
- **`co_return`** — finish coroutine

Requires a **`promise_type`** and often **`std::coroutine_handle`**.

%%%MOCHI_CARD%%%
What are key coroutine components? #q87 #coroutines #advanced-cpp

---

- **`promise_type`** — bridge between coroutine and caller; hooks for suspend/yield/return
- **`coroutine_handle`** — resume/destroy the coroutine frame
- **Awaitable** — type with **`await_ready`/`await_suspend`/`await_resume`**
- **Generator** — coroutine that **`co_yield`**s a sequence

Compiler lowers coroutines to a **state machine** on the heap (typically).

%%%MOCHI_CARD%%%
Show coroutine keywords in use. #q87 #coroutines #advanced-cpp

---
```cpp
// co_await — suspend until task completes
auto result = co_await someTask();

// co_yield — generator-style output
std::generator<int> generateNumbers() {
    co_yield 1;
    co_yield 2;
    co_yield 3;
}

// co_return — end coroutine
co_return 42;
```

**`std::generator`** (C++23) simplifies lazy sequences.

%%%MOCHI_CARD%%%
What are benefits of coroutines? #q87 #coroutines #advanced-cpp

---

- **Readable async** — looks sequential
- **Cooperative** — less thread overhead than one thread per task
- **Lazy evaluation** — generate on demand
- Replaces hand-rolled **state machines** and deep callbacks

Tradeoff: compiler support, learning curve for **`promise_type`** boilerplate.

%%%MOCHI_CARD%%%
In about 60 seconds, explain C++20 coroutines. #q87 #coroutines #advanced-cpp

---

- **`co_await` / `co_yield` / `co_return`**
- **Promise + handle** manage suspend/resume
- Great for **async I/O** and **generators**
- C++23 **`std::generator`** lowers boilerplate
