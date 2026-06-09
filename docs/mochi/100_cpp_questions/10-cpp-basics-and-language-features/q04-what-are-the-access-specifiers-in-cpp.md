What are the access specifiers in C++ and what do they do? #q04 #access-specifiers #cpp-basics

---
**Access specifiers** are keywords that control the visibility and accessibility of class members. They enable **data encapsulation** — protecting data integrity and separating a class’s **interface** from its **implementation**.

%%%MOCHI_CARD%%%
What are the three access specifiers in C++? #q04 #access-specifiers #cpp-basics

---

- **`public`** — members accessible from **any part of the program**; typically the class interface.
- **`protected`** — accessible in the **containing class**, **derived classes**, and **friends**; useful in inheritance.
- **`private`** — accessible only within the **containing class** and its **friends**; default for **class** members; hides implementation details.

%%%MOCHI_CARD%%%
What are the default access levels for classes and structs in C++? #q04 #access-specifiers #cpp-basics

---

- **`class`** members default to **`private`**.
- **`struct`** and **`union`** members default to **`public`**.
- Access specifiers can appear multiple times in one class to change the access of following members.

%%%MOCHI_CARD%%%
Show access specifiers in a class hierarchy. Define `MyClass` with `public`/`protected`/`private` sections, derive `DerivedClass`, and show what `main` can call vs what fails to compile. #q04 #access-specifiers #cpp-basics

---
```cpp
#include <iostream>

class MyClass {
public:
    void publicMethod() {
        std::cout << "Public method, accessing private data: " << privateData << std::endl;
    }
protected:
    int protectedData = 20;
private:
    int privateData = 10;
};

class DerivedClass : public MyClass {
public:
    void accessProtectedData() {
        std::cout << "Accessing protected data: " << protectedData << std::endl;
    }
};

int main() {
    MyClass obj;
    obj.publicMethod();  // OK
    // obj.privateData;  // Error
    DerivedClass derived;
    derived.accessProtectedData();  // OK
    return 0;
}
```

%%%MOCHI_CARD%%%
What modern C++ rules apply to access specifiers and inheritance? #q04 #access-specifiers #cpp-basics

---

- **`class` inheritance** defaults to **`private`** inheritance.
- **`struct` inheritance** defaults to **`public`** inheritance.
- **`friend`** grants another function or class access to `private` and `protected` members.
- **`enum class`** (C++11) uses the same access control rules as classes.

%%%MOCHI_CARD%%%
In about 60 seconds, explain access specifiers in C++. #q04 #access-specifiers #cpp-basics

---

- Access specifiers:
  - **`public`**
  - **`protected`**
  - **`private`**
- Defaults: **`private`** for class members, **`public`** for struct members.
- **`protected`** bridges base and derived classes; **`private`** hides implementation.
- Inheritance defaults differ for `class` vs `struct`; use **`friend`** sparingly for tight coupling.
