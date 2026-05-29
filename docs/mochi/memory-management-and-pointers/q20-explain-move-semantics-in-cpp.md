Explain move semantics in C++. #q20 #move-semantics #memory-pointers

---
**Move semantics** (C++11) **transfer** resources from **rvalues** instead of copying—big win for:

- **Vectors**
- **Strings**
- Other **owning** types

**Rvalues** include temporaries and expiring objects.

%%%MOCHI_CARD%%%
What are lvalues and rvalues in the move semantics context? #q20 #move-semantics #memory-pointers

---

- **Lvalue** — has a **name** and persistent storage (e.g. variable `x`).
- **Rvalue** — temporary / expiring value, e.g.:
  - **Return value**
  - **Literal**
  - Result of **`std::move(x)`**
- Without moves, `auto vec = createIntVector();` may **deep-copy** unnecessarily.

%%%MOCHI_CARD%%%
Show a move constructor example. #q20 #move-semantics #memory-pointers

---
```cpp
#include <iostream>
#include <utility>

class MyVector {
    int* data;
    size_t size;

public:
    MyVector(size_t s) : size(s), data(new int[s]) {
        std::cout << "Normal Constructor\n";
    }

    MyVector(MyVector&& other) noexcept
        : data(std::exchange(other.data, nullptr))
        , size(std::exchange(other.size, 0))
    {
        std::cout << "Move Constructor\n";
    }

    ~MyVector() {
        delete[] data;
        std::cout << "Destructor\n";
    }
};

int main() {
    MyVector v1(5);
    MyVector v2 = std::move(v1);  // Move constructor
    return 0;
}
```

%%%MOCHI_CARD%%%
Show a move assignment operator example. #q20 #move-semantics #memory-pointers

---
```cpp
MyVector& operator=(MyVector&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = std::exchange(other.data, nullptr);
        size = std::exchange(other.size, 0);
    }
    std::cout << "Move Assignment Operator\n";
    return *this;
}
```

Declarations:

```cpp
ClassName(ClassName&& other) noexcept;
ClassName& operator=(ClassName&& other) noexcept;
```

Use **`std::move`** from `<utility>` to treat an lvalue as movable when you’re done with it.

%%%MOCHI_CARD%%%
In about 60 seconds, explain move semantics. #q20 #move-semantics #memory-pointers

---

- **Moves transfer ownership** of resources from rvalues; avoid redundant copies.
- Implement **move ctor/assign** for resource-owning types; mark **`noexcept`** when possible.
- Call **`std::move`** when transferring from a named object you won’t use again.
