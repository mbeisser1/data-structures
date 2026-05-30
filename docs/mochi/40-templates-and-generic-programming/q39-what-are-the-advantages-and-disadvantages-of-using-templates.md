What are the advantages and disadvantages of using templates? #q39 #templates-pros-cons #templates-generic

---

**Advantages:**

- **Code reusability** — generic functions/classes operate on any suitable type
- **Type safety** — strong type-checking at compile time without losing flexibility
- **Performance** — specialized instantiations enable compiler optimizations
- **Flexibility** — tailor memory management and processing per type
- **Compile-time polymorphism** — often more efficient than run-time virtual dispatch

**Disadvantages:**

- **Code bloat** — many instantiations increase executable size and cache pressure
- **Compilation time** — complex templated libraries slow builds
- **Error messages** — long, hard-to-read diagnostics (especially with TMP)
- **Debuggability** — some issues surface only for specific instantiations
- **Learning curve** — advanced template features require deep C++ knowledge
- **Header-only libraries** — implementations usually live in headers, hurting separate compilation

%%%MOCHI_CARD%%%
Show a function template illustrating reuse. How does one `max` definition serve multiple types? #q39 #templates-pros-cons #templates-generic

---
```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Reuse: max works for int, double, etc.
// Bloat: each distinct T generates its own max<T>
```

%%%MOCHI_CARD%%%
Show a class template illustrating instantiation cost. How do multiple `Array<T, N>` instantiations affect compile time and binary size? #q39 #templates-pros-cons #templates-generic

---
```cpp
template <typename T, size_t N>
class Array { T data[N]; /* ... */ };

Array<int, 10> arr1;
Array<double, 20> arr2;
Array<std::string, 30> arr3;
// Many instantiations → longer builds
```

%%%MOCHI_CARD%%%
In about 60 seconds, summarize template pros and cons. #q39 #templates-pros-cons #templates-generic

---

- **Pros:** reuse, safety, speed, compile-time polymorphism
- **Cons:** binary bloat, compile time, error/debug pain, header coupling
- Use templates where genericity pays off; prefer **concepts** and restraint to limit complexity
