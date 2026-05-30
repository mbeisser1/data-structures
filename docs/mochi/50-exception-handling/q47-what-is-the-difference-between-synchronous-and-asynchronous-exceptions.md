What is the difference between synchronous and asynchronous exceptions? #q47 #sync-async-exceptions #exceptions

---

In C++, exceptions are classified as **synchronous** or **asynchronous** — they differ in behavior and typical use cases.

**Synchronous exceptions**

- Triggered by **explicit code statements** or operations
- Thrown **immediately** at the point of the issue
- Disrupt normal flow; handled with **`try`/`catch`**

**Asynchronous exceptions**

- Often caused by **external events** or **system-level issues**
- May occur **at any time** during execution
- Do not immediately disrupt flow; often **harder to catch reliably** (e.g. via **`std::promise`/`std::future`**)

%%%MOCHI_CARD%%%
Show synchronous vs asynchronous exception handling. How do you catch a direct `throw` vs an error delivered through a `future`? #q47 #sync-async-exceptions #exceptions

---
```cpp
#include <iostream>
#include <stdexcept>
#include <thread>
#include <future>

void synchronousException() {
    throw std::runtime_error("This is a synchronous exception.");
}

void asynchronousException(std::promise<void> p) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    p.set_exception(std::make_exception_ptr(
        std::runtime_error("This is an asynchronous exception.")));
}

int main() {
    try {
        synchronousException();
    } catch (const std::exception& e) {
        std::cout << "Caught synchronous exception: " << e.what() << std::endl;
    }

    std::promise<void> p;
    std::future<void> f = p.get_future();
    std::thread t(asynchronousException, std::move(p));

    try {
        f.get();
    } catch (const std::exception& e) {
        std::cout << "Caught asynchronous exception: " << e.what() << std::endl;
    }

    t.join();
    return 0;
}
```

%%%MOCHI_CARD%%%
How do you handle exceptions across thread boundaries? #q47 #sync-async-exceptions #exceptions

---

- Worker sets exception via **`promise::set_exception`**
- Caller retrieves with **`future::get()`** inside **`try`/`catch`**
- **`std::exception_ptr`** stores and rethrows across threads
- C++ does **not** use true async signals like some other languages — model async failures explicitly

%%%MOCHI_CARD%%%
In about 60 seconds, explain sync vs async exceptions. #q47 #sync-async-exceptions #exceptions

---

- **Sync** — throw at call site; normal **`catch`**
- **Async** — failure in another thread; use **`future::get()`** or **`exception_ptr`**
- Always join threads and propagate errors to a handling context
