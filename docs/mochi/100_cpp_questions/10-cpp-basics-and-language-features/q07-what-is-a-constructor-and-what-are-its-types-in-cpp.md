What is a constructor in C++? #q07 #constructors #cpp-basics

---
A **constructor** is a special member function **responsible for initializing** instances of a class. It is called **automatically** when an object is created.

%%%MOCHI_CARD%%%
What are the main types of constructors in C++? #q07 #constructors #cpp-basics

---

- **Default** — no args or `= default`; compiler-generated if you don’t define others (under rules).
- **Parameterized** — takes arguments to initialize members.
- **Copy** — `T(const T&)`; duplicates an existing object.
- **Move** — `T(T&&)` (C++11); steals resources from a temporary/rvalue.
- **Delegating** — one constructor calls another in the same class (C++11).
- **Inherited** — `using Base::Base;` reuses base constructors (C++11).

%%%MOCHI_CARD%%%
Show brief examples of copy, move, and delegating constructors. In `MyClass`, copy-initialize `data_` from `other` and move it with `std::move`; in `Rectangle`, default-construct by delegating to `Rectangle(0, 0)`. #q07 #constructors #cpp-basics

---
```cpp
class MyClass {
public:
    MyClass(const MyClass& other) : data_(other.data_) {}
    MyClass(MyClass&& other) noexcept : data_(std::move(other.data_)) {}
};

class Rectangle {
public:
    Rectangle(int l, int w) : length(l), width(w) {}
    Rectangle() : Rectangle(0, 0) {}  // delegating
private:
    int length, width;
};
```

%%%MOCHI_CARD%%%
What are key constructor best practices in modern C++? #q07 #constructors #cpp-basics

---

- Declare constructors in the **`public`** section (usually).
- **Constructor overloading** is allowed—distinct parameter lists.
- Prefer **member initializer lists** for:
  - **Base** subobjects
  - **`const` members**
  - **Reference** members
- Use **`= default`** / **`= delete`** explicitly when needed (C++11).
- For resource-owning types, follow the **Rule of Five** or prefer **Rule of Zero** with smart pointers.

%%%MOCHI_CARD%%%
In about 60 seconds, explain constructors in C++. #q07 #constructors #cpp-basics

---

- Constructors **initialize** objects at creation; no return type.
- Constructor types to know:
  - **Default**
  - **Parameterized**
  - **Copy**
  - **Move**
  - **Delegating**
  - **Inherited**
- Use **initializer lists**; **`= default`/`= delete`** for clarity.
- Resource classes: **Rule of Five/Zero**; moves use **`std::move`**.
