What is object-oriented programming (OOP) in C++? #q03 #oop

---
**Object-oriented programming (OOP)** organizes code into reusable, self-contained **objects**. Each object groups **data attributes** (characteristics) and **methods** (behaviors) that operate on that data.

%%%MOCHI_CARD%%%
What are the four pillars of object-oriented programming? #q03 #oop

---

- **Encapsulation** — objects hide internal state and behavior; expose a controlled public interface.
- **Inheritance** — “is-a” relationship; derived objects access attributes and behaviors of a base class.
- **Polymorphism** — objects treated as instances of a parent type while exhibiting their own behavior.
- **Abstraction** — simplify complex systems by focusing on high-level actions while hiding implementation details.

%%%MOCHI_CARD%%%
What is the relationship between a class and an object in C++? #q03 #oop

---
A **`class`** is the **blueprint**; an **object** is a **specific instance** created from that class (with its own data).

%%%MOCHI_CARD%%%
Show a class and object example. Define `Car` with private `model`/`year`, a constructor, and `display()`; in `main`, create `Car myCar("Tesla", 2023)` and call `display()`. #q03 #oop

---
```cpp
class Car {
private:
    std::string model;
    int year;

public:
    Car(std::string m, int y) : model(m), year(y) {}
    void display() {
        std::cout << year << " " << model << std::endl;
    }
};

int main() {
    Car myCar("Tesla", 2023);
    myCar.display();
    return 0;
}
```

%%%MOCHI_CARD%%%
How does C++ support inheritance? #q03 #oop

---
C++ supports **single** and **multiple** inheritance. A derived class can extend a base class and reuse its constructors/members (here, `ElectricCar` extends `Car`).

%%%MOCHI_CARD%%%
Show single inheritance in C++. Derive `ElectricCar` from `Car`, add `batteryCapacity`, and chain to the base constructor with `Car(m, y)` in the member initializer list. #q03 #oop

---
```cpp
class ElectricCar : public Car {
private:
    int batteryCapacity;

public:
    ElectricCar(std::string m, int y, int bc) : Car(m, y), batteryCapacity(bc) {}
};
```

%%%MOCHI_CARD%%%
What kinds of polymorphism does C++ support? #q03 #oop

---

- **Compile-time** — function overloading, templates.
- **Run-time** — **virtual functions** (e.g. pure virtual `start()` overridden in `Car`).

%%%MOCHI_CARD%%%
Show runtime polymorphism with pure virtual functions. Define abstract `Vehicle` with pure virtual `start()`, override in `Car`, and print when started. #q03 #oop

---
```cpp
class Vehicle {
public:
    virtual void start() = 0;  // Pure virtual function
};

class Car : public Vehicle {
public:
    void start() override {
        std::cout << "Car started" << std::endl;
    }
};
```

%%%MOCHI_CARD%%%
How does C++ implement encapsulation? #q03 #oop

---
With **access specifiers**:

- **`public`**
- **`private`**
- **`protected`**

Internal data (e.g. `balance`) stays hidden; only safe operations (e.g. `deposit`) are exposed.

%%%MOCHI_CARD%%%
Show encapsulation with access specifiers. In `BankAccount`, keep `balance` private and expose `deposit` that only adds positive amounts. #q03 #oop

---
```cpp
class BankAccount {
private:
    double balance;

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
};
```

%%%MOCHI_CARD%%%
How do you create abstraction in C++? #q03 #oop

---
Use **abstract classes** / interfaces via **pure virtual functions** (`= 0`). Concrete types (e.g. `Circle`) **override** and supply implementation.

%%%MOCHI_CARD%%%
Show abstraction with an abstract base class. Define `Shape` with pure virtual `area()`, implement `Circle` with radius and a π·r² override. #q03 #oop

---
```cpp
class Shape {
public:
    virtual double area() = 0;  // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double area() override {
        return M_PI * radius * radius;
    }
};
```

%%%MOCHI_CARD%%%
What modern C++ features complement classic OOP? #q03 #oop

---

- **Smart pointers** for ownership and lifetime:
  - **`unique_ptr`**
  - **`shared_ptr`**
  - **`weak_ptr`**
- **Move semantics** — efficient resource transfer between objects
- **Lambdas** — inline function objects for flexible callbacks and algorithms
- **Concepts (C++20)** — constraints on templates for clearer errors and safer generics

%%%MOCHI_CARD%%%
In about 60 seconds, what is OOP in C++? #q03 #oop

---

- **Four pillars:**
  - **Encapsulation**
  - **Inheritance**
  - **Polymorphism**
  - **Abstraction**
- **C++ mechanisms:**
  - **Access specifiers**
  - **Virtual functions**
  - **Pure virtual / abstract classes**
  - **Single & multiple inheritance**
- **Modern helpers:**
  - **Smart pointers**
  - **Move semantics**
  - **Lambdas**
  - **Concepts**
