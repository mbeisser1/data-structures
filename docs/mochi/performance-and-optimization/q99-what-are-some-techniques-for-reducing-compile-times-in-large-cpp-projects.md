What are some techniques for reducing compile times in large C++ projects? #q99 #compile-times #performance

---
Long builds hurt iteration. Attack **include graph**, **template bloat**, and **parallelism**.

**High impact:**

- **Forward declarations** in headers
- **Minimal includes** in `.h` — rest in `.cpp`
- **Pimpl** / facades — hide heavy deps
- **Precompiled headers (PCH)** or **C++20 modules**

%%%MOCHI_CARD%%%
What header and template practices speed compilation? #q99 #compile-times #performance

---

- **`#pragma once`** / include guards
- **Explicit template instantiations** in `.cpp` — not every TU
- **`extern template`** for heavy templates:

```cpp
extern template class std::vector<MyClass>;
```

- Avoid **`auto`** in headers when it pulls unexpected heavy types

%%%MOCHI_CARD%%%
What build-system techniques reduce compile time? #q99 #compile-times #performance

---

- **Parallel builds** — `ninja -j`, `make -j`
- **Unity/jumbo builds** — fewer TUs (trade incremental rebuild)
- **Modules (C++20)** — `import` vs textual `#include`
- **ccache** / **distcc** — cache or distribute compilation

Split targets so changing one module doesn't rebuild everything.

%%%MOCHI_CARD%%%
What design patterns help compile-time isolation? #q99 #compile-times #performance

---

- **Pimpl** — pointer to impl in header, details in `.cpp`
- **Modular libraries** — loose coupling, stable interfaces
- **ODR** discipline — one definition per symbol across TUs
- **`constexpr`/`enum class`** — less runtime code in headers

Analyze includes with **include-what-you-use (IWYU)** or **`clang-include-fixer`**.

%%%MOCHI_CARD%%%
In about 60 seconds, explain reducing compile times. #q99 #compile-times #performance

---

- Cut **header dependencies** — forward declare, Pimpl
- Move **template instantiations** out of headers
- **PCH**, **modules**, **parallel** builds
- Measure include cost — biggest wins are architectural
