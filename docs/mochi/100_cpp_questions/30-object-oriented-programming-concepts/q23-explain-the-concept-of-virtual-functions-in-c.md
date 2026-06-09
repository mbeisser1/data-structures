Explain the concept of virtual functions in C++. #q23 #virtual-functions #oop-concepts

---
**Virtual functions** enable **polymorphic behavior** through **dynamic dispatch** (late binding): the **correct function** runs based on the **actual object type**, not the pointer or reference type used to call it.

%%%MOCHI_CARD%%%
How do virtual functions work (vtable and dynamic dispatch)? #q23 #virtual-functions #oop-concepts

---

- Classes with virtual functions have a hidden **vptr** pointing to a **vtable** of function addresses
- Calling a virtual function uses the vtable → **dynamic binding** at run time

%%%MOCHI_CARD%%%
Show a virtual function example. How do `Animal*` calls dispatch to `Dog` and `Cat` overrides of `makeSound()`? #q23 #virtual-functions #oop-concepts

---
```cpp
#include <iostream>

class Animal {
public:
    virtual void makeSound() {
        std::cout << "The animal makes a sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "The dog barks" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "The cat meows" << std::endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound();  // The dog barks
    animal2->makeSound();  // The cat meows

    delete animal1;
    delete animal2;
    return 0;
}
```

%%%MOCHI_CARD%%%
What are the benefits and costs of virtual functions? #q23 #virtual-functions #oop-concepts

---

**Benefits:**

- **Polymorphism** — treat derived objects through a base interface
- **Abstraction** — define interfaces without full implementation in the base
- **Flexibility** — extend behavior without modifying the base class

**Costs:**

- **Slight overhead** — extra indirection on virtual calls
- **Memory** — objects carry an additional vptr
- Compilers often optimize; still weigh cost in hot paths

%%%MOCHI_CARD%%%
What modern C++ features relate to virtual functions? #q23 #virtual-functions #oop-concepts

---

- **`override`** (C++11) — marks an intended override; catches signature mistakes
- **`final`** (C++11) — block further override or inheritance
- Base **destructor should be `virtual`** when deleting polymorphically

%%%MOCHI_CARD%%%
In about 60 seconds, explain virtual functions. #q23 #virtual-functions #oop-concepts

---

- **`virtual`** → **dynamic dispatch** through **vtable/vptr**
- Enables **run-time polymorphism** and **abstract interfaces**
- Use **`override`**, **`final`**, and a **`virtual` destructor** in bases
- Trade a little speed/size for flexible OOP design
