How do you implement a singleton pattern in C++? #q84 #singleton #advanced-cpp

---
**Singleton** ensures **one instance** and global access via **`getInstance()`**.

**Modern Meyer's singleton (C++11+):**

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

**Static local** initialization is **thread-safe** in C++11+.

%%%MOCHI_CARD%%%
Show verifying singleton uniqueness. #q84 #singleton #advanced-cpp

---
```cpp
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
Show pointer-based singleton alternative. #q84 #singleton #advanced-cpp

---
```cpp
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
