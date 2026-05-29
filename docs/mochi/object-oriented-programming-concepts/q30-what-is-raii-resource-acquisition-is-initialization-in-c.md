What is RAII (Resource Acquisition Is Initialization) in C++? #q30 #raii #oop-concepts

---
**RAII** ties **resource lifetime** to **object lifetime** — acquire in the **constructor**, release in the **destructor**. Gives **deterministic cleanup** and **exception safety** for memory, files, locks, etc.

**Benefits:**

- **Automatic** release at scope end
- **Exception-safe** cleanup
- Less manual **`new`/`delete`** or **`open`/`close`**

%%%MOCHI_CARD%%%
Show RAII resource acquisition and release with a file handler. #q30 #raii #oop-concepts

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

- Constructor **opens**; destructor **closes** — even if an exception is thrown

%%%MOCHI_CARD%%%
What standard library types implement RAII? #q30 #raii #oop-concepts

---

- **`std::unique_ptr`** / **`std::shared_ptr`** — heap memory
- **`std::lock_guard`** / **`std::unique_lock`** — mutexes
- **`std::fstream`** and related — file handles
- Containers like **`std::vector`** — manage their own storage

%%%MOCHI_CARD%%%
Show RAII with `std::unique_ptr`. #q30 #raii #oop-concepts

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
- **Exception-safe**, deterministic cleanup
- Modern C++: **smart pointers**, **lock guards**, **streams**, containers
- Core pattern behind much of safe C++ resource handling
