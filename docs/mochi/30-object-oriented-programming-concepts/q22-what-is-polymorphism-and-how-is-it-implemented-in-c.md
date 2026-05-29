What is polymorphism and how is it implemented in C++? #q22 #polymorphism #oop-concepts

---
**Polymorphism** lets you treat different types uniformly — same interface, behavior resolved by actual object type. Supports **reuse** and **separation of concerns**.

%%%MOCHI_CARD%%%
What are the two main types of polymorphism in C++? #q22 #polymorphism #oop-concepts

---

- **Compile-time** — **function overloading**, **operator overloading** (resolved at compile time)
- **Run-time** — **virtual functions** + **inheritance** (resolved while the program runs)

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
- Each object carries a hidden **vptr** pointing at its class’s vtable
- A virtual call **looks up** the function in the object’s vtable at run time
- Small overhead; usually negligible on modern hardware

%%%MOCHI_CARD%%%
What are best practices for virtual functions and polymorphism? #q22 #polymorphism #oop-concepts

---

- Make base **destructors `virtual`** when deleting through base pointers
- Use **`override`** on derived overrides; **`final`** when further override is forbidden
- Use virtuals to define **interfaces** in base classes
- Modern alternatives for some cases:
  - **`std::variant` / `std::visit`** (C++17)
  - **Concepts** (C++20)

%%%MOCHI_CARD%%%
In about 60 seconds, explain polymorphism in C++. #q22 #polymorphism #oop-concepts

---

- **Compile-time:** overloading
- **Run-time:** **`virtual`** + inheritance → **vtable/vptr**
- Base pointer/reference can call the **derived override**
- **`virtual ~Base`**, **`override`**, **`final`**
- Alternatives: **variant/visit**, **concepts**
