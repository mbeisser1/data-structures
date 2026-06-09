What are templates in C++? #q31 #templates #templates-generic

---
**Templates** in C++ enable **generic programming** — code that works with **multiple data types** without sacrificing **type safety**. They are extensively used in the **Standard Template Library (STL)** for containers and algorithms.

%%%MOCHI_CARD%%%
Show a basic function template. How do you write one `add` that works for both `int` and `double`? #q31 #templates #templates-generic

---
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int result1 = add(5, 3);         // Instantiates add<int>
double result2 = add(3.14, 2.5); // Instantiates add<double>
```

%%%MOCHI_CARD%%%
What happens when you call a function template? #q31 #templates #templates-generic

---

- The compiler **generates** a concrete version per type used
- `T` must support the operations you use (here **`+`**)

%%%MOCHI_CARD%%%
Show a class template example. How do you declare a generic `Vector<T>` and specialize it for one type? #q31 #templates #templates-generic

---
```cpp
template <typename T>
class Vector {
private:
    T* elements;
    size_t size;
public:
    // ... methods ...
};

Vector<int> intVector;
Vector<std::string> stringVector;

template <>
class Vector<bool> {
    // Specialized implementation for bool
};
```

%%%MOCHI_CARD%%%
How do C++20 concepts relate to templates? #q31 #templates #templates-generic

---

- **Concepts** constrain template parameters with clearer errors than raw templates alone

%%%MOCHI_CARD%%%
Show C++20 concepts constraining templates. How do you restrict `add` to types where `a + b` is valid? #q31 #templates #templates-generic

---
```cpp
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
};

template <Addable T>
T add(T a, T b) {
    return a + b;
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain templates in C++. #q31 #templates #templates-generic

---

- **Generic code** — one definition, many types; compiler **instantiates** per use
- **Function templates** — type often **deduced** from arguments
- **Class templates** — type specified: `Stack<int>`
- **Specialization** for specific types; **concepts** (C++20) for constraints
- Foundation of the **STL**
