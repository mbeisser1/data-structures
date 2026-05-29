What is a memory leak and how can it be prevented? #q13 #memory-leak #memory-pointers

---
A **memory leak** happens when memory is **allocated but never freed** after it is no longer needed, slowly reducing available memory and hurting performance or causing crashes.

%%%MOCHI_CARD%%%
What commonly causes memory leaks? #q13 #memory-leak #memory-pointers

---

- **Missing deallocation** — no matching `delete` for `new` or `free` for `malloc`.
- **Complex structures** — forgetting to free nodes in lists/trees/graphs.
- **Circular references** — with **`shared_ptr`**, cycles can keep objects alive indefinitely.

%%%MOCHI_CARD%%%
Show RAII, smart pointers, and manual management (leak risk). #q13 #memory-leak #memory-pointers

---
```cpp
#include <iostream>
#include <memory>

class MyResource {
public:
    MyResource() { std::cout << "Resource acquired!\n"; }
    ~MyResource() { std::cout << "Resource released!\n"; }
};

void manualManagement() {
    MyResource* resource = new MyResource();
    // delete resource;  // Omitting this leaks memory
}

void raii() {
    MyResource resource;  // Released when out of scope
}

void smartPointers() {
    auto resource = std::make_unique<MyResource>();
}
```

- **RAII** and **smart pointers** prevent leaks; raw **`new` without `delete`** leaks.

%%%MOCHI_CARD%%%
How do you prevent memory leaks in C++? #q13 #memory-leak #memory-pointers

---

- **RAII** — acquire in constructor, release in destructor.
- **Smart pointers:**
  - **`unique_ptr`**
  - **`shared_ptr`**
  - **`weak_ptr`** (use **`weak_ptr`** to break cycles)
- **Stack allocation** when lifetime matches scope.
- **Clear ownership** — one obvious owner for each resource.

%%%MOCHI_CARD%%%
In about 60 seconds, explain memory leaks and prevention. #q13 #memory-leak #memory-pointers

---

- Causes:
  - Missed **`delete` / `free`**
  - **Complex structures** (lists/trees/graphs)
  - **`shared_ptr` cycles**
- Prevent with:
  - **RAII**
  - **Smart pointers**
  - **Stack** objects when lifetime matches scope
  - Explicit **ownership** rules
