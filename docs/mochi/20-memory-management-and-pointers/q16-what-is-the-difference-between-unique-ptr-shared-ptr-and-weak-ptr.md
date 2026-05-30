What is the difference between `unique_ptr`, `shared_ptr`, and `weak_ptr`? #q16 #smart-pointers #memory-pointers

---
Smart pointers are crucial for **memory management** and preventing **dangling pointers** and **memory leaks**. **`unique_ptr`**, **`shared_ptr`**, and **`weak_ptr`** each serve different ownership roles.

%%%MOCHI_CARD%%%
Compare `unique_ptr`, `shared_ptr`, and `weak_ptr`. #q16 #smart-pointers #memory-pointers

---

| Pointer | Ownership | Notes |
| --- | --- | --- |
| **`unique_ptr`** | **Exclusive** | One owner; movable; deleted when `unique_ptr` goes out of scope |
| **`shared_ptr`** | **Shared** | **Reference counting**; last owner deletes; thread-safe refcount |
| **`weak_ptr`** | **Non-owning** | Observes `shared_ptr`; **`lock()`** for temporary access; breaks cycles |

%%%MOCHI_CARD%%%
Show basic usage of `unique_ptr`, `shared_ptr`, and `weak_ptr`. Give one short example of each ownership model. #q16 #smart-pointers #memory-pointers

---
```cpp
#include <memory>

std::unique_ptr<int> ptr = std::make_unique<int>(42);

std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
std::shared_ptr<int> ptr2 = ptr1;

std::shared_ptr<int> shared = std::make_shared<int>(42);
std::weak_ptr<int> weak = shared;

if (auto locked = weak.lock()) {
    // Use the locked shared_ptr
} else {
    // Object has been deleted
}
```

%%%MOCHI_CARD%%%
How does `weak_ptr` break circular references? #q16 #smart-pointers #memory-pointers

---

- **`shared_ptr`** members in a cycle keep refcounts ≥ 1 forever.
- Store the **back-reference** as **`weak_ptr`** so one direction does not own.
- When the scope ends, both **`A`** and **`B`** can destruct normally.

%%%MOCHI_CARD%%%
Show breaking a cycle with `weak_ptr`. How can mutual `shared_ptr` links prevent destruction, and how does `weak_ptr` fix it? #q16 #smart-pointers #memory-pointers

---
```cpp
#include <memory>
#include <iostream>

class B;

class A {
public:
    std::shared_ptr<B> b_ptr;
    A() { std::cout << "A constructed\n"; }
    ~A() { std::cout << "A destructed\n"; }
};

class B {
public:
    std::weak_ptr<A> a_ptr;  // weak_ptr breaks the cycle
    B() { std::cout << "B constructed\n"; }
    ~B() { std::cout << "B destructed\n"; }
};

int main() {
    {
        auto a = std::make_shared<A>();
        auto b = std::make_shared<B>();
        a->b_ptr = b;
        b->a_ptr = a;
    }  // Both a and b are properly destructed
    return 0;
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, compare the three smart pointer types. #q16 #smart-pointers #memory-pointers

---

- **`unique_ptr`**: one owner, move-only, fastest default.
- **`shared_ptr`**: many owners, refcounted cleanup, overhead + cycle risk.
- **`weak_ptr`**: non-owning watch; **`lock()`** to access; use to **break cycles**.
