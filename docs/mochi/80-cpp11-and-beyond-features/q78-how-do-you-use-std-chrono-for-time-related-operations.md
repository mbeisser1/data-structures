How do you use `std::chrono` for time-related operations? #q78 #std-chrono #cpp11-beyond

---
**`std::chrono`** is C++’s standard library for **time-related operations** — a **robust, type-safe, hardware-independent** way to work with durations, time points, and clocks.

**Three clocks:**

- **`system_clock`** — wall-clock time (can jump with DST/NTP)
- **`steady_clock`** — monotonic, for **elapsed** measurements
- **`high_resolution_clock`** — alias to one of the above

%%%MOCHI_CARD%%%
What are durations and time points in `std::chrono`? #q78 #std-chrono #cpp11-beyond

---

**Duration** — time interval, e.g. `std::chrono::milliseconds(500)`

**Time point** — instant on a clock, e.g. `steady_clock::now()`

Subtract time points → **duration**. Use **`duration_cast`** to convert units.

%%%MOCHI_CARD%%%
Show measuring elapsed time. How do you time an operation with `steady_clock`? #q78 #std-chrono #cpp11-beyond

---
```cpp
auto start = std::chrono::steady_clock::now();
// ... operation ...
auto end = std::chrono::steady_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
std::cout << "Time taken: " << duration.count() << " ms" << std::endl;
```

%%%MOCHI_CARD%%%
Show sleeping and printing current time. How do you pause a thread and read wall-clock time? #q78 #std-chrono #cpp11-beyond

---
```cpp
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

int main() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current time: "
              << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S")
              << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    auto later = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = later - now;
    std::cout << "Elapsed: " << elapsed.count() << "s" << std::endl;

    return 0;
}
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain `std::chrono`. #q78 #std-chrono #cpp11-beyond

---

- **Clocks**, **durations**, **time_points** — compile-time unit safety
- **`steady_clock`** for timing; **`system_clock`** for calendar time
- **`duration_cast`** converts units; **`sleep_for`** blocks threads
- Prefer chrono over raw **`sleep()`** / **`clock()`**
