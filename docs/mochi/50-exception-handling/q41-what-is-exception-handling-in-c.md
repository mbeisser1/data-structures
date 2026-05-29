What is exception handling in C++? #q41 #exception-handling #exceptions

---
**Exception handling** manages **unexpected errors** and abnormal conditions during execution — separating error paths from normal control flow.

**Key components:**

- **`try`** — code that may throw
- **`throw`** — signal an exception
- **`catch`** — handle a specific exception type
- **Exception classes** — from `<exception>`, `<stdexcept>`, etc.

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

- **I/O and network errors**
- **Resource cleanup** on failure paths
- **Abnormal conditions** (e.g. invalid input)

**Best practices:**

- Use for **exceptional** situations, not regular control flow
- **Don’t throw from destructors**
- Document throwing functions
- Prefer **strong guarantees** where possible
- Mark non-throwing functions **`noexcept`**

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
