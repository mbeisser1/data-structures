What is the difference between `struct` and `class` in C++? #q06 #struct-vs-class #cpp-basics

---
In C++, both **`struct`** and **`class`** create **user-defined types**, but they differ in **default member access**, **default inheritance access**, and typical **use cases**.

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

- **`struct`** — suited for small, simple objects with **mostly public** data (often **POD-like** aggregates).
- **`class`** — intended for larger, more complex types using **encapsulation**, **data hiding**, and member functions.
- In modern C++ the distinction is mainly **defaults and convention**; both can have constructors, destructors, and methods.

%%%MOCHI_CARD%%%
In about 60 seconds, explain `struct` vs `class` in C++. #q06 #struct-vs-class #cpp-basics

---

- Syntax is almost identical; defaults differ.
- **`struct` → public** members and **public** inheritance by default.
- **`class` → private** members and **private** inheritance by default.
- Use **`struct`** for plain data aggregates; **`class`** for encapsulated objects with behavior.
