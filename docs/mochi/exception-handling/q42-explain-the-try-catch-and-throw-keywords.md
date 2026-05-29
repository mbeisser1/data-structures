Explain the `try`, `catch`, and `throw` keywords. #q42 #try-catch-throw #exceptions

---

- **`try`** — encloses code that may throw
- **`catch`** — handles exceptions of a matching type
- **`throw`** — raises an exception object

**Flow:** execute `try` → on throw, search matching **`catch`** up the stack → handle or terminate.

%%%MOCHI_CARD%%%
What is the syntax for `try`, `catch`, and `throw`? #q42 #try-catch-throw #exceptions

---

- **`try { ... }`** — guarded code
- **`catch (const ExceptionType& e) { ... }`** — handler (prefer **const reference** to avoid slicing)
- **`throw ExceptionObject();`** — raise an exception

%%%MOCHI_CARD%%%
Show the syntax for `try`, `catch`, and `throw`. What do the three keywords look like in minimal form? #q42 #try-catch-throw #exceptions

---
```cpp
try {
    // Code that might throw
}
catch (ExceptionType& e) {
    // Handle the exception
}

throw ExceptionObject();
```

%%%MOCHI_CARD%%%
Show `try`, `catch`, and `throw` with age validation. How do you throw different standard exceptions for invalid vs out-of-range age and catch each separately? #q42 #try-catch-throw #exceptions

---
```cpp
#include <iostream>
#include <stdexcept>

void validateAge(int age) {
    if (age < 0) {
        throw std::invalid_argument("Age cannot be negative");
    }
    if (age > 150) {
        throw std::out_of_range("Age is unrealistically high");
    }
}

int main() {
    try {
        int age;
        std::cin >> age;
        validateAge(age);
        std::cout << "Your age is: " << age << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
    return 0;
}
```

%%%MOCHI_CARD%%%
What are best practices for `try`/`catch`/`throw`? #q42 #try-catch-throw #exceptions

---

- Prefer **standard exception types** when they fit
- **Catch by const reference**
- Order **`catch`** blocks **most specific → most general**
- Use **`noexcept`** when a function truly cannot throw
- In hot paths consider **`std::optional`** or **`std::expected`** (C++23)

%%%MOCHI_CARD%%%
In about 60 seconds, explain try, catch, and throw. #q42 #try-catch-throw #exceptions

---

- **`throw`** raises; **`try`** defines guarded code; **`catch`** handles by type
- Unhandled exceptions **propagate** up the call stack
- Catch **specific types first**, then **`std::exception`**
- Always **`const&`** in catch handlers
