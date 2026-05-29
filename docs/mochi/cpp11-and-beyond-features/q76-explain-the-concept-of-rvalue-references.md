Explain the concept of rvalue references. #q76 #rvalue-refs #cpp11-beyond

---
An **rvalue reference** is declared with **`&&`** and binds to **temporaries** (rvalues) — enabling **move semantics** and **perfect forwarding**.

**Lvalue reference `&`** — binds to named objects  
**Rvalue reference `&&`** — binds to temporaries and moved-from objects

The compiler can overload on value category for efficient resource transfer.

%%%MOCHI_CARD%%%
What are key use cases for rvalue references? #q76 #rvalue-refs #cpp11-beyond

---

**Move semantics**

```cpp
std::vector<int> vec = createVector(); // move from temporary
```

**Perfect forwarding**

```cpp
template<typename T>
void wrapper(T&& arg) {
    foo(std::forward<T>(arg));
}
```

**Move constructor/assignment** — steal resources from expiring objects.

%%%MOCHI_CARD%%%
Show rvalue reference binding and `std::move`. #q76 #rvalue-refs #cpp11-beyond

---
```cpp
#include <iostream>
#include <utility>

void modifyRValue(int&& rvalue) {
    rvalue += 10;
    std::cout << "Inside modifyRValue: " << rvalue << '\n';
}

int main() {
    int&& rvref = 5;
    std::cout << "Initial value: " << rvref << '\n';

    modifyRValue(std::move(rvref));
    std::cout << "After move: " << rvref << '\n';

    return 0;
}
```

**`std::move`** casts to rvalue — does not move by itself; enables move ctor/assignment.

%%%MOCHI_CARD%%%
What utilities support rvalue references? #q76 #rvalue-refs #cpp11-beyond

---

- **`std::move`** — cast to rvalue reference
- **`std::forward`** — preserve value category in templates
- **Move ctor/assign** — `T(T&&)`, `T& operator=(T&&)`
- **C++17 guaranteed copy elision** — sometimes no move needed for prvalues

After move, source is in a **valid but unspecified** state.

%%%MOCHI_CARD%%%
In about 60 seconds, explain rvalue references. #q76 #rvalue-refs #cpp11-beyond

---

- **`&&`** binds to temporaries
- Enables **moves** instead of copies
- **`std::move`** + move operations transfer ownership
- Foundation for **perfect forwarding** with **`T&&`** in templates
