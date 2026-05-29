What is the difference between `struct` and `class` in C++? #q06 #struct-vs-class #cpp-basics

---
Both define **user-defined types** with nearly the same capabilities:

- **Members**
- **Methods**
- **Constructors**
- **Destructors**

The main differences are **default access** and typical **design intent**.

%%%MOCHI_CARD%%%
How do default member access levels differ for `struct` and `class`? #q06 #struct-vs-class #cpp-basics

---

- **`struct`** — members are **`public` by default**.
- **`class`** — members are **`private` by default**.

%%%MOCHI_CARD%%%
How do default inheritance access levels differ for `struct` and `class`? #q06 #struct-vs-class #cpp-basics

---

- **`struct`** — **public** inheritance by default.
- **`class`** — **private** inheritance by default.

%%%MOCHI_CARD%%%
When do developers typically choose `struct` vs `class`? #q06 #struct-vs-class #cpp-basics

---

- **`struct`** — simple aggregates / **POD-like** data with mostly public fields.
- **`class`** — types with:
  - **Encapsulation**
  - **Invariants**
  - **Behavior** via member functions
- In modern C++ the keyword choice is mostly **convention**; either can have methods and special members.

%%%MOCHI_CARD%%%
In about 60 seconds, explain `struct` vs `class` in C++. #q06 #struct-vs-class #cpp-basics

---

- Syntax is almost identical; defaults differ.
- **`struct` → public** members and **public** inheritance by default.
- **`class` → private** members and **private** inheritance by default.
- Use **`struct`** for plain data aggregates; **`class`** for encapsulated objects with behavior.
