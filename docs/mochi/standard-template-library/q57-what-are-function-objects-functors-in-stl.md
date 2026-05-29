What are function objects (functors) in STL? #q57 #functors #stl

---
A **functor** is a **callable object** — usually a class with **`operator()`** overloaded — passed to STL algorithms.

**STL algorithms accept:**

- Function pointers
- **`std::function`**
- Functors and **lambdas**

Functors can hold **state** between calls.

%%%MOCHI_CARD%%%
What advantages do functors have over function pointers? #q57 #functors #stl

---

- **Statefulness** — member variables persist across invocations
- **Inlining** — compilers often optimize functor calls better than indirect calls
- **Type safety** — no void* or manual casting

**Types:**

- **Class functors** — named structs/classes with `operator()`
- **Lambdas** — anonymous functors (C++11+)

%%%MOCHI_CARD%%%
Show a unary predicate functor with `std::remove_if`. Implement `IsEven` as a callable testing divisibility by 2; remove matching elements from `nums` and erase the tail — output should be `1 3 5 7 9`. #q57 #functors #stl

---
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct IsEven {
    bool operator()(int num) const {
        return num % 2 == 0;
    }
};

int main() {
    std::vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto newEnd = std::remove_if(nums.begin(), nums.end(), IsEven{});
    nums.erase(newEnd, nums.end());

    for (int num : nums) {
        std::cout << num << " ";
    }
    // Output: 1 3 5 7 9
    return 0;
}
```

%%%MOCHI_CARD%%%
Show a stateful functor with `std::transform`. Use `SumWithAccumulator` with a running-total member so in-place transform yields cumulative sums `1 3 6 10 15`. #q57 #functors #stl

---
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

struct SumWithAccumulator {
    int total = 0;

    int operator()(int num) {
        return total += num;
    }
};

int main() {
    std::vector<int> nums {1, 2, 3, 4, 5};

    std::transform(nums.begin(), nums.end(), nums.begin(), SumWithAccumulator{});

    for (int num : nums) {
        std::cout << num << " ";
    }
    // Output: 1 3 6 10 15
    return 0;
}
```

%%%MOCHI_CARD%%%
Show modern C++ functor alternatives. Replace named functors with a lambda predicate, a generic lambda, and CTAD on `std::greater` (no explicit `<int>`). #q57 #functors #stl

---
```cpp
// Lambda (C++11)
auto isEven = [](int num) { return num % 2 == 0; };
auto newEnd = std::remove_if(nums.begin(), nums.end(), isEven);

// Generic lambda (C++14)
auto genericPredicate = [](auto const& item) { return item > 0; };

// CTAD (C++17)
std::greater greater; // instead of std::greater<int>
```

%%%MOCHI_CARD%%%
In about 60 seconds, explain STL functors. #q57 #functors #stl

---

- Objects with **`operator()`** used as algorithm callbacks
- Can carry **state**; often faster than function pointers
- **Lambdas** are inline functors
- **`std::greater`**, custom predicates — same pattern
