What is the rule of three in C++? #q18 #rule-of-three #memory-pointers

---
If a class defines **any one** of these because it manages resources, define **all three**:

1. **Destructor**
2. **Copy constructor**
3. **Copy assignment operator**

Otherwise copies and destruction can cause:

- **Memory leaks**
- **Double-delete**
- **Dangling** state

%%%MOCHI_CARD%%%
Show a rule-of-three implementation. For a class that owns heap memory, what three special members must you define? #q18 #rule-of-three #memory-pointers

---
```cpp
class Resource {
private:
    int* data;

public:
    Resource(int value) : data(new int(value)) {}

    ~Resource() { delete data; }

    Resource(const Resource& other) : data(new int(*other.data)) {}

    Resource& operator=(const Resource& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
};
```

%%%MOCHI_CARD%%%
What does the rule of five add (C++11)? #q18 #rule-of-three #memory-pointers

---

- **Move constructor** and **move assignment** transfer ownership instead of copying.
- Moves should be **`noexcept`** when possible; null out the source’s pointer after steal.
- Prefer **rule of zero** with **`unique_ptr`** / containers when you can avoid raw ownership.

%%%MOCHI_CARD%%%
Show move operations for a resource-owning class. How should move ctor and move assignment transfer a raw pointer member? #q18 #rule-of-three #memory-pointers

---
```cpp
ModernResource(ModernResource&& other) noexcept : data(other.data) {
    other.data = nullptr;
}

ModernResource& operator=(ModernResource&& other) noexcept {
    if (this != &other) {
        delete data;
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}
```

%%%MOCHI_CARD%%%
Show the rule of zero with a smart pointer member. When can you omit all special member functions? #q18 #rule-of-three #memory-pointers

---
```cpp
#include <memory>

class SmartResource {
    std::unique_ptr<int> data;
public:
    SmartResource(int value) : data(std::make_unique<int>(value)) {}
};
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain the rule of three. #q18 #rule-of-three #memory-pointers

---

- Custom special members — if you define one, you probably need all three:
  - **Destructor**
  - **Copy constructor**
  - **Copy assignment**
- C++11: extend to **rule of five** with move operations.
- Prefer **rule of zero** with **`unique_ptr`** / containers when possible.
