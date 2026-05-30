Explain the concept of branch prediction and its impact on performance. #q93 #branch-prediction #performance

---
**Branch prediction** is a **hardware optimization** that anticipates the outcome of **conditional branches** — the CPU **speculatively executes** along the predicted path to keep the instruction pipeline full.

**Correct prediction** → high throughput, fewer pipeline stalls  
**Misprediction** → pipeline flush and wasted cycles

%%%MOCHI_CARD%%%
How do CPUs predict branches? #q93 #branch-prediction #performance

---

- **Static** — compile-time heuristics
- **Dynamic** — history-based (two-level adaptive, neural predictors)

Predictors learn **patterns** (e.g. mostly-positive loop). **Random/unpredictable** branches hurt most.

%%%MOCHI_CARD%%%
Show a branch-heavy loop. How does an `if` inside a hot loop over a `vector` interact with the branch predictor? #q93 #branch-prediction #performance

---
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int sum_positive(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        if (num > 0) {
            sum += num;
        }
    }
    return sum;
}

int main() {
    std::vector<int> data(1000000);
    std::generate(data.begin(), data.end(), []() { return rand() % 100 - 25; });
    std::cout << sum_positive(data) << std::endl;
    return 0;
}
```

Sorted or biased data → easier to predict than random 50/50 splits.

%%%MOCHI_CARD%%%
How can you optimize for branch prediction? #q93 #branch-prediction #performance

---

- **Sort/partition** data so branches are predictable
- **`[[likely]]`/`[[unlikely]]`** (C++20) — hint hot path
- **Branchless code** — cmov, lookup tables, bitmask tricks in hot loops
- **Reduce branches** in inner loops — SIMD, predication where available

Profile first — not every branch matters.

%%%MOCHI_CARD%%%
In about 60 seconds, explain branch prediction. #q93 #branch-prediction #performance

---

- CPU **speculates** on branches before condition known
- **Mispredict** = expensive flush
- Make hot paths **predictable** or **branchless**
- Random branches in tight loops are a common perf hit
