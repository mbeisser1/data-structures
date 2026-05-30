Explain the concept of destructors in C++. #q08 #destructors #cpp-basics

---
A **destructor** is a special member function **automatically called** when an object **goes out of scope** or is explicitly **`delete`d**. Its primary purpose is **proper cleanup** of the object’s allocated resources.

%%%MOCHI_CARD%%%
What are the key features of C++ destructors? #q08 #destructors #cpp-basics

---

- Syntax: **`~ClassName()`** — no return type, typically no parameters.
- Called **automatically** (implicitly) at end of lifetime.
- Objects destroy in **reverse order** of construction.
- **`virtual` destructors** are required in polymorphic base classes.

%%%MOCHI_CARD%%%
What are common destructor use cases? #q08 #destructors #cpp-basics

---

- **Memory** — `delete` / `delete[]` for dynamic arrays and owned pointers.
- **Files** — close open streams in `~FileHandler()`.
- **Resources** — release when the destructor runs:
  - **Sockets**
  - **DB connections**
  - **Locks**

%%%MOCHI_CARD%%%
What are destructor best practices in modern C++? #q08 #destructors #cpp-basics

---

- Implement **RAII**: acquire in constructor, release in destructor.
- Base classes used polymorphically need **`virtual ~Base()`** (often `= default`).
- Prefer **`noexcept`** destructors when possible (C++11+).
- Prefer **smart pointers** so cleanup is automatic:
  - **`unique_ptr`**
  - **`shared_ptr`**

%%%MOCHI_CARD%%%
In about 60 seconds, explain destructors in C++. #q08 #destructors #cpp-basics

---

- **`~T()`** runs at end of life to **free resources** (RAII).
- No return type/args; destruction order is **LIFO**.
- **Virtual destructor** in bases for safe `delete` through pointers.
- Modern C++:
  - **`= default`** destructors
  - **`noexcept`** destructors
  - **Smart pointers** to reduce manual cleanup
