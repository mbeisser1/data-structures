What are delegating constructors? #q75 #delegating-ctors #cpp11-beyond

---
**Delegating constructors** (C++11) let one constructor **call another** of the same class — centralizing initialization logic.

```cpp
Person() : Person("John Doe", 30) { }
```

The **delegate call must be the only** entry in the initializer list (no mixed member init before it).

%%%MOCHI_CARD%%%
Show delegating constructors with a `Person` class. #q75 #delegating-ctors #cpp11-beyond

---
```cpp
class Person {
    std::string name;
    int age;
public:
    Person(const std::string& n, int a) : name(n), age(a) {
        std::cout << "Base constructor called\n";
    }

    Person() : Person("John Doe", 30) {
        std::cout << "Delegating constructor called\n";
    }

    Person(const std::string& n) : Person(n, 25) {
        std::cout << "Name-only constructor called\n";
    }
};
```

All paths eventually run the **target constructor’s** member initialization.

%%%MOCHI_CARD%%%
What are rules and limitations for delegating constructors? #q75 #delegating-ctors #cpp11-beyond

---

- **One delegate** per constructor — single target in init list
- **No cycles** — A→B→A is ill-formed / undefined
- Delegating ctor **cannot** initialize members before delegating
- Body of delegating ctor runs **after** target ctor completes

Alternative: **default arguments** on one constructor instead of many delegates.

%%%MOCHI_CARD%%%
What are best practices for delegating constructors? #q75 #delegating-ctors #cpp11-beyond

---

- Pick **one “master”** constructor with full init logic
- Delegate simpler overloads to it — **DRY**
- Avoid **long delegation chains** — hard to follow
- Combine with **`explicit`**, **`= default`**, **`= delete`** as needed

%%%MOCHI_CARD%%%
In about 60 seconds, explain delegating constructors. #q75 #delegating-ctors #cpp11-beyond

---

- C++11: **`Ctor() : Ctor(args) { }`**
- Reduces duplicated member init
- Delegate must be **sole** initializer-list item
- No circular delegation; prefer one primary ctor
