Explain the concept of smart pointers in C++. #q15 #smart-pointers #memory-pointers

---
**Smart pointers** are objects designed for managing **dynamic memory** more safely than raw pointers. They offer **automated memory management**, improved safety (fewer leaks, dangling pointers, double deletes), and clear **scoped ownership**.

%%%MOCHI_CARD%%%
What is `std::unique_ptr`? #q15 #smart-pointers #memory-pointers

---

- **Exclusive ownership** — only one owner; **not copyable**, **movable**.
- Object destroyed when the `unique_ptr` goes out of scope.
- Lightweight default for sole ownership.

%%%MOCHI_CARD%%%
Show `unique_ptr` exclusive ownership. Why can’t you copy one `unique_ptr` to another? #q15 #smart-pointers #memory-pointers

---
```cpp
#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> uptr = std::make_unique<int>(5);
    // std::unique_ptr<int> uptr2 = uptr; // Error: not copyable
    std::cout << *uptr << std::endl;
    return 0;  // Memory released when uptr goes out of scope
}
```

%%%MOCHI_CARD%%%
What is `std::shared_ptr`? #q15 #smart-pointers #memory-pointers

---

- **Shared ownership** with **reference counting**; last owner destroys the object.
- **Thread-safe** refcount updates (not the pointed-to object itself).
- Watch **circular references** when nodes hold `shared_ptr` to each other.

%%%MOCHI_CARD%%%
Show `shared_ptr` sharing and a circular reference. What happens to lifetime when two `Node`s point at each other with `shared_ptr`? #q15 #smart-pointers #memory-pointers

---
```cpp
#include <memory>
#include <iostream>

struct Node {
    std::shared_ptr<Node> next;
};

int main() {
    std::shared_ptr<int> sptr = std::make_shared<int>(10);
    {
        std::shared_ptr<int> anotherSptr = sptr;
        std::cout << *anotherSptr << std::endl;
    }

    std::shared_ptr<Node> node1 = std::make_shared<Node>();
    std::shared_ptr<Node> node2 = std::make_shared<Node>();
    node1->next = node2;
    node2->next = node1;  // Circular reference — nodes may never destroy

    return 0;
}
```

%%%MOCHI_CARD%%%
What is `std::weak_ptr`? #q15 #smart-pointers #memory-pointers

---

- **Non-owning** observer of a `shared_ptr` target.
- Use **`lock()`** to obtain a temporary `shared_ptr` for access.
- Does not extend lifetime; useful to **break cycles**.

%%%MOCHI_CARD%%%
Show `weak_ptr` observation with `lock()`. How does `lock()` behave while the object is alive vs after the last `shared_ptr` is gone? #q15 #smart-pointers #memory-pointers

---
```cpp
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> sPtr = std::make_shared<int>(42);
    std::weak_ptr<int> wPtr = sPtr;

    if (auto locked = wPtr.lock()) {
        std::cout << "Value: " << *locked << std::endl;
    }

    sPtr.reset();

    if (auto locked = wPtr.lock()) {
        std::cout << "Value: " << *locked << std::endl;
    } else {
        std::cout << "The object is no longer available.\n";
    }

    return 0;
}
```

%%%MOCHI_CARD%%%
What are smart pointer best practices? #q15 #smart-pointers #memory-pointers

---

- Use **`make_unique` / `make_shared`** to create them.
- Default to **`unique_ptr`**; use **`shared_ptr`** only when sharing is required.
- Use **`weak_ptr`** to observe shared objects and break cycles.
- Don’t mix **raw owning pointers** with smart pointers for the same resource.

%%%MOCHI_CARD%%%
In about 60 seconds, explain smart pointers in C++. #q15 #smart-pointers #memory-pointers

---

- RAII wrappers:
  - **`unique_ptr`** — sole owner
  - **`shared_ptr`** — shared ownership + refcount
  - **`weak_ptr`** — non-owning observer
- Prefer **`make_*`** factories; **`unique_ptr`** by default.
- **`weak_ptr`** for cycles and safe observation.
