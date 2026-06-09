What are the improvements in smart pointers introduced in C++11? #q79 #smart-pointers-cpp11 #cpp11-beyond

---
C++11 introduced significant **smart pointer** improvements — enhancing memory safety and ownership semantics. It replaced deprecated **`auto_ptr`** with:

- **`std::unique_ptr`** — **exclusive** ownership, zero ref-count overhead
- **`std::shared_ptr`** — **shared** ownership via **reference counting**
- **`std::weak_ptr`** — non-owning observer; breaks **`shared_ptr`** cycles

**`make_shared`/`make_unique`** — safer, often fewer allocations.

%%%MOCHI_CARD%%%
Compare `unique_ptr`, `shared_ptr`, and `weak_ptr`. #q79 #smart-pointers-cpp11 #cpp11-beyond

---

**`unique_ptr`**

- One owner; movable, not copyable
- Lightweight; use by default

**`shared_ptr`**

- Multiple owners; control block + strong count
- Last one destroys the object

**`weak_ptr`**

- Does not keep object alive
- **`lock()`** → temporary **`shared_ptr`** if still alive

%%%MOCHI_CARD%%%
Show using all three smart pointer types. How do exclusive, shared, and weak ownership differ in practice? #q79 #smart-pointers-cpp11 #cpp11-beyond

---
```cpp
#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource released\n"; }
    void use() { std::cout << "Resource used\n"; }
};

int main() {
    {
        auto uniqueResource = std::make_unique<Resource>();
        uniqueResource->use();
    } // released

    {
        auto sharedResource1 = std::make_shared<Resource>();
        {
            auto sharedResource2 = sharedResource1;
            sharedResource2->use();
        }
    } // released when last shared_ptr dies

    auto sharedResource = std::make_shared<Resource>();
    std::weak_ptr<Resource> weakResource = sharedResource;

    if (auto temp = weakResource.lock()) {
        temp->use();
    }

    return 0;
}
```

%%%MOCHI_CARD%%%
Why prefer `make_shared` and `make_unique`? #q79 #smart-pointers-cpp11 #cpp11-beyond

---

- **Exception safety** — object and control block allocated together (`make_shared`)
- **Single allocation** for object + control block (`make_shared`)
- Clearer syntax — no **`new`** in user code
- **`make_unique`** (C++14) same idea for exclusive ownership

Avoid **`shared_ptr` on `this`** without **`enable_shared_from_this`**.

%%%MOCHI_CARD%%%
In about 60 seconds, explain C++11 smart pointers. #q79 #smart-pointers-cpp11 #cpp11-beyond

---

- **`unique_ptr`** default; **`shared_ptr`** when shared lifetime needed
- **`weak_ptr`** breaks cycles and observes safely
- **`make_*`** factories over raw **`new`**
- RAII automatic cleanup — no manual **`delete`**
