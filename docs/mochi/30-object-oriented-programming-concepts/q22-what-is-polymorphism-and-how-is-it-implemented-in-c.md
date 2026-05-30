What is polymorphism and how is it implemented in C++? #q22 #polymorphism #oop-concepts

---
**Polymorphism** in C++ allows objects of **different types** to be treated as if they are the **same type**, facilitating **code reusability** and **separation of concerns**.

%%%MOCHI_CARD%%%
What are the two main types of polymorphism in C++? #q22 #polymorphism #oop-concepts

---

- **Compile-time polymorphism** — **function overloading** and **operator overloading**
- **Run-time polymorphism** — **virtual functions** and **inheritance**; the call is resolved at run time based on the actual object type

%%%MOCHI_CARD%%%
Show run-time polymorphism with virtual functions. How can `Dog` and `Cat` be called through `Animal` pointers so each prints its own `speak()` message? #q22 #polymorphism #oop-concepts

---
```cpp
#include <iostream>
#include <memory>

class Animal {
public:
    virtual void speak() const {
        std::cout << "The animal speaks!\n";
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "The dog barks!\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "The cat meows!\n";
    }
};

int main() {
    std::unique_ptr<Animal> myDog = std::make_unique<Dog>();
    std::unique_ptr<Animal> myCat = std::make_unique<Cat>();

    myDog->speak();  // The dog barks!
    myCat->speak();  // The cat meows!
    return 0;
}
```

%%%MOCHI_CARD%%%
How do vtables and vptrs enable run-time polymorphism? #q22 #polymorphism #oop-concepts

---

- Each class with virtual functions has a **vtable** (array of function pointers)
- Each object has a hidden **vptr** (virtual pointer) to that class’s vtable
- A virtual call **dereferences** the matching entry in the object’s vtable at run time
- Small overhead from the lookup; modern compilers and CPUs usually keep the cost negligible

%%%MOCHI_CARD%%%
What are best practices for virtual functions and polymorphism? #q22 #polymorphism #oop-concepts

---

- Declare base **destructors `virtual`** so derived objects clean up correctly
- Use **`override`** on derived overrides; **`final`** when further override is forbidden
- Use virtual functions when a **base class defines an interface** for derived classes
- Alternatives for some designs: **`std::variant` / `std::visit`** (C++17), **concepts** (C++20)

%%%MOCHI_CARD%%%
In about 60 seconds, explain polymorphism in C++. #q22 #polymorphism #oop-concepts

---

- Treat different types **through a common interface**
- **Compile-time:** overloading; **run-time:** **`virtual`** + inheritance
- **vtable/vptr** resolve the call to the **derived override**
- **`virtual ~Base`**, **`override`**, **`final`**
