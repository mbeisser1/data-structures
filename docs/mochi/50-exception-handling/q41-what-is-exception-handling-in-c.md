What is exception handling in C++? #q41 #exception-handling #exceptions

---
**Exception handling** is a mechanism to **manage and respond to unexpected events** during program execution — such as errors and abnormal conditions.

**Key components:**

- **`try` block** — code where exceptions might occur
- **`throw` statement** — explicitly signals an exception
- **`catch` block** — handles exceptions of a specific type
- **Exception classes** — predefined in the standard library (e.g. `<exception>`)

%%%MOCHI_CARD%%%
Show basic exception handling syntax. How do you throw on failure and catch a `std::exception` to print `what()`? #q41 #exception-handling #exceptions

---
```cpp
try {
    if (someErrorCondition) {
        throw std::runtime_error("An error occurred");
    }
} catch (const std::exception& e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
}
```

%%%MOCHI_CARD%%%
What are common use cases and best practices for exceptions? #q41 #exception-handling #exceptions

---

**Use cases:**

- **Error reporting and handling** — file I/O, network issues, etc.
- **Resource management** — cleanup even when errors occur
- **Abnormal situations** — unexpected behavior (e.g. division by zero)

**Best practices:**

- Use exceptions for **exceptional** situations, not regular control flow
- **Avoid throwing in destructors**
- **Document** functions that may throw
- Provide **strong exception guarantees** where possible
- Use **`noexcept`** for functions that don’t throw

%%%MOCHI_CARD%%%
What is the standard exception hierarchy in C++? #q41 #exception-handling #exceptions

---

- **`std::exception`**
  - **`std::logic_error`**
    - **`std::invalid_argument`**
    - **`std::domain_error`**
    - **`std::length_error`**
    - **`std::out_of_range`**
  - **`std::runtime_error`**
    - **`std::range_error`**
    - **`std::overflow_error`**
    - **`std::underflow_error`**
    - **`std::system_error`**

Catch **`const std::exception&`** for a wide net; more specific types for targeted handling.

%%%MOCHI_CARD%%%
In about 60 seconds, explain exception handling in C++. #q41 #exception-handling #exceptions

---

- **`try` / `throw` / `catch`** for structured error handling
- Use for **errors**, not everyday branching
- Standard hierarchy under **`std::exception`**
- **`noexcept`**, **RAII**, and clear guarantees matter
- Throwing has cost — use error codes in hot paths when appropriate
