How do you implement a stack unwinding mechanism? #q50 #stack-unwinding #exceptions

---
**Stack unwinding** ensures **proper cleanup of resources** when an exception is thrown — the runtime **systematically destroys objects** as execution unwinds through the call stack.

**Steps:**

1. An **exception object** is created and thrown
2. The runtime **searches for a `catch` block**, unwinding frame by frame
3. **Local objects** in each frame are destroyed in **reverse order** of construction
4. Matching **`catch`** runs; otherwise unwinding continues until termination

%%%MOCHI_CARD%%%
What implements stack unwinding in C++? #q50 #stack-unwinding #exceptions

---

- **Compiler-generated** cleanup code (you don’t hand-write unwind loops)
- **Exception tables** map PC values to cleanup handlers
- **Unwinding library** (e.g. **`libunwind`**) traverses frames
- **RAII** relies on this — dtors must run during unwind

%%%MOCHI_CARD%%%
Show stack unwinding with RAII resources. What destructor order do you expect when an exception propagates from `innerFunction` through `outerFunction` to `main`? #q50 #stack-unwinding #exceptions

---
```cpp
#include <iostream>
#include <stdexcept>

class Resource {
public:
    Resource(int id) : m_id(id) {
        std::cout << "Resource " << m_id << " acquired\n";
    }
    ~Resource() {
        std::cout << "Resource " << m_id << " released\n";
    }
private:
    int m_id;
};

void innerFunction() {
    Resource r1(1);
    Resource r2(2);
    throw std::runtime_error("Error in innerFunction");
}

void outerFunction() {
    Resource r3(3);
    try {
        innerFunction();
    } catch (const std::exception& e) {
        std::cout << "Caught in outerFunction: " << e.what() << '\n';
        throw; // Re-throw
    }
}

int main() {
    try {
        outerFunction();
    } catch (const std::exception& e) {
        std::cout << "Caught in main: " << e.what() << '\n';
    }
}
```

%%%MOCHI_CARD%%%
What must destructors guarantee during stack unwinding? #q50 #stack-unwinding #exceptions

---

- Destructors must **not throw** (implicit **`noexcept`**)
- Throwing from a dtor during unwind → **`std::terminate`**
- Use **RAII** for all scoped resources
- **`noexcept` functions** that throw skip normal unwind → immediate terminate

%%%MOCHI_CARD%%%
In about 60 seconds, explain stack unwinding. #q50 #stack-unwinding #exceptions

---

- Compiler + runtime **unwind the stack** on throw
- **Dtors run** inner-to-outer until a **`catch`** matches
- **RAII** makes cleanup automatic
- Never throw from destructors; rely on generated unwind tables
