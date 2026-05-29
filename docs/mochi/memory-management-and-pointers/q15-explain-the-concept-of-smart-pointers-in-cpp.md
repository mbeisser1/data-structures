Explain the concept of smart pointers in C++. #q15 #smart-pointers #memory-pointers

---
**Smart pointers** (`<memory>`) are RAII wrappers that **automatically manage** dynamic memory—reducing:

- **Memory leaks**
- **Dangling pointers**
- **Double delete**

They also establish clear **ownership**.

%%%MOCHI_CARD%%%
What is `std::unique_ptr`? #q15 #smart-pointers #memory-pointers

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

- **Exclusive ownership** — only one owner; **not copyable**, **movable**.

%%%MOCHI_CARD%%%
What is `std::shared_ptr`? #q15 #smart-pointers #memory-pointers

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

- **Shared ownership** with **reference counting**; watch **circular references**.

%%%MOCHI_CARD%%%
What is `std::weak_ptr`? #q15 #smart-pointers #memory-pointers

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

- **Non-owning** observer; use **`lock()`** to access; breaks **cycles**.

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
