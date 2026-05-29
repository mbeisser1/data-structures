Explain the difference between function templates and class templates. #q32 #function-class-templates #templates-generic

---
Both support **generic programming**, but they differ in **syntax**, **type specification**, and typical **use cases**.

%%%MOCHI_CARD%%%
Show a function template. #q32 #function-class-templates #templates-generic

---
```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int maxInt = max(5, 10);           // T deduced as int
double maxDouble = max(3.14, 2.71); // T deduced as double
```

**Function templates:**

- Type often **inferred** from arguments
- **Instantiated** when called with specific types
- Good for **algorithms** and type-parametric operations

%%%MOCHI_CARD%%%
Show a class template. #q32 #function-class-templates #templates-generic

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

**Class templates:**

- Type **must be specified** at instantiation: `Stack<int>`
- Good for **containers** and generic data structures

%%%MOCHI_CARD%%%
When should you use function vs class templates? #q32 #function-class-templates #templates-generic

---

- **Function templates** — generic **algorithms/operations** (sort, max, swap-like utilities)
- **Class templates** — generic **types/containers** (`vector`, custom stacks, matrices)
- Modern C++ adds **`auto`**, **variadic templates**, and **concepts** to both

%%%MOCHI_CARD%%%
In about 60 seconds, compare function and class templates. #q32 #function-class-templates #templates-generic

---

- **Function:** `template <typename T> void f(T x)` — type **deduced** at call site
- **Class:** `template <typename T> class C` — type **explicit** at `C<int>`
- Functions → **operations**; classes → **data structures**
- Both compile to **separate instantiations** per type
