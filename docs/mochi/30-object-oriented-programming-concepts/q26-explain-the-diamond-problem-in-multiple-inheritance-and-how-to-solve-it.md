Explain the diamond problem in multiple inheritance and how to solve it. #q26 #diamond-problem #oop-concepts

---
The **diamond problem** is a classic issue in **multiple inheritance**: a derived class inherits from **two base classes** that share a **common ancestor**, creating **ambiguity** and **duplicate copies** of the ancestor’s data.

```text
      Base
     /    \
  BaseA  BaseB
     \    /
    Derived
```

%%%MOCHI_CARD%%%
What issues does the diamond problem cause? #q26 #diamond-problem #oop-concepts

---

- **Ambiguity** — uncertainty about which inherited member (method or attribute) to use
- **Data duplication** — multiple copies of the common ancestor’s attributes in the derived class

%%%MOCHI_CARD%%%
Show the diamond problem causing an ambiguous call. Why does calling `display()` on `Derived` fail when both parents share `Base`? #q26 #diamond-problem #oop-concepts

---
```cpp
#include <iostream>

class Base {
public:
    void display() { std::cout << "Display from Base" << std::endl; }
};

class BaseA : public Base {};
class BaseB : public Base {};

class Derived : public BaseA, public BaseB {};

int main() {
    Derived d;
    // d.display();  // Error: ambiguous call
    return 0;
}
```

%%%MOCHI_CARD%%%
How do you solve the diamond problem in C++? #q26 #diamond-problem #oop-concepts

---

- **Virtual inheritance** — `class BaseA : virtual public Base` ensures **only one** instance of the common base
- **Explicit qualification** — `d.BaseA::display();` names which base’s member to use
- **Virtual functions** in the shared base for proper run-time polymorphism
- **Override in derived** — provide a single `display()` in `Derived`
- With virtual bases, the derived constructor may need to **initialize the virtual base** explicitly

%%%MOCHI_CARD%%%
Show solving the diamond problem with virtual inheritance. How does `Derived` ensure a single shared `Base` subobject is constructed? #q26 #diamond-problem #oop-concepts

---
```cpp
class BaseA : virtual public Base {};
class BaseB : virtual public Base {};

class Derived : public BaseA, public BaseB {
public:
    Derived() : Base(), BaseA(), BaseB() {}
};
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain the diamond problem. #q26 #diamond-problem #oop-concepts

---

- Multiple inheritance + shared ancestor → **duplicate base** + **ambiguous** members
- Fix with **`virtual` inheritance** (preferred), qualification, or overrides
- Use **`override`**; **`= default`** ctors/dtors when possible
