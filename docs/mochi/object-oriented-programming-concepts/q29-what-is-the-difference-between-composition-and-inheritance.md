What is the difference between composition and inheritance? #q29 #composition-inheritance #oop-concepts

---
Both model relationships between classes:

- **Inheritance** — **“is-a”** (specialization)
- **Composition** — **“has-a”** (containment)

**Favor composition over inheritance** when you need flexibility and looser coupling.

%%%MOCHI_CARD%%%
Show inheritance (“is-a”) with `Animal` and `Lion`. #q29 #composition-inheritance #oop-concepts

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

- `Lion` **is an** `Animal` — inherits interface and can override behavior

%%%MOCHI_CARD%%%
Show composition (“has-a”) with `Car` and `Engine`. #q29 #composition-inheritance #oop-concepts

---
```cpp
#include <memory>

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

- `Car` **has an** `Engine` — engine lifetime tied to the car

%%%MOCHI_CARD%%%
Compare composition and inheritance. #q29 #composition-inheritance #oop-concepts

---

| | **Inheritance** | **Composition** |
| --- | --- | --- |
| Relationship | **Is-a** | **Has-a** |
| Coupling | Tighter | Looser |
| Flexibility | Less (fixed hierarchy) | More (swap components) |
| Reuse | Via base implementation | Via embedded objects |

%%%MOCHI_CARD%%%
In about 60 seconds, compare composition and inheritance. #q29 #composition-inheritance #oop-concepts

---

- **Inheritance:** **is-a**, tight coupling, override virtuals
- **Composition:** **has-a**, looser coupling, embed/replace parts
- Default bias: **favor composition** for maintainable design
