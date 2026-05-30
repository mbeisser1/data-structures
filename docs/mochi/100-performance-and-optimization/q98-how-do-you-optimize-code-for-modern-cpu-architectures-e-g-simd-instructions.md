How do you optimize code for modern CPU architectures (e.g., SIMD instructions)? #q98 #simd #performance

---
Optimize for modern CPUs with **data vectorization** (SIMD: SSE, AVX, AVX-512), **loop unrolling**, and **cache optimization** — plus compiler flags like **`-O3 -march=native`** for auto-vectorization and intrinsics for hand-tuned kernels.

%%%MOCHI_CARD%%%
Show SIMD array addition. How do you add two `float` arrays using vector instructions instead of a scalar loop? #q98 #simd #performance

---
```cpp
#include <immintrin.h>

void AddArrays(float* result, const float* arr1, const float* arr2, int size) {
    for (int i = 0; i < size; i += 8) {
        __m256 a = _mm256_loadu_ps(&arr1[i]);
        __m256 b = _mm256_loadu_ps(&arr2[i]);
        __m256 r = _mm256_add_ps(a, b);
        _mm256_storeu_ps(&result[i], r);
    }
}
```

Processes **8 floats** per iteration (256-bit AVX).

%%%MOCHI_CARD%%%
What other CPU optimization techniques complement SIMD? #q98 #simd #performance

---

- **Loop unrolling** — `#pragma unroll(4)` or compiler `-O3`
- **Cache locality** — sequential access, alignment, prefetch
- **Avoid false sharing** on parallel SIMD workers
- **Profile** with VTune / perf — verify vectorization actually happened

Portable libraries: **Eigen**, **xsimd**, **Highway**.

%%%MOCHI_CARD%%%
What compiler flags help vectorization? #q98 #simd #performance

---

- **GCC/Clang:** `-O3`, `-march=native`, `-ffast-math` (careful — breaks IEEE rules)
- **MSVC:** `/O2`, `/arch:AVX2`
- Check reports: `-fopt-info-vec` (GCC), `-Rpass=loop-vectorize` (Clang)

Always **benchmark** — wrong alignment or remainder loops can negate gains.

%%%MOCHI_CARD%%%
In about 60 seconds, explain SIMD optimization. #q98 #simd #performance

---

- **SIMD** = parallel lanes per instruction (AVX, etc.)
- Compiler **auto-vectorizes** loops with `-O3`; intrinsics for control
- Pair with **cache-friendly** memory layout
- Use **portable libs** when targeting multiple CPUs
