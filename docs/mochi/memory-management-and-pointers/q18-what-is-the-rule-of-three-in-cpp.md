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
Show a rule-of-three implementation. #q18 #rule-of-three #memory-pointers

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
Show rule-of-five and smart-pointer alternatives. #q18 #rule-of-three #memory-pointers

---
**Rule of five** adds **move constructor** and **move assignment**:

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

**Smart pointer member** (often **rule of zero** for moves):

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
