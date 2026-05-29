How do you optimize memory usage in C++ programs? #q92 #memory-optimization #performance

---
Memory optimization combines **storage choice**, **smart pointers**, **pools**, and **right data structures**.

**Storage classes:**

- **Automatic** — stack, scope-limited
- **Static** — program lifetime
- **`thread_local`** — per-thread instance
- **Dynamic** — heap; minimize and manage with RAII

%%%MOCHI_CARD%%%
What tools reduce dynamic memory overhead? #q92 #memory-optimization #performance

---

**Smart pointers**

- **`unique_ptr`** — single owner, default choice
- **`shared_ptr`** — shared ownership when needed

**Memory pools / PMR**

```cpp
std::array<std::byte, 1024> buffer;
std::pmr::monotonic_buffer_resource mbr{buffer.data(), buffer.size()};
std::pmr::vector<int> vec{&mbr};
```

Reuse allocations for short-lived objects; arena frees in bulk.

%%%MOCHI_CARD%%%
What data structure and technique choices save memory? #q92 #memory-optimization #performance

---

- **`unordered_map`** — fast, more memory
- **`map`/`set`** — tree, balanced memory
- **Move semantics** — avoid copying large buffers
- **SSO** — small strings often stack-backed in libstdc++/libc++
- **Memory-mapped files** — large data without full RAM load

Pick structure by access pattern, not habit.

%%%MOCHI_CARD%%%
How do you find memory bottlenecks? #q92 #memory-optimization #performance

---

- **Valgrind** (massif), **Visual Studio** memory profiler, **heaptrack**
- Watch peak RSS, allocation rate, fragmentation
- Fix leaks first, then reduce allocation churn (pools, reserves, moves)

Measure before micro-optimizing container choice.

%%%MOCHI_CARD%%%
In about 60 seconds, explain memory optimization. #q92 #memory-optimization #performance

---

- Prefer **stack/RAII** over raw **`new`**
- **`unique_ptr`**, **PMR/arenas** for churn
- Right **container** + **move** + **reserve**
- **Profile** heap usage — don't guess
