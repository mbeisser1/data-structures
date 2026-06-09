What is loop unrolling and when is it beneficial? #q94 #loop-unrolling #performance

---
**Loop unrolling** reduces **loop control overhead** (counters, branches) by executing **multiple iterations’ work** per loop step — improving **CPU pipeline** utilization and enabling better **vectorization**.

Often done by the **compiler**; manual unroll when profiling shows benefit.

%%%MOCHI_CARD%%%
What are benefits and trade-offs of loop unrolling? #q94 #loop-unrolling #performance

---

**Benefits**

- Better **ILP** / pipeline use
- Helps **auto-vectorization**
- Fewer branch checks per element

**Trade-offs**

- **Code bloat** — I-cache pressure
- Harder to read if manual
- Unroll factor fixed at compile time

Moderate factors (**2–4**) often help; excessive unroll can hurt.

%%%MOCHI_CARD%%%
Show manual loop unrolling. How do you sum an array four elements per iteration? #q94 #loop-unrolling #performance

---
```cpp
#include <iostream>
#include <vector>
#include <chrono>

int main() {
    const int SIZE = 100000000;
    std::vector<int> data(SIZE, 1);
    long long sum = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; ++i) {
        sum += data[i];
    }
    auto end = std::chrono::high_resolution_clock::now();
    // ... time original ...

    sum = 0;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i += 4) {
        sum += data[i] + data[i + 1] + data[i + 2] + data[i + 3];
    }
    end = std::chrono::high_resolution_clock::now();
    // ... time unrolled ...
    return 0;
}
```

Compare with **`std::chrono`** or profilers — measure, don't assume.

%%%MOCHI_CARD%%%
In about 60 seconds, explain loop unrolling. #q94 #loop-unrolling #performance

---

- Do **more work per loop iteration** — fewer control instructions
- Compiler often unrolls automatically
- Balance **speed vs code size**
- Combine with **vectorization** for numeric hot loops
