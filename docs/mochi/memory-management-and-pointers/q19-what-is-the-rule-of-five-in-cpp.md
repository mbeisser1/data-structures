What is the rule of five in C++? #q19 #rule-of-five #memory-pointers

---
For classes that **directly manage resources** (e.g. raw dynamic memory), define all **five** special members:

1. Destructor  
2. Copy constructor  
3. Copy assignment operator  
4. Move constructor  
5. Move assignment operator  

%%%MOCHI_CARD%%%
Show a full rule-of-five implementation. For a class owning a dynamic array, what five special members are required? #q19 #rule-of-five #memory-pointers

---
```cpp
class MyClass {
private:
    int* data;
    size_t size;

public:
    MyClass(size_t s) : data(new int[s]), size(s) {}

    ~MyClass() { delete[] data; }

    MyClass(const MyClass& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + size, data);
    }

    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            MyClass temp(other);
            std::swap(data, temp.data);
            std::swap(size, temp.size);
        }
        return *this;
    }

    MyClass(MyClass&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
};
```

%%%MOCHI_CARD%%%
What is the rule of zero? #q19 #rule-of-five #memory-pointers

---

- Let **RAII members** (`unique_ptr`, `vector`, etc.) define destruction and copying/moving.
- Use **`= default` / `= delete`** when you want explicit compiler behavior.
- Prefer **rule of zero** over hand-written five when members already manage resources.

%%%MOCHI_CARD%%%
Show the rule of zero with smart pointers. How can a `unique_ptr` member eliminate hand-written special members? #q19 #rule-of-five #memory-pointers

---
```cpp
#include <memory>

class ModernClass {
private:
    std::unique_ptr<int[]> data;
    size_t size;

public:
    ModernClass(size_t s) : data(std::make_unique<int[]>(s)), size(s) {}

    // Rule of Zero: no explicit special member functions needed
};
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain the rule of five. #q19 #rule-of-five #memory-pointers

---

- Resource-owning class needs all **five** special members:
  - **Destructor**
  - **Copy constructor**
  - **Copy assignment**
  - **Move constructor**
  - **Move assignment**
- Copies **duplicate** (often copy-and-swap); moves **steal** resources.
- Prefer **rule of zero** with **`unique_ptr`/`vector`** when you can.
