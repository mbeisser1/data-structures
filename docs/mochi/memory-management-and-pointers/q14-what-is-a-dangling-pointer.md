What is a dangling pointer? #q14 #dangling-pointer #memory-pointers

---
A **dangling pointer** points to memory that is **no longer valid**—already **`delete`d/`free`d** or a **stack object that went out of scope**. Dereferencing it is **undefined behavior**.

%%%MOCHI_CARD%%%
Show examples of dangling pointers. #q14 #dangling-pointer #memory-pointers

---
```cpp
#include <iostream>
#include <memory>

void danglingPointerExample() {
    int* rawPtr = new int(5);
    delete rawPtr;
    // rawPtr is now dangling
    // *rawPtr; // Undefined behavior

    std::unique_ptr<int> smartPtr = std::make_unique<int>(5);
}

int* returnDanglingPointer() {
    int localVar = 10;
    return &localVar;  // Dangling: localVar goes out of scope
}

int main() {
    danglingPointerExample();
    int* danglingPtr = returnDanglingPointer();
    // *danglingPtr; // Undefined behavior
    return 0;
}
```

%%%MOCHI_CARD%%%
What causes dangling pointers? #q14 #dangling-pointer #memory-pointers

---

- **Premature deallocation** — memory freed while raw pointers still reference it.
- **Returning address of locals** — pointer/reference to a stack variable after the function returns.
- **Use-after-free** — accessing through a pointer after deallocation.

%%%MOCHI_CARD%%%
How do you avoid dangling pointers? #q14 #dangling-pointer #memory-pointers

---

- Prefer **smart pointers:**
  - **`unique_ptr`**
  - **`shared_ptr`**
  - **`weak_ptr`**
- Set raw pointers to **`nullptr`** after `delete` if you must use them.
- Use **RAII** and careful **lifetime/scope** design.
- C++17+: **`std::optional`** instead of nullable pointers when appropriate.

%%%MOCHI_CARD%%%
In about 60 seconds, explain dangling pointers. #q14 #dangling-pointer #memory-pointers

---

- Common causes:
  - **Use-after-free**
  - **Return address of local** (`&local`)
  - Early **`delete`**
- Fix with:
  - **Smart pointers**
  - **RAII**
  - **`nullptr`** after delete
  - **Static analysis tools**
