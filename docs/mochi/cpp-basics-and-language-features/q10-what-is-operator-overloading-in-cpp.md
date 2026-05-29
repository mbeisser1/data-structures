What is operator overloading in C++? #q10 #operator-overloading #cpp-basics

---
**Operator overloading** lets you define how **operators** (`+`, `==`, `<<`, etc.) behave for **user-defined types**, making custom classes read more naturally while keeping type-specific semantics.

%%%MOCHI_CARD%%%
How can operators be overloaded in C++? #q10 #operator-overloading #cpp-basics

---

- **Member function**: `MyClass operator+(const MyClass& other) const { ... }`
- **Non-member** (often **`friend`**): `MyClass operator+(const MyClass& lhs, const MyClass& rhs) { ... }`
- Choose member vs free function based on symmetry and left-hand operand rules (e.g. `<<` often non-member).

%%%MOCHI_CARD%%%
Which operators are commonly overloaded, and which cannot be? #q10 #operator-overloading #cpp-basics

---

**Common:**

- Arithmetic: **`+` `-` `*` `/`**
- Comparisons: **`==` `!=` `<` `>`**
- Assignment: **`=`**
- Stream: **`<<` `>>`**
- Increment: **`++` `--`**
- Subscript: **`[]`**

**Cannot overload:**

- **`.`** (member access)
- **`::`** (scope resolution)
- **`?:`** (ternary)
- **`sizeof`**

You **cannot invent new operators**. **Precedence and arity** stay fixed; built-in types’ operators cannot be replaced.

%%%MOCHI_CARD%%%
Show operator overloading on `Complex`. Store `real` and `imag`, implement `operator+` to add component-wise and return a new `Complex`. #q10 #operator-overloading #cpp-basics

---
```cpp
class Complex {
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};
```

%%%MOCHI_CARD%%%
What are operator overloading best practices? #q10 #operator-overloading #cpp-basics

---

- Match **intuitive** built-in behavior; preserve **clear semantics**.
- Overload **sparingly**; document non-obvious behavior.

%%%MOCHI_CARD%%%
In about 60 seconds, explain operator overloading in C++. #q10 #operator-overloading #cpp-basics

---

- Extend **existing operators** to user types for readable code.
- Implement as **member** or **non-member/friend** depending on the operator.
- **Forbidden operators:**
  - **`.`**
  - **`::`**
  - **`?:`**
  - **`sizeof`**
- Keep behavior **predictable**; don’t change precedence/arity.
