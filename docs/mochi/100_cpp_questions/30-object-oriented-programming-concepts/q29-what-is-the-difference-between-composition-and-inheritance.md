What is the difference between composition and inheritance? #q29 #composition-inheritance #oop-concepts

---
Both establish relationships between classes in OOP:

- **Inheritance** — **“is-a”**: a derived class **is a kind of** the base (e.g. every `Square` is a `Rectangle`)
- **Composition** — **“has-a”**: one class **contains** another (e.g. a `Car` **has an** `Engine`)

**Favor composition over inheritance** when you want looser coupling and more flexible, maintainable designs.

%%%MOCHI_CARD%%%
Show inheritance (“is-a”) with `Animal` and `Lion`. How does `Lion` specialize `Animal` behavior and add its own method? #q29 #composition-inheritance #oop-concepts

---
```cpp
class Animal {
public:
    virtual void eat() { std::cout << "Nom nom nom\n"; }
};

class Lion : public Animal {
public:
    void roam() { std::cout << "Roaming the savannah\n"; }
    void eat() override { std::cout << "Lion eating meat\n"; }
};
```

%%%MOCHI_CARD%%%
Show composition (“has-a”) with `Car` and `Engine`. How does `Car` own an `Engine` and delegate `start()`? #q29 #composition-inheritance #oop-concepts

---
```cpp
#include <memory>
#include <iostream>

class Engine {
public:
    void start() { std::cout << "Engine started\n"; }
};

class Car {
    std::unique_ptr<Engine> engine;

public:
    Car() : engine(std::make_unique<Engine>()) {}
    void start() { engine->start(); }
};
```

%%%MOCHI_CARD%%%
Compare composition and inheritance. #q29 #composition-inheritance #oop-concepts

---

| | **Inheritance** | **Composition** |
| --- | --- | --- |
| Relationship | **Is-a** | **Has-a** |
| Coupling | Tighter | Looser |
| Flexibility | Less (fixed hierarchy) | More (swap components at run time) |
| Code reuse | Through base-class implementation | Through composed objects |

%%%MOCHI_CARD%%%
In about 60 seconds, compare composition and inheritance. #q29 #composition-inheritance #oop-concepts

---

- **Inheritance:** **is-a**, tight coupling, override virtuals
- **Composition:** **has-a**, looser coupling, embed/replace parts
- Default bias: **favor composition** for maintainable design
