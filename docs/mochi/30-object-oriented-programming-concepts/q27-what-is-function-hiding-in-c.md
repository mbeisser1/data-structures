What is function hiding in C++? #q27 #function-hiding #oop-concepts

---
**Function hiding** happens when a derived class declares a function **with the same name** as a base function but a **different signature** — the base overloads are **hidden**, not overridden.

%%%MOCHI_CARD%%%
Show an example of function hiding. Why does `display("Hello")` work on `Derived` but a no-arg `display()` call does not? #q27 #function-hiding #oop-concepts

---
```cpp
class Base {
public:
    void display() {
        std::cout << "Base display" << std::endl;
    }
};

class Derived : public Base {
public:
    void display(std::string message) {
        std::cout << "Derived display: " << message << std::endl;
    }
};

int main() {
    Derived d;
    d.display("Hello");  // OK
    // d.display();       // Error: Base::display() is hidden
}
```

%%%MOCHI_CARD%%%
How is function hiding different from overriding? #q27 #function-hiding #oop-concepts

---

- **Hiding** — same name, **different parameters**; base overloads disappear from derived scope
- **Overriding** — same name **and signature** (with `virtual`); dynamic dispatch replaces base implementation

%%%MOCHI_CARD%%%
How do you prevent unwanted function hiding? #q27 #function-hiding #oop-concepts

---

- Use **`override`** when intentionally overriding a **virtual** with the **same signature**
- Use **`using Base::fn;`** to bring base overloads into the derived class scope when adding new overloads

%%%MOCHI_CARD%%%
Show preventing hiding with `override`. How do you replace a virtual `display()` in the base with a derived implementation? #q27 #function-hiding #oop-concepts

---
```cpp
class Base {
public:
    virtual void display() const {
        std::cout << "Base display" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() const override {
        std::cout << "Derived display" << std::endl;
    }
};
```

%%%MOCHI_CARD%%%
Show preventing hiding with `using`. How can `Derived` add `print(double)` while still calling `Base::print(int)`? #q27 #function-hiding #oop-concepts

---
```cpp
class Base {
public:
    void print(int x) {
        std::cout << "Printing int: " << x << std::endl;
    }
};

class Derived : public Base {
public:
    using Base::print;
    void print(double x) {
        std::cout << "Printing double: " << x << std::endl;
    }
};

int main() {
    Derived d;
    d.print(5);     // Calls Base::print(int)
    d.print(3.14);  // Calls Derived::print(double)
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain function hiding. #q27 #function-hiding #oop-concepts

---

- Derived function **same name, different signature** → **hides** base overloads
- Not the same as **`virtual` override**
- Fix: **`override`** for true overrides; **`using Base::fn`** to expose base overloads
