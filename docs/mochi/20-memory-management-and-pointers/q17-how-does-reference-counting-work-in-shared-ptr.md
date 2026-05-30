How does reference counting work in `shared_ptr`? #q17 #shared-ptr #memory-pointers

---
**Reference counting** in **`std::shared_ptr`** tracks how many smart pointers reference an object. When the count reaches **zero**, the object is **automatically deallocated**.

%%%MOCHI_CARD%%%
What is the `shared_ptr` control block? #q17 #shared-ptr #memory-pointers

---

- Separate **control block** holds:
  - **Strong count**
  - **Weak count**
  - Pointer to managed object
  - Optional custom **deleter**
- Copying a `shared_ptr` **increments** the count; destroying one **decrements** it.
- Count updates use **atomic** operations for thread-safe bookkeeping (not the pointed-to object itself).

%%%MOCHI_CARD%%%
Show `shared_ptr` reference counting with `use_count()`. How does the count change as copies are created, destroyed, and reset? #q17 #shared-ptr #memory-pointers

---
```cpp
#include <memory>
#include <iostream>

int main() {
    auto sp1 = std::make_shared<int>(42);
    std::cout << "Reference count: " << sp1.use_count() << std::endl;  // 1

    {
        auto sp2 = sp1;
        std::cout << "Reference count: " << sp1.use_count() << std::endl;  // 2
    }  // sp2 destroyed, count decrements

    std::cout << "Reference count: " << sp1.use_count() << std::endl;  // 1

    sp1.reset();  // count becomes 0, object deallocated

    return 0;
}
```

%%%MOCHI_CARD%%%
What are performance and thread-safety notes for `shared_ptr`? #q17 #shared-ptr #memory-pointers

---

- Prefer **`std::make_shared`** — often one allocation for object + control block.
- **Copy** = increment count; **move** = cheap transfer without changing count.
- **Refcount ops** are thread-safe; **data access** still needs your own synchronization.

%%%MOCHI_CARD%%%
In about 60 seconds, explain `shared_ptr` reference counting. #q17 #shared-ptr #memory-pointers

---

- **Control block** tracks owners; last **`shared_ptr` out** → delete.
- **`use_count()`** shows current strong refs (debugging, not logic).
- Use **`make_shared`**; remember: **thread-safe count ≠ thread-safe object**.
