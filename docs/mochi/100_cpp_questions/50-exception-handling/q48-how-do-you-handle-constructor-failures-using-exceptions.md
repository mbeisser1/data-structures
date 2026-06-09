How do you handle constructor failures using exceptions? #q48 #constructor-failures #exceptions

---
The recommended approach for **constructor failures** is to **throw an exception**. This ensures:

1. The object is **not left** in an invalid or partially constructed state
2. **Resources** are properly cleaned up (via **RAII**)
3. The **caller** is notified and can handle the failure

Never leave a half-built object that callers must detect manually.

%%%MOCHI_CARD%%%
Show constructor failure handling with RAII. How does `MyClass` use `unique_ptr` so a failed `Resource` initialization still cleans up? #q48 #constructor-failures #exceptions

---
```cpp
#include <iostream>
#include <stdexcept>
#include <memory>

class Resource {
public:
    Resource() {
        if (/* allocation fails */) {
            throw std::runtime_error("Resource allocation failed");
        }
    }

    void initialize() {
        if (/* initialization fails */) {
            throw std::runtime_error("Resource initialization failed");
        }
    }

    ~Resource() {
        std::cout << "Resource cleaned up" << std::endl;
    }
};

class MyClass {
private:
    std::unique_ptr<Resource> resource;

public:
    MyClass() {
        resource = std::make_unique<Resource>();
        try {
            resource->initialize();
        } catch (...) {
            throw; // unique_ptr cleans up; re-throw
        }
    }
};

int main() {
    try {
        MyClass obj;
    } catch (const std::exception& e) {
        std::cerr << "Constructor failed: " << e.what() << std::endl;
    }
    return 0;
}
```

%%%MOCHI_CARD%%%
What are best practices for constructor exceptions? #q48 #constructor-failures #exceptions

---

- Use **smart pointers** for members needing dynamic allocation
- **Re-throw** after local cleanup in ctor **`catch`**
- Keep ctors **exception-neutral** — let failures propagate
- Prefer **member initializer list** + RAII over manual two-phase init
- C++11+: failed ctor means **no object exists** — no dtor runs for that object

%%%MOCHI_CARD%%%
In about 60 seconds, explain constructor failure handling. #q48 #constructor-failures #exceptions

---

- **Throw** on failure — partial objects must not escape
- **`unique_ptr`** and RAII members auto-clean during unwind
- Caller **`catch`**es; object was never fully constructed
- Re-throw after any ctor-local cleanup
