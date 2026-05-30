What is inheritance in C++? Explain its types. #q21 #inheritance #oop-concepts

---
**Inheritance** in C++ is a fundamental OOP concept: a **derived class** is created from an existing **base class**. This facilitates **code reusability** and an **“is-a”** relationship (e.g. `Dog` is an `Animal`).

%%%MOCHI_CARD%%%
What are the types of inheritance in C++? #q21 #inheritance #oop-concepts

---

- **Single** — derived class inherits from one base class
- **Multiple** — derived class inherits from two or more base classes
- **Multilevel** — derived class becomes a base class for another derived class
- **Hierarchical** — multiple derived classes inherit from one base class
- **Virtual** — prevents multiple instances of a base class in diamond inheritance

%%%MOCHI_CARD%%%
Show examples of single and virtual inheritance. How do you declare simple public inheritance vs a diamond hierarchy with `virtual` bases? #q21 #inheritance #oop-concepts

---
```cpp
// Single inheritance
class Base { /* ... */ };
class Derived : public Base { /* ... */ };

// Virtual inheritance (diamond problem mitigation)
class Base { /* ... */ };
class Derived1 : virtual public Base { /* ... */ };
class Derived2 : virtual public Base { /* ... */ };
class FinalDerived : public Derived1, public Derived2 { /* ... */ };
```

%%%MOCHI_CARD%%%
What are inheritance access specifiers (`public`, `protected`, `private`)? #q21 #inheritance #oop-concepts

---

- **`public`** — public and protected base members become public and protected in the derived class
- **`protected`** — public and protected base members become protected in the derived class
- **`private`** — public and protected base members become private in the derived class

%%%MOCHI_CARD%%%
Show inheritance access specifier effects. Given `Base` with `public`, `protected`, and `private` members, what is visible in a `public`-derived class? #q21 #inheritance #oop-concepts

---
```cpp
class Base {
public:
    int x;
protected:
    int y;
private:
    int z;
};

class PublicDerived : public Base {
    // x public, y protected, z inaccessible
};
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain inheritance in C++. #q21 #inheritance #oop-concepts

---

- **Inheritance** = reuse + **is-a** via base/derived classes
- Types:
  - **Single**
  - **Multiple**
  - **Multilevel**
  - **Hierarchical**
  - **Virtual**
- Access specifiers control how inherited members appear in the derived class
- Pick inheritance type + access level to match encapsulation and design intent
