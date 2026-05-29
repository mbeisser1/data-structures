What is the purpose of `std::exception` and its derived classes? #q49 #std-exception #exceptions

---
**`std::exception`** is the **base class** for standard C++ exceptions.

**Benefits:**

- **Polymorphic handling** via **`const std::exception&`**
- **`what()`** returns a human-readable message
- Derived types model **specific error categories** (logic vs runtime vs allocation)

%%%MOCHI_CARD%%%
What are common `std::exception` derived types? #q49 #std-exception #exceptions

---

- **`std::logic_error`** — program logic bugs
  - **`std::invalid_argument`**, **`std::out_of_range`**, **`std::length_error`**
- **`std::runtime_error`** — runtime failures
  - **`std::overflow_error`**, **`std::system_error`**
- **`std::bad_alloc`** — `new` failure
- **`std::bad_cast`**, **`std::bad_typeid`** — RTTI errors
- **`std::future_error`**, **`std::filesystem::filesystem_error`** — async / filesystem

All provide **`what() const noexcept`** (some add **`code()`** or path accessors).

%%%MOCHI_CARD%%%
Show catching multiple derived exceptions. How do you throw different standard types and handle them through `const std::exception&`? #q49 #std-exception #exceptions

---
```cpp
#include <iostream>
#include <exception>
#include <stdexcept>
#include <new>

void handleException(const std::exception& ex) {
    std::cout << "Exception: " << ex.what() << std::endl;
}

void simulateExceptions(int exType) {
    switch (exType) {
        case 1: throw std::invalid_argument("Invalid argument!");
        case 2: throw std::bad_alloc();
        case 3: throw std::out_of_range("Out of range!");
        default: throw std::runtime_error("Generic runtime error");
    }
}

int main() {
    for (int i = 1; i <= 4; ++i) {
        try {
            simulateExceptions(i);
        } catch (const std::exception& ex) {
            handleException(ex);
        }
    }
    return 0;
}
```

%%%MOCHI_CARD%%%
When should you catch specific vs base exception types? #q49 #std-exception #exceptions

---

- Catch **specific** types when you can **recover differently**
- Catch **`std::exception`** as a **catch-all** for unknown standard errors
- Use **`dynamic_cast`** only when you need runtime type info (rare with good design)
- Custom types should also derive from **`std::exception`**

%%%MOCHI_CARD%%%
In about 60 seconds, explain `std::exception`. #q49 #std-exception #exceptions

---

- Base for **all standard exceptions**
- **`what()`** for messages; catch by **`const std::exception&`**
- **Logic** vs **runtime** branches cover most library throws
- Derive custom exceptions from it for interoperability
