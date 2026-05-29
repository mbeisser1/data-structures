What are templates in C++? #q31 #templates #templates-generic

---
**Templates** enable **generic programming** — write one pattern that works for many types while keeping **type safety**. Heavily used in the **STL** for containers and algorithms.

%%%MOCHI_CARD%%%
Show a basic function template. #q31 #templates #templates-generic

---
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int result1 = add(5, 3);         // Instantiates add<int>
double result2 = add(3.14, 2.5); // Instantiates add<double>
```

- The compiler **generates** a concrete version per type used
- `T` must support the operations you use (here **`+`**)

%%%MOCHI_CARD%%%
Show a class template example. #q31 #templates #templates-generic

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
```

- **Class templates** — type parameter specified at instantiation: `Vector<int>`
- **Specialization** — custom version for a specific type:

```cpp
template <>
class Vector<bool> {
    // Specialized implementation for bool
};
```

%%%MOCHI_CARD%%%
How do C++20 concepts relate to templates? #q31 #templates #templates-generic

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

- **Concepts** constrain template parameters with clearer errors than raw templates alone

%%%MOCHI_CARD%%%
In about 60 seconds, explain templates in C++. #q31 #templates #templates-generic

---

- **Generic code** — one definition, many types; compiler **instantiates** per use
- **Function templates** — type often **deduced** from arguments
- **Class templates** — type specified: `Stack<int>`
- **Specialization** for specific types; **concepts** (C++20) for constraints
- Foundation of the **STL**
