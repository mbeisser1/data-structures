How do you use algorithms like `sort`, `find`, and `binary_search` in STL? #q58 #stl-algorithms #stl

---
STL algorithms in **`<algorithm>`** operate on **iterator ranges** `[first, last)`.

**Pattern:**

```cpp
auto result = std::algorithm(first, last, /* optional predicate/value */);
```

Most return an **iterator** to the result position (or `bool` for `binary_search`).

%%%MOCHI_CARD%%%
What sorting and searching algorithms are commonly used? #q58 #stl-algorithms #stl

---

**Sorting**

- **`std::sort`** — general sort, O(n log n) average
- **`std::stable_sort`** — preserves order of equal elements
- **`std::partial_sort`**, **`std::is_sorted`**

**Searching**

- **`std::find`**, **`std::find_if`** — linear search, O(n)
- **`std::binary_search`** — on **sorted** range, O(log n)
- **`std::lower_bound`**, **`std::upper_bound`** — insertion/search boundaries

%%%MOCHI_CARD%%%
Show `sort`, `find`, and `binary_search` on a vector. How do you sort, linear-search for a value, then test membership with binary search? #q58 #stl-algorithms #stl

---
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 2, 8, 10, 1, 3, 6};

    std::sort(numbers.begin(), numbers.end());

    int numToFind = 6;
    auto it = std::find(numbers.begin(), numbers.end(), numToFind);

    if (it != numbers.end()) {
        std::cout << numToFind << " found at index: "
                  << std::distance(numbers.begin(), it) << std::endl;
    }

    int numToSearch = 7;
    bool found = std::binary_search(numbers.begin(), numbers.end(), numToSearch);

    std::cout << numToSearch << (found ? " exists" : " does not exist")
              << " in the sorted vector" << std::endl;

    return 0;
}
```

%%%MOCHI_CARD%%%
How do custom comparators work with STL algorithms? #q58 #stl-algorithms #stl

---
```cpp
std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
    return std::abs(a) < std::abs(b);  // Sort by absolute value
});
```

Pass a **comparator** or **lambda** as the last argument for flexible ordering.

**Remember:** **`binary_search`** requires the range to be sorted with the **same ordering** used for the search.

%%%MOCHI_CARD%%%
In about 60 seconds, explain sort, find, and binary_search. #q58 #stl-algorithms #stl

---

- Algorithms take **iterator ranges**
- **`sort`** then **`binary_search`** on sorted data — O(log n) lookup
- **`find`** works on unsorted data — O(n)
- Custom **comparators** control sort order; match comparator for binary search
