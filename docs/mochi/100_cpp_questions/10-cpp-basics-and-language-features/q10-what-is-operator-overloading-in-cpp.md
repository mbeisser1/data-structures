What is operator overloading in C++? #q10 #operator-overloading #cpp-basics

---
**Operator overloading** allows developers to define **custom behaviors** for operators when used with **user-defined types** such as classes and structures — more intuitive, expressive code for custom types.

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

- Maintain **intuitive behavior** consistent with built-in operators.
- Preserve **clear semantics**; implement **efficiently** for hot operations.
- Overload **sparingly**; **document** behavior that deviates from expectations.

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
