What is the rule of five in C++? #q19 #rule-of-five #memory-pointers

---
For classes that **directly manage resources** (e.g. raw dynamic memory), define all **five** special members:

1. Destructor  
2. Copy constructor  
3. Copy assignment operator  
4. Move constructor  
5. Move assignment operator  

%%%MOCHI_CARD%%%
Show a full rule-of-five implementation. #q19 #rule-of-five #memory-pointers

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
Show the rule of zero with smart pointers. #q19 #rule-of-five #memory-pointers

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

- **`= default` / `= delete`** when you want explicit compiler behavior.
- Prefer **rule of zero** when RAII members handle resources.

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
