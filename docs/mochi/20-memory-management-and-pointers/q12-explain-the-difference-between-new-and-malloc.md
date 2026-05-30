Explain the difference between `new` and `malloc()`. #q12 #new-vs-malloc #memory-pointers

---
In C++, both **`new`** and **`malloc()`** are used for **dynamic memory allocation**, but they have different origins and characteristics — **`new`** is C++; **`malloc()`** comes from C.

%%%MOCHI_CARD%%%
How do `new` and `malloc()` differ on return type and failure? #q12 #new-vs-malloc #memory-pointers

---

- **`new`** — returns a **typed pointer**; on failure throws **`std::bad_alloc`** (unless a custom handler is set).
- **`malloc()`** — returns **`void*`**; on failure returns **`nullptr`** (must cast to target type).

%%%MOCHI_CARD%%%
How do construction, destruction, and sizing differ? #q12 #new-vs-malloc #memory-pointers

---

- **`new`** — allocates **and constructs**; **`delete`** destroys **then** deallocates.
- **`malloc()` / `free()`** — raw memory only; **no constructors/destructors** (use **placement new** + manual dtor if needed).
- **`new`** deduces size from **type**; **`malloc(n)`** needs **bytes** explicitly.

%%%MOCHI_CARD%%%
Show `new` vs `malloc` with `Widget`. How does construction and cleanup differ between `new`/`delete` and `malloc`/`free`? #q12 #new-vs-malloc #memory-pointers

---
```cpp
#include <iostream>
#include <cstdlib>
#include <new>

class Widget {
public:
    Widget(int val) : value(val) { std::cout << "Widget constructed\n"; }
    ~Widget() { std::cout << "Widget destructed\n"; }
private:
    int value;
};

int main() {
    Widget* w1 = new Widget(5);
    int* arr = new int[10];

    Widget* w2 = static_cast<Widget*>(std::malloc(sizeof(Widget)));
    if (w2) {
        new (w2) Widget(10);  // placement new
    }

    delete w1;
    delete[] arr;

    if (w2) {
        w2->~Widget();
        std::free(w2);
    }

    return 0;
}
```

%%%MOCHI_CARD%%%
What should modern C++ code use instead of raw `malloc`/`new`? #q12 #new-vs-malloc #memory-pointers

---

- Prefer **`new`/`delete`** (or smart pointers) over **`malloc`/`free`** in C++.
- Better: **`std::unique_ptr` / `std::shared_ptr`** with **`make_unique` / `make_shared`**.
- Prefer **`std::vector`** over manual dynamic arrays when possible.

%%%MOCHI_CARD%%%
Show modern alternatives to manual heap management. How would you own a `Widget` and a dynamic `int` sequence without raw `new`? #q12 #new-vs-malloc #memory-pointers

---
```cpp
#include <memory>
#include <vector>

std::unique_ptr<Widget> w = std::make_unique<Widget>(5);
std::vector<int> vec(10);  // Dynamic array managed by vector
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain `new` vs `malloc()`. #q12 #new-vs-malloc #memory-pointers

---

- **`new`**: C++, typed, throws on failure, **calls ctor/dtor**.
- **`malloc`**: C, `void*`, null on failure, **raw bytes only**; placement new + manual dtor if needed.
- Modern style: **smart pointers + containers**, not manual heap management.
