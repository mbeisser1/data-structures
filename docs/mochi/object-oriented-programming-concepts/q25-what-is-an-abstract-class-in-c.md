What is an abstract class in C++? #q25 #abstract-class #oop-concepts

---
An **abstract class** is a **base class** that defines a polymorphic **interface** but **cannot be instantiated** on its own — typically via one or more **pure virtual functions**.

%%%MOCHI_CARD%%%
What are the key features of an abstract class? #q25 #abstract-class #oop-concepts

---

- Declares **virtual** functions (often **pure virtual** with **`= 0`**)
- **Not instantiable** until all pure virtuals are implemented in a derived class
- May still have **constructors/destructors** and non-pure virtuals with default behavior

%%%MOCHI_CARD%%%
Show an abstract class example with `Shape` and `Circle`. How can `Shape` mix pure virtuals with a default `printType()`, and how does `Circle` become concrete? #q25 #abstract-class #oop-concepts

---
```cpp
#include <iostream>
#include <numbers>

class Shape {
public:
    virtual ~Shape() = default;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual void printType() const {
        std::cout << "This is a Shape" << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}

    double area() const override {
        return std::numbers::pi * radius * radius;
    }

    double perimeter() const override {
        return 2 * std::numbers::pi * radius;
    }

    void printType() const override {
        std::cout << "This is a Circle" << std::endl;
    }
};

int main() {
    // Shape myShape;  // Error: abstract

    Circle c(5);
    Shape* shape_ptr = &c;
    shape_ptr->printType();
    return 0;
}
```

%%%MOCHI_CARD%%%
What should you remember about abstract classes in modern C++? #q25 #abstract-class #oop-concepts

---

- Can mix **pure** and **non-pure virtual** functions
- Unimplemented pure virtuals in a derived class → derived stays **abstract**
- Use **`override`** on implementations; **`final`** to stop further derivation
- Prefer **`= default`** for trivial destructors when appropriate

%%%MOCHI_CARD%%%
In about 60 seconds, explain abstract classes. #q25 #abstract-class #oop-concepts

---

- Base type with **pure virtuals** → **no direct instantiation**
- Defines **interface**; concrete classes **implement** pure virtuals
- Supports **polymorphism** via base pointers/references
- **`virtual ~Shape`**, **`override`**, optional **`final`**
