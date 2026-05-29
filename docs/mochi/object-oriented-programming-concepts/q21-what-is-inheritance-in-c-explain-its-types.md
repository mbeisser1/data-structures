What is inheritance in C++? Explain its types. #q21 #inheritance #oop-concepts

---
**Inheritance** lets a **derived class** be built from an existing **base class** — code reuse plus an **“is-a”** relationship (e.g. `Dog` is an `Animal`).

%%%MOCHI_CARD%%%
What are the types of inheritance in C++? #q21 #inheritance #oop-concepts

---

- **Single** — one base class
- **Multiple** — two or more base classes
- **Multilevel** — derived class becomes base for another derived class
- **Hierarchical** — several derived classes share one base
- **Virtual** — prevents duplicate base subobjects in diamond hierarchies

%%%MOCHI_CARD%%%
Show examples of single and virtual inheritance. #q21 #inheritance #oop-concepts

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

- **`public` inheritance** — base **`public`** → derived **`public`**; base **`protected`** → derived **`protected`**
- **`protected` inheritance** — base **`public`** and **`protected`** → derived **`protected`**
- **`private` inheritance** — base **`public`** and **`protected`** → derived **`private`**

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
