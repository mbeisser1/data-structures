How do you implement a singleton pattern in C++? #q84 #singleton #advanced-cpp

---
The **singleton pattern** ensures a class has **only one instance** and provides a **global point of access** via **`getInstance()`**.

**Meyer’s singleton (C++11+):** function-local **`static`** instance — **thread-safe** lazy initialization; **delete** copy and assignment; **private** constructor.

Delete **copy/move** and make the constructor **private** so only **`getInstance()`** can create the object.

%%%MOCHI_CARD%%%
Show Meyers singleton. How do you guarantee one instance with lazy, thread-safe initialization? #q84 #singleton #advanced-cpp

---
```cpp
class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
private:
    Singleton() = default;
};
```

%%%MOCHI_CARD%%%
Show verifying singleton uniqueness. How do you prove two `getInstance()` calls return the same object? #q84 #singleton #advanced-cpp

---
```cpp
#include <cassert>

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    assert(&s1 == &s2);

    // Singleton s3;           // error: ctor private
    // Singleton s4 = s1;    // error: copy deleted

    return 0;
}
```

Lazy initialization — instance created on **first** **`getInstance()`** call.

%%%MOCHI_CARD%%%
What are key singleton design points? #q84 #singleton #advanced-cpp

---

- **`static` local** inside **`getInstance()`** — preferred
- **Delete copy/move** — prevent duplicates
- **Private constructor** — block direct construction
- Avoid global **`new`** singletons — use static local or **`unique_ptr`** in function

Singleton is often an **anti-pattern** (hidden deps, testing pain) — use sparingly.

%%%MOCHI_CARD%%%
Show pointer-based singleton alternative. When might you return a `Singleton*` from `getInstance()` instead of a reference? #q84 #singleton #advanced-cpp

---
```cpp
#include <memory>

class Singleton {
public:
    static Singleton* getInstance() {
        static std::unique_ptr<Singleton> instance(new Singleton());
        return instance.get();
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
private:
    Singleton() = default;
};
```

Meyer's **`static Singleton instance`** is simpler and usually preferred.

%%%MOCHI_CARD%%%
In about 60 seconds, explain singleton in C++. #q84 #singleton #advanced-cpp

---

- **One instance**, **`getInstance()`** access
- **`static` local** = thread-safe lazy init (C++11)
- Delete **copy/assign**; **private ctor**
- Prefer dependency injection over singleton when you can
