Explain the concept of type erasure in C++. #q82 #type-erasure #advanced-cpp

---
**Type erasure** stores **different concrete types** behind one **uniform interface** — the caller doesn’t know the stored type.

**Mechanism:**

- Common interface (often **virtual** base)
- Concrete types hidden behind **`unique_ptr<Interface>`** or similar
- Examples: **`std::function`**, **`std::any`**

%%%MOCHI_CARD%%%
Show a simple type-erased wrapper. #q82 #type-erasure #advanced-cpp

---
```cpp
class Dog {
public:
    virtual ~Dog() = default;
    virtual void bark() const = 0;
    virtual std::unique_ptr<Dog> clone() const = 0;
};

class GoldenRetriever : public Dog {
public:
    void bark() const override {
        std::cout << "Woof! I'm a friendly Golden Retriever!" << std::endl;
    }
    std::unique_ptr<Dog> clone() const override {
        return std::make_unique<GoldenRetriever>(*this);
    }
};

class AnyDog {
    std::unique_ptr<Dog> pDog;
public:
    template<typename T>
    AnyDog(T dog) : pDog(std::make_unique<T>(std::move(dog))) {}
    AnyDog(const AnyDog& other) : pDog(other.pDog->clone()) {}
    void bark() const { pDog->bark(); }
};
```

**`AnyDog`** exposes one API; breed type is erased.

%%%MOCHI_CARD%%%
What are benefits of type erasure? #q82 #type-erasure #advanced-cpp

---

- **Unified interface** for heterogeneous types
- **Encapsulation** — hide inheritance hierarchy
- **Runtime polymorphism** without templating every call site
- Enables **`std::function<void()>`** holding any callable

Cost: heap allocation + virtual dispatch (typical).

%%%MOCHI_CARD%%%
Show built-in type erasure with `std::any`. #q82 #type-erasure #advanced-cpp

---
```cpp
#include <any>
#include <iostream>

int main() {
    std::any a = 1;
    std::cout << std::any_cast<int>(a) << std::endl;

    a = 3.14;
    std::cout << std::any_cast<double>(a) << std::endl;

    a = std::string("Hello, type erasure!");
    std::cout << std::any_cast<std::string>(a) << std::endl;

    return 0;
}
```

**`any_cast`** recovers type; wrong type throws **`bad_any_cast`**.

%%%MOCHI_CARD%%%
In about 60 seconds, explain type erasure. #q82 #type-erasure #advanced-cpp

---

- One **public type**, many **hidden concrete types**
- Usually **virtual interface + pimpl/unique_ptr**
- **`std::function`**, **`std::any`** are standard examples
- Trade runtime cost for flexible homogeneous containers/APIs
