What is template specialization? #q33 #template-specialization #templates-generic

---
**Template specialization** lets you provide **custom implementations** for specific data types within a template class or function — useful for:

- **Performance optimization**
- **Non-standard types**
- **Type-specific behavior**

%%%MOCHI_CARD%%%
What are the types of template specialization? #q33 #template-specialization #templates-generic

---

- **Primary template** — default implementation for most types
- **Explicit (full) specialization** — completely different implementation for one type (`template <>`)
- **Partial specialization** — specialize on part of the pattern ( **class templates only**, e.g. `T*`)

%%%MOCHI_CARD%%%
Show template specialization with `Calculator`. How do you provide a generic `add`, a full specialization for `int`, and a partial specialization for pointers? #q33 #template-specialization #templates-generic

---
```cpp
#include <iostream>

template <typename T>
struct Calculator {
    static T add(T a, T b) {
        std::cout << "General addition\n";
        return a + b;
    }
};

template <>
struct Calculator<int> {
    static int add(int a, int b) {
        std::cout << "Optimized integer addition\n";
        return a + b;
    }
};

template <typename T>
struct Calculator<T*> {
    static T* add(T* a, std::ptrdiff_t b) {
        std::cout << "Pointer arithmetic\n";
        return a + b;
    }
};
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain template specialization. #q33 #template-specialization #templates-generic

---

- Override default template behavior for **specific types**
- **Full** specialization: `template <> class Foo<int>`
- **Partial** specialization: `template <typename T> class Foo<T*>`
- Used for optimization and special cases (e.g. `vector<bool>`)
