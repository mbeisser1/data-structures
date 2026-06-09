Explain the concept of exception safety. #q46 #exception-safety #exceptions

---
**Exception safety** means writing code that **maintains consistency** and **prevents resource leaks**, even when exceptions occur — crucial for robust, reliable software.

**Key principles:**

- **RAII** — resources released via destructors
- **Exception-safe operations** — throw before committing state changes
- **Guarantees** — strong, basic, or no-throw

%%%MOCHI_CARD%%%
What are the three exception safety guarantees? #q46 #exception-safety #exceptions

---

- **Strong guarantee** — if an exception is thrown, the operation has **no effect** (state unchanged)
- **Basic guarantee** — no **resource leaks**, but state may be modified
- **No-throw guarantee** — function **never throws** (use **`noexcept`**)

%%%MOCHI_CARD%%%
Show a strong exception safety guarantee. How do you modify a `vector` only after a successful copy-and-commit? #q46 #exception-safety #exceptions

---
```cpp
void strongGuarantee(std::vector<int>& vec, int value) {
    auto tempVec = vec;  // Create a temporary copy
    tempVec.push_back(value);
    vec = std::move(tempVec);  // Only modify if all operations succeed
}
```

%%%MOCHI_CARD%%%
Show a basic exception safety guarantee. What can happen to `vector` state if an exception occurs mid-loop? #q46 #exception-safety #exceptions

---
```cpp
void basicGuarantee(std::vector<int>& vec, int count) {
    for (int i = 0; i < count; ++i) {
        try {
            vec.push_back(i);
            if (i == 3) throw std::runtime_error("Simulated error");
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
            vec.resize(vec.size() - i - 1);
            throw;  // Re-throw for caller to handle
        }
    }
}
```

%%%MOCHI_CARD%%%
Show a no-throw exception safety guarantee. How can a function promise not to propagate exceptions from `push_back`? #q46 #exception-safety #exceptions

---
```cpp
void noThrowGuarantee(std::vector<int>& vec, int value) noexcept {
    try {
        vec.push_back(value);
    } catch (...) {
        // Catch all exceptions and handle internally
    }
}
```

%%%MOCHI_CARD%%%
How does RAII support exception safety? #q46 #exception-safety #exceptions

---

- Acquire resources in **constructors**; release in **destructors**
- During stack unwinding, **dtors run automatically**
- Use **`std::unique_ptr`**, **`std::lock_guard`**, etc.
- Perform **throwing work** before mutating visible state (copy-and-swap for strong guarantee)

%%%MOCHI_CARD%%%
In about 60 seconds, explain exception safety. #q46 #exception-safety #exceptions

---

- **Strong** = all-or-nothing; **basic** = no leaks; **no-throw** = `noexcept`
- **RAII** is the foundation
- Copy-then-commit patterns give strong guarantees
- Document guarantees for container and API design
