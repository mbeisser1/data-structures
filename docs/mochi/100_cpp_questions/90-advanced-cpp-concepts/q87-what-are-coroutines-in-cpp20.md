What are coroutines in C++20? #q87 #coroutines #advanced-cpp

---
**Coroutines** (C++20) are functions that can be **suspended** and **resumed** — a structured approach to **asynchronous programming**, making event handling and I/O more manageable.

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
Show coroutine keywords in use. What does each of `co_await`, `co_yield`, and `co_return` do? #q87 #coroutines #advanced-cpp

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
Show a minimal generator coroutine. How do `promise_type` and `coroutine_handle` produce a Fibonacci sequence? #q87 #coroutines #advanced-cpp

---
```cpp
#include <coroutine>
#include <iostream>

class FibonacciGenerator {
public:
    struct promise_type {
        int current_value = 0;
        FibonacciGenerator get_return_object() {
            return FibonacciGenerator{
                std::coroutine_handle<promise_type>::from_promise(*this)};
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void unhandled_exception() { std::terminate(); }
        std::suspend_always yield_value(int value) {
            current_value = value;
            return {};
        }
    };

    FibonacciGenerator(std::coroutine_handle<promise_type> h) : handle(h) {}
    ~FibonacciGenerator() { if (handle) handle.destroy(); }

    int next() {
        handle.resume();
        return handle.promise().current_value;
    }

private:
    std::coroutine_handle<promise_type> handle;
};

FibonacciGenerator fibonacci_sequence() {
    int a = 0, b = 1;
    while (true) {
        co_yield a;
        int temp = a;
        a = b;
        b = temp + b;
    }
}
```

%%%MOCHI_CARD%%%
What are benefits of coroutines? #q87 #coroutines #advanced-cpp

---

- **Simplified asynchronous code** — reads like synchronous code
- **Efficient resource usage** — cooperative multitasking without per-task thread overhead
- **Lazy evaluation** — generate values on demand (generators)
- **Improved performance** — fewer callbacks and complex state machines
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
