How do you implement a type-safe container using templates? #q38 #type-safe-container #templates-generic

---
A **type-safe container** ensures that only objects of a **specific type** can be stored and retrieved — implemented with a **class template** so type mismatches fail at **compile time**.

%%%MOCHI_CARD%%%
Show a `TypeSafeContainer` template class. How do you store an optional `T`, set a value, and throw if `getValue` is called when empty? #q38 #type-safe-container #templates-generic

---
```cpp
#include <optional>
#include <stdexcept>

template <typename T>
class TypeSafeContainer {
private:
    std::optional<T> value;

public:
    void setValue(const T& newValue) {
        value = newValue;
    }

    T getValue() const {
        if (!value.has_value()) {
            throw std::logic_error("No value set");
        }
        return value.value();
    }

    bool hasData() const { return value.has_value(); }
    void reset() { value.reset(); }
};
```

%%%MOCHI_CARD%%%
Show using `TypeSafeContainer` for different types. Why does assigning a string to an `int` container fail at compile time? #q38 #type-safe-container #templates-generic

---
```cpp
TypeSafeContainer<int> intContainer;
intContainer.setValue(42);
std::cout << intContainer.getValue() << std::endl;

TypeSafeContainer<std::string> stringContainer;
stringContainer.setValue("Hello, World!");

// Compile error — wrong type:
// intContainer.setValue("Not an integer");
```

%%%MOCHI_CARD%%%
What are design points for type-safe template containers? #q38 #type-safe-container #templates-generic

---

- **`template <typename T>`** — one container per element type
- **`std::optional<T>`** — tracks empty vs populated state
- **`getValue()`** throws if empty — avoids undefined behavior

%%%MOCHI_CARD%%%
In about 60 seconds, explain type-safe containers with templates. #q38 #type-safe-container #templates-generic

---

- **Class template** parameter **`T`** locks stored type at compile time
- **`optional`** + validation for runtime empty checks
- Wrong-type assignments fail at **compile time**
- Pattern behind many STL containers (`vector<T>`, etc.)
