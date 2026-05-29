Explain the concept of allocators in STL. #q60 #allocators #stl

---
**Allocators** handle **memory allocation/deallocation** for containers — separating **storage** from **object lifetime**.

**Default:** **`std::allocator<T>`** uses **`operator new`/`delete`**.

Containers accept an allocator template parameter: **`std::vector<T, Alloc>`**.

%%%MOCHI_CARD%%%
What must an STL allocator provide? #q60 #allocators #stl

---

**Memory**

- **`allocate(n)`** — raw storage for `n` objects
- **`deallocate(p, n)`** — free storage

**Lifetime** (via **`std::allocator_traits`** in modern code)

- **`construct`**, **`destroy`** — placement new / explicit destructor

**Other**

- **`value_type`**, **`max_size()`**
- **`select_on_container_copy_construction()`**

%%%MOCHI_CARD%%%
What standard allocator types exist? #q60 #allocators #stl

---

- **`std::allocator<T>`** — default heap allocator
- **`std::pmr::polymorphic_allocator<T>`** (C++17) — runtime-selected memory resource
- Custom allocators — pools, arena, GPU memory, tracking wrappers

Use **`std::allocator_traits`** for portable allocator operations.

%%%MOCHI_CARD%%%
Show a custom allocator with `std::vector`. What must a minimal allocator provide, and how do you plug it into `vector`? #q60 #allocators #stl

---
```cpp
#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class SimpleAllocator {
public:
    using value_type = T;

    SimpleAllocator() noexcept {}
    template <class U> SimpleAllocator(const SimpleAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t n) noexcept {
        ::operator delete(p);
    }
};

int main() {
    std::vector<int, SimpleAllocator<int>> vec;
    vec.push_back(42);
    std::cout << "Vector size: " << vec.size() << std::endl;
    return 0;
}
```

%%%MOCHI_CARD%%%
Why use custom allocators? #q60 #allocators #stl

---

- **Performance** — arena/pool allocation for hot paths
- **Memory tracking** — debug/profiling wrappers
- **Specialized hardware** — device-local memory
- **Polymorphic resources (C++17)** — swap strategies at runtime without changing container type

Most code uses the **default allocator**; customize when allocation is a bottleneck.

%%%MOCHI_CARD%%%
In about 60 seconds, explain STL allocators. #q60 #allocators #stl

---

- **Pluggable memory strategy** for containers
- Default **`std::allocator`** → heap via `new`/`delete`
- Custom allocators for **pools, tracking, PMR**
- **`allocator_traits`** abstracts allocator interface; C++17 **`pmr`** adds runtime flexibility
