What are the advantages and disadvantages of using templates? #q39 #templates-pros-cons #templates-generic

---

**Advantages:**

- **Code reuse** — one generic definition for many types
- **Type safety** — errors caught at compile time
- **Performance** — monomorphization enables inlining/specialization
- **Flexibility** — custom strategies per type
- **Compile-time polymorphism** — often faster than virtual dispatch

**Disadvantages:**

- **Code bloat** — separate instantiation per type increases binary size
- **Long compile times** — heavy template code in headers
- **Cryptic errors** — deep instantiation stacks
- **Harder debugging** — issues appear only for certain `T`
- **Steep learning curve** — especially TMP
- **Header-only** implementations — hurts separate compilation

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
