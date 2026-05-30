Explain the difference between function templates and class templates. #q32 #function-class-templates #templates-generic

---
Both **function templates** and **class templates** enable **generic programming** — code that works with different data types — but they have **distinct characteristics** and **use cases**.

%%%MOCHI_CARD%%%
Show a function template. How does `max` work when called with integers vs floating-point values? #q32 #function-class-templates #templates-generic

---
```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int maxInt = max(5, 10);           // T deduced as int
double maxDouble = max(3.14, 2.71); // T deduced as double
```

%%%MOCHI_CARD%%%
What are key properties of function templates? #q32 #function-class-templates #templates-generic

---

- Type **inferred** from the function’s arguments
- **Instantiated** when called with specific types
- Useful for **operations** that must work on multiple data types

%%%MOCHI_CARD%%%
Show a class template. How do you build a generic `Stack<T>` and instantiate it for different element types? #q32 #function-class-templates #templates-generic

---
```cpp
template <typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(T const& elem) { elements.push_back(elem); }
    void pop() { elements.pop_back(); }
    T top() const { return elements.back(); }
    bool empty() const { return elements.empty(); }
};

Stack<int> intStack;
Stack<std::string> stringStack;
```

%%%MOCHI_CARD%%%
What are key properties of class templates? #q32 #function-class-templates #templates-generic

---

- Create **generic data structures** or types
- Type **must be specified** when instantiating: `Stack<int>`
- Useful for **containers**, mathematical structures, or any multi-type class

%%%MOCHI_CARD%%%
When should you use function vs class templates? #q32 #function-class-templates #templates-generic

---

- **Function templates** — generic **algorithms/operations** on multiple types (sorting, finding elements)
- **Class templates** — generic **data structures/types** (vectors, lists, custom containers)
- Modern C++ adds **`auto`**, **variadic templates**, and **concepts** to both

%%%MOCHI_CARD%%%
In about 60 seconds, compare function and class templates. #q32 #function-class-templates #templates-generic

---

- **Function:** `template <typename T> void f(T x)` — type **deduced** at call site
- **Class:** `template <typename T> class C` — type **explicit** at `C<int>`
- Functions → **operations**; classes → **data structures**
- Both compile to **separate instantiations** per type
