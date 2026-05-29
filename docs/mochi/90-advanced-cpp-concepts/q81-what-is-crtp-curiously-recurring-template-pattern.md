What is CRTP (Curiously Recurring Template Pattern)? #q81 #crtp #advanced-cpp

---
**CRTP** is a pattern where a class inherits from a **template base instantiated with the derived type itself**:

```cpp
template <typename Derived>
class Base { /* ... */ };

class Derived : public Base<Derived> { /* ... */ };
```

Enables **static (compile-time) polymorphism** without virtual functions.

%%%MOCHI_CARD%%%
How does CRTP work? #q81 #crtp #advanced-cpp

---
The base casts **`this`** to **`Derived*`** and calls derived methods — **compile-time binding** (no vtable). The derived type is known when you call through a concrete **`Derived`**.

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

- **No virtual call overhead**
- **Compile-time errors** for missing derived methods (when instantiated)
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
