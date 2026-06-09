What is a pure virtual function? #q24 #pure-virtual #oop-concepts

---
A **pure virtual function** is a **virtual member function** in a base class with **no implementation**, declared with **`= 0`**. It is meant to be **overridden by derived classes** — a key tool for abstract classes and interfaces.

%%%MOCHI_CARD%%%
What is the syntax for a pure virtual function? #q24 #pure-virtual #oop-concepts

---

Declare with **`virtual`**, a return type and name, parameter list, and **`= 0`** — no function body in the class definition.

%%%MOCHI_CARD%%%
Show pure virtual function syntax. How do you declare a function in a base class that derived types must implement? #q24 #pure-virtual #oop-concepts

---
```cpp
class Base {
public:
    virtual void pureVirtualFunction() = 0;
};
```

%%%MOCHI_CARD%%%
What are key characteristics and use cases of pure virtual functions? #q24 #pure-virtual #oop-concepts

---

**Characteristics:**

- **No implementation** in the base class (a separate body is still allowed in some cases)
- A class with at least one pure virtual becomes an **abstract class**
- Derived classes must override **all** pure virtuals to be instantiable

**Use cases:**

- **Define interfaces** — contract for derived classes
- **Run-time polymorphism** — via abstract base pointers
- **Template method pattern** — algorithm skeleton in base, steps in derived classes

%%%MOCHI_CARD%%%
Show pure virtual functions with `Shape`, `Circle`, and `Rectangle`. How do you store different shapes and call `draw()` and `area()` polymorphically? #q24 #pure-virtual #oop-concepts

---
```cpp
#include <iostream>
#include <vector>
#include <memory>

class Shape {
public:
    virtual double area() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void draw() const override {
        std::cout << "Drawing a circle\n";
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void draw() const override {
        std::cout << "Drawing a rectangle\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5));
    shapes.push_back(std::make_unique<Rectangle>(4, 6));

    for (const auto& shape : shapes) {
        shape->draw();
        std::cout << "Area: " << shape->area() << std::endl;
    }
    return 0;
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain pure virtual functions. #q24 #pure-virtual #oop-concepts

---

- Declared **`virtual ... = 0`**
- Makes class **abstract**; derived must override all pure virtuals to instantiate
- A pure virtual may still have a **default implementation** elsewhere, but **`= 0`** keeps it pure
- Always use a **`virtual` destructor** in polymorphic bases
