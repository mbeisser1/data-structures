Explain the concept of branch prediction and its impact on performance. #q93 #branch-prediction #performance

---
**Branch prediction** lets the CPU **guess** which way an **`if`/loop branch** goes and **speculatively execute** ahead — keeping the pipeline full.

**Correct prediction** → high throughput  
**Misprediction** → pipeline flush, wasted cycles

%%%MOCHI_CARD%%%
How do CPUs predict branches? #q93 #branch-prediction #performance

---

- **Static** — compile-time heuristics
- **Dynamic** — history-based (two-level adaptive, neural predictors)

Predictors learn **patterns** (e.g. mostly-positive loop). **Random/unpredictable** branches hurt most.

%%%MOCHI_CARD%%%
Show a branch-heavy loop. #q93 #branch-prediction #performance

---
```cpp
int sum_positive(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        if (num > 0) {  // predictor learns if data is skewed
            sum += num;
        }
    }
    return sum;
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
