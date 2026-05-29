What is loop unrolling and when is it beneficial? #q94 #loop-unrolling #performance

---
**Loop unrolling** duplicates loop body work so each iteration handles **multiple elements** — less branch/counter overhead per element.

```cpp
// before
for (int i = 0; i < 4; ++i) { work(i); }

// unrolled (factor 2)
for (int i = 0; i < 4; i += 2) {
    work(i); work(i+1);
}
```

Often done by the **compiler** (`-O2`/`-O3`); manual unroll for hot loops.

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
Show manual unrolling in a sum loop. #q94 #loop-unrolling #performance

---
```cpp
const int SIZE = 100000000;
long long sum = 0;

// Unrolled factor 4
for (int i = 0; i < SIZE; i += 4) {
    sum += data[i] + data[i + 1] + data[i + 2] + data[i + 3];
}
```

Compare with **`std::chrono`** or profilers — measure, don't assume.

Use **PGO** so compiler picks unroll factors from runtime data.

%%%MOCHI_CARD%%%
In about 60 seconds, explain loop unrolling. #q94 #loop-unrolling #performance

---

- Do **more work per loop iteration** — fewer control instructions
- Compiler often unrolls automatically
- Balance **speed vs code size**
- Combine with **vectorization** for numeric hot loops
