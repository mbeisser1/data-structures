Explain the concept of type erasure in C++. #q82 #type-erasure #advanced-cpp

---
**Type erasure** lets you store objects of **different types** in a single container while exposing a **consistent interface** — fundamental to polymorphism and types like **`std::function`** and **`std::any`**.

**Mechanism:**

- Common interface (often **virtual** base)
- Concrete types hidden behind **`unique_ptr<Interface>`** or similar
- Examples: **`std::function`**, **`std::any`**

%%%MOCHI_CARD%%%
Show a type-erased wrapper for polymorphic objects. How can one public type hold different concrete implementations behind a shared interface? #q82 #type-erasure #advanced-cpp

---
```cpp
#include <iostream>
#include <memory>

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

int main() {
    AnyDog dog1(GoldenRetriever{});
    dog1.bark();
    AnyDog dog2 = dog1;
    dog2.bark();
    return 0;
}
```

%%%MOCHI_CARD%%%
What are benefits of type erasure? #q82 #type-erasure #advanced-cpp

---

- **Flexibility** — work with different types through one interface
- **Encapsulation** — hide concrete type details
- **Runtime polymorphism** — dynamic dispatch without exposing hierarchy
- **Runtime polymorphism** without templating every call site
- Enables **`std::function<void()>`** holding any callable

Cost: heap allocation + virtual dispatch (typical).

%%%MOCHI_CARD%%%
Show built-in type erasure with `std::any`. How do you store and recover values of different types in one variable? #q82 #type-erasure #advanced-cpp

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
