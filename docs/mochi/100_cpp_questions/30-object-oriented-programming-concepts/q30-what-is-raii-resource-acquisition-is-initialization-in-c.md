What is RAII (Resource Acquisition Is Initialization) in C++? #q30 #raii #oop-concepts

---
**RAII** (Resource Acquisition Is Initialization) is a fundamental C++ pattern for **efficient, deterministic resource management** — memory, file handles, network connections, locks, and more.

The core idea: **tie a resource’s lifecycle to an object’s lifetime** — acquire in the **constructor**, release in the **destructor**.

**Benefits:**

- **Automatic resource management** when the object goes out of scope
- **Exception safety** — cleanup still runs if an exception is thrown
- **Simpler code** — less explicit **`new`/`delete`** or **`open`/`close`**

%%%MOCHI_CARD%%%
Show RAII with a file handler. How do you acquire a file in the constructor and release it in the destructor? #q30 #raii #oop-concepts

---
```cpp
#include <fstream>
#include <stdexcept>
#include <string>

class FileHandler {
    std::ifstream file;

public:
    FileHandler(const std::string& filename) : file(filename) {
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }
    }

    ~FileHandler() {
        if (file.is_open()) {
            file.close();
        }
    }
};
```

%%%MOCHI_CARD%%%
What standard library types implement RAII? #q30 #raii #oop-concepts

---

- **`std::unique_ptr`** — exclusive ownership of dynamic objects
- **`std::shared_ptr`** — shared ownership of dynamic objects
- **`std::lock_guard`** / **`std::unique_lock`** — automatic mutex management
- **`std::fstream`** and related — file I/O with automatic closing

%%%MOCHI_CARD%%%
Show RAII with `std::unique_ptr`. How does a heap `Resource` get acquired and released around a function call? #q30 #raii #oop-concepts

---
```cpp
#include <memory>
#include <iostream>

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource released\n"; }
    void use() { std::cout << "Resource used\n"; }
};

void raiiDemo() {
    std::unique_ptr<Resource> res = std::make_unique<Resource>();
    res->use();
}  // Resource released automatically

int main() {
    raiiDemo();
    return 0;
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain RAII. #q30 #raii #oop-concepts

---

- **Acquire in ctor, release in dtor** — scope-bound resource management
- **Automatic** and **exception-safe** cleanup
- Standard library: **smart pointers**, **lock guards**, **streams**
- Core pattern behind safe C++ resource handling
