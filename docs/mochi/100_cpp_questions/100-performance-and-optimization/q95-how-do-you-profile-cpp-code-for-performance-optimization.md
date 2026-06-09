How do you profile C++ code for performance optimization? #q95 #profiling #performance

---
**Profiling** is a crucial technique for **detailed performance analysis** — identify **bottlenecks** and optimize the **most time-consuming** parts, not guesses.

**Workflow:**

1. Build with **`-g -O2`** (symbols + optimizations)
2. Run under a profiler
3. Fix top functions (algorithm, cache, allocation)
4. Re-profile to verify

%%%MOCHI_CARD%%%
What profiling tools are commonly used? #q95 #profiling #performance

---

- **`gprof`** — GCC, `-pg` flag
- **Valgrind/Callgrind** — call graphs (slow, detailed)
- **`perf`** — Linux sampling (`perf record` / `perf report`)
- **Intel VTune**, **AMD μProf** — hardware counters
- **gperftools** — CPU + heap (`pprof`)

Pick sampling profilers for low overhead on large apps.

%%%MOCHI_CARD%%%
Show basic gprof and perf usage. How do you build and run a profiled binary on Linux? #q95 #profiling #performance

---
```bash
# gprof
g++ -pg -g -O2 app.cpp -o app
./app
gprof app gmon.out > analysis.txt

# perf
perf record ./app
perf report
```

Look for: **self time %**, call chains, cache misses, allocation hotspots.

%%%MOCHI_CARD%%%
What should you look for in profiler output? #q95 #profiling #performance

---

- Functions with highest **exclusive** time
- **Hot loops** — vectorization, unrolling candidates
- **Cache/branch** misses (perf/VTune)
- **Allocations** in inner loops

Integrate profiling in CI for **regression** detection on critical paths.

%%%MOCHI_CARD%%%
In about 60 seconds, explain profiling C++. #q95 #profiling #performance

---

- **Measure first** — `-g -O2`, then profiler
- **`perf`**, **VTune**, **Callgrind** for different depths
- Optimize **top frames**; re-run to confirm
- Profile after real changes, not micro-speculation
