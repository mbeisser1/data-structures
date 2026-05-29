What happens if an exception is not caught? #q45 #uncaught-exceptions #exceptions

---
An uncaught exception **propagates up the call stack** via **stack unwinding** until a matching **`catch`** is found — or the program **terminates**.

%%%MOCHI_CARD%%%
What happens during stack unwinding for an uncaught exception? #q45 #uncaught-exceptions #exceptions

---

1. Search for a matching **`catch`** up the stack
2. Destroy **local objects** in reverse construction order (call **destructors**)
3. Pop stack frames until a handler is found or **`main`** is exhausted

If never caught → **`std::terminate()`** → typically **`std::abort()`**.

%%%MOCHI_CARD%%%
Show exception propagation through the call stack. How does an exception thrown in `inner_function` reach a handler in `main`? #q45 #uncaught-exceptions #exceptions

---
```cpp
#include <iostream>
#include <stdexcept>

void inner_function() {
    throw std::runtime_error("Error in inner_function");
}

void middle_function() {
    inner_function();  // Exception propagates
}

int main() {
    try {
        middle_function();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}
```

%%%MOCHI_CARD%%%
What happens with uncaught exceptions and `noexcept`? #q45 #uncaught-exceptions #exceptions

---

- **`std::set_terminate()`** — customize handler called before abort
- **`noexcept` function** — if an exception escapes → **`std::terminate()`** immediately (**no normal unwinding**)
- Use **RAII** so destructors still clean up during normal unwinding

%%%MOCHI_CARD%%%
Show uncaught exceptions violating `noexcept`. What happens if a `noexcept` function throws? #q45 #uncaught-exceptions #exceptions

---
```cpp
void func() noexcept {
    throw std::runtime_error("Error");  // Immediate termination
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain uncaught exceptions. #q45 #uncaught-exceptions #exceptions

---

- Unhandled throw → **unwind stack**, run **dtors**, search **`catch`**
- Reaches top with no handler → **`std::terminate`**
- **`noexcept` violation** → terminate without full unwind
- **RAII** ensures cleanup while unwinding
