What is function overloading in C++? #q09 #function-overloading #cpp-basics

---
**Function overloading** lets multiple functions **share a name** but differ by **parameter list**:

- **Types**
- **Order**
- **Count**

The compiler picks the best match at compile time (**static polymorphism**).

%%%MOCHI_CARD%%%
How does the compiler distinguish overloaded functions? What are the restrictions? #q09 #function-overloading #cpp-basics

---

- Distinguished by:
  - **Parameter types**
  - **Order**
  - **Count** (including empty/nullary)
- **Return type alone** cannot distinguish overloads.
- Works for **free functions** and **member functions**.

%%%MOCHI_CARD%%%
Show function overloading examples. Overload `print` for `int`, `double`, and `const std::string&` with distinct output labels. #q09 #function-overloading #cpp-basics

---
```cpp
void print(int num) { std::cout << "Integer: " << num << '\n'; }
void print(double num) { std::cout << "Double: " << num << '\n'; }
void print(const std::string& str) { std::cout << "String: " << str << '\n'; }
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain function overloading in C++. #q09 #function-overloading #cpp-basics

---

- Same **name**, different **signatures** (parameters—not return type).
- Compiler resolves at **compile time**; improves API ergonomics.
- Use **clear naming intent**; combine with **default arguments** when it simplifies the API.
- Modern C++: prefer **`std::string`**, consider **variadic templates** / **`constexpr`** where appropriate.
