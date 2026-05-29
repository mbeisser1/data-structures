Explain the concept of modules in C++20. #q90 #modules #advanced-cpp

---
**Modules** replace **`#include`** with **`import`** — faster builds, clearer boundaries, better encapsulation.

**Benefits over headers:**

- **Faster compilation** — parse once, reuse BMI (built module interface)
- **Stronger encapsulation** — only **`export`**ed names visible
- Fewer **ODR** / macro leakage issues
- Explicit **dependency graph**

%%%MOCHI_CARD%%%
What are module unit types? #q90 #modules #advanced-cpp

---

1. **Primary module interface** — **`export module name;`**
2. **Module implementation unit** — **`module name;`** (no export)
3. **Module partition** — **`export module name:part;`**

Only **`export`** declarations are visible to importers.

%%%MOCHI_CARD%%%
Show module interface, implementation, and usage. How do you export API from a module and consume it from `main`? #q90 #modules #advanced-cpp

---
```cpp
// mymodule.cpp (interface)
export module mymodule;

export int globalVar;
export void someFunction();
export class MyClass {
public:
    void method();
};

// implementation
module mymodule;
int globalVar = 42;
void someFunction() { /* ... */ }
void MyClass::method() { /* ... */ }

// consumer
import mymodule;

int main() {
    someFunction();
    MyClass obj;
    obj.method();
}
```

%%%MOCHI_CARD%%%
What are module partitions and the global module fragment? #q90 #modules #advanced-cpp

---

**Partition** — split a large module:

```cpp
export module mymodule:part;
export void partFunction();
```

Import from primary interface: **`export import :part;`**

**Global module fragment** (legacy headers):

```cpp
module;
#include <legacy_header.h>
export module mymodule;
```

Check **compiler support** — tooling still catching up vs headers.

%%%MOCHI_CARD%%%
In about 60 seconds, explain C++20 modules. #q90 #modules #advanced-cpp

---

- **`export module`** defines API; **`import`** consumes it
- Replaces textual **`#include`** for speed and isolation
- **`export`** controls visibility; partitions split large modules
- Coexists with headers during migration
