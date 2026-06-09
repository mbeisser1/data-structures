What is dynamic memory allocation in C++? #q11 #dynamic-memory #memory-pointers

---
**Dynamic memory allocation** in C++ allows memory management **during program execution**. Unlike automatic and static storage, it lets you **explicitly control** an object’s **lifetime**, **size**, and **location** in memory.

%%%MOCHI_CARD%%%
Where does dynamic memory come from, and how is it managed in C++? #q11 #dynamic-memory #memory-pointers

---

- **Heap** — large pool available **throughout program runtime**; grows/shrinks as needed (vs the more limited stack).
- **`new` / `delete`** — allocate/release single objects
- **`new[]` / `delete[]`** — arrays
- Destructors run on **`delete`**
- **Smart pointers (C++11)** for safer automatic cleanup:
  - **`unique_ptr`**
  - **`shared_ptr`**
  - **`weak_ptr`**

%%%MOCHI_CARD%%%
Show an example of `new` and `delete`. How do you allocate a single object and an array on the heap, and pair the correct delete forms? #q11 #dynamic-memory #memory-pointers

---
```cpp
#include <iostream>

class DynamicMemoryExample {
public:
    DynamicMemoryExample() { std::cout << "Constructor called!\n"; }
    ~DynamicMemoryExample() { std::cout << "Destructor called!\n"; }
};

int main() {
    int* intPtr = new int(42);
    std::cout << *intPtr << std::endl;
    delete intPtr;

    DynamicMemoryExample* array = new DynamicMemoryExample[3];
    delete[] array;

    return 0;
}
```

%%%MOCHI_CARD%%%
Show dynamic memory managed by smart pointers. How can `make_unique` and `make_shared` own heap objects without manual `delete`? #q11 #dynamic-memory #memory-pointers

---
```cpp
#include <iostream>
#include <memory>

class DynamicMemoryExample {
public:
    DynamicMemoryExample() { std::cout << "Constructor called!\n"; }
    ~DynamicMemoryExample() { std::cout << "Destructor called!\n"; }
};

int main() {
    auto uptr = std::make_unique<int>(42);
    std::cout << *uptr << std::endl;

    auto sptr = std::make_shared<DynamicMemoryExample>();
    auto array = std::make_unique<DynamicMemoryExample[]>(3);

    return 0;  // Smart pointers release memory automatically
}
```

%%%MOCHI_CARD%%%
What are best practices for `new`, `delete`, and smart pointers? #q11 #dynamic-memory #memory-pointers

---

- Always pair **`new` with `delete`** and **`new[]` with `delete[]`**.
- Prefer **smart pointers** over raw owning pointers.
- Use **`std::make_unique`** / **`std::make_shared`** for exception safety and efficiency.
- Prefer **`std::vector`** (or other containers) over manual dynamic arrays when possible.

%%%MOCHI_CARD%%%
In about 60 seconds, explain dynamic memory allocation in C++. #q11 #dynamic-memory #memory-pointers

---

- Allocate on the **heap** when lifetime/size isn’t stack-bound.
- **`new`/`delete`** call constructors/destructors; match `[]` forms for arrays.
- Modern C++:
  - **Smart pointers**
  - **Containers**
  - Avoid leaks and manual **`new`/`delete`** pairing
