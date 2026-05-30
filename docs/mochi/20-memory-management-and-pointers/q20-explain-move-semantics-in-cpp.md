Explain move semantics in C++. #q20 #move-semantics #memory-pointers

---
**Move semantics** (C++11) enables efficient handling of data by **transferring rvalue resources** — temporaries, literals, or explicitly moved objects — instead of copying. This reduces unnecessary copying and improves performance.

%%%MOCHI_CARD%%%
What are lvalues and rvalues in the move semantics context? #q20 #move-semantics #memory-pointers

---

- **Lvalue** — an object with **identity** and **persisting state** (e.g. a named variable).
- **Rvalue** — a **temporary** without a named identity (e.g. return value, literal).
- Without move semantics, `auto vec = createIntVector();` may **deep-copy** the entire vector unnecessarily.

%%%MOCHI_CARD%%%
Show a move constructor example. For a class owning a buffer, how do you transfer ownership from an rvalue? #q20 #move-semantics #memory-pointers

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
Show a move assignment operator. How do you release current resources and steal from the source object? #q20 #move-semantics #memory-pointers

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

%%%MOCHI_CARD%%%
What are move operation signatures and when to use `std::move`? #q20 #move-semantics #memory-pointers

---

- Use **`std::move`** from `<utility>` to treat a named lvalue as movable when you’re done with it.
- Mark moves **`noexcept`** when possible so containers can optimize.

%%%MOCHI_CARD%%%
Show move operation signatures. What do the move constructor and move assignment declarations look like? #q20 #move-semantics #memory-pointers

---
```cpp
ClassName(ClassName&& other) noexcept;
ClassName& operator=(ClassName&& other) noexcept;
```
%%%MOCHI_CARD%%%
In about 60 seconds, explain move semantics. #q20 #move-semantics #memory-pointers

---

- **Moves transfer ownership** of resources from rvalues; avoid redundant copies.
- Implement **move ctor/assign** for resource-owning types; mark **`noexcept`** when possible.
- Call **`std::move`** when transferring from a named object you won’t use again.
