Explain the concept of namespaces in C++. #q05 #namespaces #cpp-basics

---
**Namespaces** group related code and prevent naming collisions. They let large projects organize declarations into logical scopes instead of one flat global namespace.

%%%MOCHI_CARD%%%
How do you declare and use a namespace in C++? #q05 #namespaces #cpp-basics

---

- Declare with `namespace Name { ... }`.
- Refer with **`::`**: `Name::function()`.
- Or bring names in with **`using namespace Name;`** (use narrowly—especially avoid `using namespace std;` in headers).

%%%MOCHI_CARD%%%
What are nested namespaces in C++? #q05 #namespaces #cpp-basics

---

- Namespaces can nest: `namespace Outer { namespace Inner { ... } }`.
- **C++17** shorthand: `namespace Outer::Inner { ... }`.
- Qualified names chain with `::`, e.g. `Outer::Inner::function()`.

%%%MOCHI_CARD%%%
What is an unnamed (anonymous) namespace? #q05 #namespaces #cpp-basics

---
An **unnamed namespace** limits its contents to the **current translation unit** (internal linkage), similar in spirit to `static` at file scope.

%%%MOCHI_CARD%%%
Show an unnamed (anonymous) namespace. Declare `hidden_variable = 42` inside `namespace { }` so it has internal linkage in this translation unit. #q05 #namespaces #cpp-basics

---
```cpp
namespace {
    int hidden_variable = 42;
}
```

%%%MOCHI_CARD%%%
What is a namespace alias in C++? #q05 #namespaces #cpp-basics

---
A **namespace alias** shortens long qualified names.

%%%MOCHI_CARD%%%
Show a namespace alias. Map `vln` to `very_long_namespace_name` and call `vln::function()` instead of the full qualified name. #q05 #namespaces #cpp-basics

---
```cpp
namespace very_long_namespace_name { void function(); }
namespace vln = very_long_namespace_name;
vln::function();  // same as very_long_namespace_name::function()
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain namespaces in C++. #q05 #namespaces #cpp-basics

---

- Namespaces **organize code** and **avoid name clashes**.
- Use **`::`** for qualification; prefer **`using`** declarations over broad `using namespace`.
- **Nested** namespaces (C++17 `A::B`) model hierarchical APIs.
- **Unnamed namespaces** hide helpers inside one `.cpp` file; **aliases** shorten verbose names.
