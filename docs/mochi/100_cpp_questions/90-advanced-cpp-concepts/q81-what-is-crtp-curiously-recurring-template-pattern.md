What is CRTP (Curiously Recurring Template Pattern)? #q81 #crtp #advanced-cpp

---
The **Curiously Recurring Template Pattern (CRTP)** is an advanced design pattern that leverages **static polymorphism** — the base class accesses the derived class’s methods and properties at **compile time** (no vtable):

```cpp
template <typename Derived>
class Base { /* ... */ };

class Derived : public Base<Derived> { /* ... */ };
```

Enables **static (compile-time) polymorphism** without virtual functions.

%%%MOCHI_CARD%%%
How does CRTP work? #q81 #crtp #advanced-cpp

---
The base uses **`static_cast<Derived*>(this)`** to call derived methods — a form of **compile-time reflection**. The derived type is fixed in the template argument, so binding happens at **compile time** (no vtable).

%%%MOCHI_CARD%%%
Show CRTP in action. How does `Base<Derived>` call into `Derived` without virtual functions? #q81 #crtp #advanced-cpp

---
```cpp
#include <iostream>

template <typename Derived>
class Base {
public:
    void interface() {
        static_cast<Derived*>(this)->implementation();
    }
    static void static_interface() {
        Derived::static_implementation();
    }
protected:
    Base() = default;
};

class Derived : public Base<Derived> {
public:
    void implementation() {
        std::cout << "Derived::implementation\n";
    }
    static void static_implementation() {
        std::cout << "Derived::static_implementation\n";
    }
};

int main() {
    Derived d;
    d.interface();
    Derived::static_interface();
    return 0;
}
```

Used in **`std::enable_shared_from_this`**, expression templates, mixin bases.

%%%MOCHI_CARD%%%
What are benefits of CRTP? #q81 #crtp #advanced-cpp

---

- **Efficiency** — avoids virtual dispatch overhead
- **Compile-time safety** — errors flagged earlier
- **Static polymorphism** — without virtual functions
- **No runtime overhead** — no vtable lookups
- **Static polymorphism** — inline-friendly
- **Mixin-style** code reuse

Tradeoff: base must know derived type at compile time; not runtime substitutable like virtuals.

%%%MOCHI_CARD%%%
In about 60 seconds, explain CRTP. #q81 #crtp #advanced-cpp

---

- **`class D : public Base<D>`**
- Base calls derived via **`static_cast<Derived*>(this)`**
- **Static polymorphism** — fast, no vtable
- Common in library internals and mixin designs
