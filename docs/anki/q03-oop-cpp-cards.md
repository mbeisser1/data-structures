# Question 3 — Object-oriented programming in C++ (study cards)

Synthesized from [`questions.md`](../questions.md) — `### 3. What is *object-oriented programming* in *C++*?`  
Deck: `CPP::01-Basics` · Tags: `q03`, `oop`

---

## Card 1 — Main question (summary)

**Front:** What is object-oriented programming (OOP) in C++?

**Back:** **Object-oriented programming** organizes code into reusable, self-contained **objects**. Each object combines **data** (attributes) and **methods** (behaviors that use that data), instead of scattering state and logic across unrelated functions.

*Source: intro paragraph immediately under `### 3`.*

---

## Card 2 — Four pillars of OOP

**Front:** What are the four pillars of object-oriented programming?

**Back:**

- **Encapsulation** — hide internal state; expose a controlled public interface.
- **Inheritance** — “is-a” relationship; derived types reuse/extend base behavior.
- **Polymorphism** — treat objects as their base type while keeping specialized behavior.
- **Abstraction** — focus on what something does, not every implementation detail.

---

## Card 3 — Classes and objects

**Front:** What is the relationship between a class and an object in C++?

**Back:** A **`class`** is the **blueprint**; an **object** is a **specific instance** created from that class (with its own data).

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

---

## Card 4 — Inheritance

**Front:** How does C++ support inheritance?

**Back:** C++ supports **single** and **multiple** inheritance. A derived class can extend a base class and reuse its constructors/members (here, `ElectricCar` extends `Car`).

```cpp
class ElectricCar : public Car {
private:
    int batteryCapacity;

public:
    ElectricCar(std::string m, int y, int bc) : Car(m, y), batteryCapacity(bc) {}
};
```

---

## Card 5 — Polymorphism

**Front:** What kinds of polymorphism does C++ support?

**Back:**

- **Compile-time** — function overloading, templates.
- **Run-time** — **virtual functions** (e.g. pure virtual `start()` overridden in `Car`).

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

---

## Card 6 — Encapsulation

**Front:** How does C++ implement encapsulation?

**Back:** With **access specifiers** — `public`, `private`, `protected` — so internal data (e.g. `balance`) is hidden and only safe operations (`deposit`) are exposed.

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

---

## Card 7 — Abstraction

**Front:** How do you create abstraction in C++?

**Back:** Use **abstract classes** / interfaces via **pure virtual functions** (`= 0`). Concrete types (e.g. `Circle`) **override** and supply implementation.

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

---

## Card 8 — Modern C++ and OOP

**Front:** What modern C++ features complement classic OOP?

**Back:**

- **Smart pointers** — `unique_ptr`, `shared_ptr`, `weak_ptr` for ownership and lifetime
- **Move semantics** — efficient resource transfer between objects
- **Lambdas** — inline function objects for flexible callbacks and algorithms
- **Concepts (C++20)** — constraints on templates for clearer errors and safer generics

---

## Card 9 — Interview synthesis

**Front:** In about 60 seconds, what is OOP in C++?

**Back:**

- **Objects** bundle data + behavior; **classes** define object shape.
- **Four pillars:** encapsulation, inheritance, polymorphism, abstraction.
- **C++ mechanisms:** access specifiers, virtual functions, pure virtual / abstract classes, single & multiple inheritance.
- **Modern helpers:** smart pointers, moves, lambdas, concepts.
