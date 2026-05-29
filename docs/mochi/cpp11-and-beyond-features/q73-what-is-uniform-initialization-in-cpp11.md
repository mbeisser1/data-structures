What is uniform initialization in C++11? #q73 #uniform-init #cpp11-beyond

---
**Uniform initialization** uses **`{}`** for all initialization — primitives, arrays, objects, and containers.

**Benefits:**

- **Consistent syntax** everywhere
- **No narrowing** — `int x{3.14};` is an error
- **Fixes most vexing parse** — `Widget w{args};` vs function declaration
- Prefers **`std::initializer_list`** constructors when available

%%%MOCHI_CARD%%%
Show uniform initialization examples. How does `{}` initialize scalars, containers, and aggregates consistently? #q73 #uniform-init #cpp11-beyond

---
```cpp
int a{5};
double b{3.14};
Point p{10, 20};
int arr[]{1, 2, 3, 4, 5};
std::vector<int> vec{1, 2, 3, 4, 5};
std::map<int, std::string> map{{1, "one"}, {2, "two"}};
```

%%%MOCHI_CARD%%%
How does uniform initialization prevent narrowing? #q73 #uniform-init #cpp11-beyond

---

- Braces enforce **exact-fit** conversions for safer initialization
- **`int x{3.14}`** fails to compile; **`int y(3.14)`** may truncate with a warning

%%%MOCHI_CARD%%%
Show narrowing checks with `{}`. Why does braced initialization reject some conversions that parentheses allow? #q73 #uniform-init #cpp11-beyond

---
```cpp
int x{3.14};  // Error: narrowing conversion
int y(3.14);  // OK (truncates) — may warn
```

%%%MOCHI_CARD%%%
How does initializer_list constructor priority work? #q73 #uniform-init #cpp11-beyond

---

- **`{}`** may call **`initializer_list`** constructors instead of ordinary constructors
- **`()`** vs **`{}`** can select **different** overloads — know which you intend

%%%MOCHI_CARD%%%
Show `initializer_list` priority. How can `{}` vs `()` choose different `Widget` constructors? #q73 #uniform-init #cpp11-beyond

---
```cpp
class Widget {
public:
    Widget(int i, bool b) { /* regular */ }
    Widget(std::initializer_list<long double> il) { /* list */ }
};

Widget w1(10, true);    // regular constructor
Widget w2{10, true};    // initializer_list (narrowing conversions apply)
Widget w3{10, true, 5}; // initializer_list
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain uniform initialization. #q73 #uniform-init #cpp11-beyond

---

- **`{}` everywhere** — one init syntax
- **No narrowing** in brace init
- May prefer **`initializer_list`** ctors
- Pair with **structured bindings** (C++17) for tuple-like returns
