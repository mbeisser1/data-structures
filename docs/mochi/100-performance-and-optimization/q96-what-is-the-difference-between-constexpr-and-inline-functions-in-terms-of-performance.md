What is the difference between `constexpr` and `inline` functions in terms of performance? #q96 #constexpr-vs-inline #performance

---

**`constexpr`**

- Can run at **compile time** when args are constants
- **`constexpr int x = square(5);`** — no runtime cost
- At runtime, behaves like a normal function unless inlined

**`inline`**

- Hints **inlining** at call sites — removes call overhead
- May **duplicate** code → I-cache bloat if overused
- Modern compilers inline without keyword

%%%MOCHI_CARD%%%
Show compile-time vs runtime behavior. When does `constexpr` eliminate runtime work that `inline` alone might not? #q96 #constexpr-vs-inline #performance

---
```cpp
constexpr int square(int x) { return x * x; }
constexpr int result = square(5);  // compile-time

inline int add(int a, int b) { return a + b; }
int r = add(3, 4);  // may become: int r = 3 + 4;
```

**`constexpr`** enables **constant folding** and array sizes at compile time.

%%%MOCHI_CARD%%%
What are key performance differences? #q96 #constexpr-vs-inline #performance

---

| Aspect | `constexpr` | `inline` |
| --- | --- | --- |
| Primary goal | Compile-time eval | Call-site inlining |
| When it wins | Constant contexts, templates | Tiny hot functions |
| Code size | Single eval at compile time | May duplicate body |
| Restrictions | Literal-friendly body rules | Fewer restrictions |

Both can end up inlined; **`constexpr`** adds **compile-time computation** semantics.

%%%MOCHI_CARD%%%
What are modern C++ considerations? #q96 #constexpr-vs-inline #performance

---

- **`inline`** often unnecessary — trust **`-O2`** / LTO
- **`constexpr`** grew in C++14/17 — more usable in real functions
- **`consteval`** (C++20) — **must** compile-time; stricter than **`constexpr`**
- Use **`constexpr`** for constants/tables; **`inline`** rarely needed explicitly

%%%MOCHI_CARD%%%
In about 60 seconds, explain constexpr vs inline performance. #q96 #constexpr-vs-inline #performance

---

- **`constexpr`** = work at **compile time** when possible
- **`inline`** = hint to **embed** function body at calls
- Different goals; both may inline at runtime
- Prefer **`constexpr`** for compile-time constants; omit **`inline`** unless ODR needs it
