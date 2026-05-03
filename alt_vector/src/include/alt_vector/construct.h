#ifndef ALT_TYPES_ALT_VECTOR_CONSTRUCT_H
#define ALT_TYPES_ALT_VECTOR_CONSTRUCT_H

#include "alt_vector.h"

namespace alt {
namespace types {

// Factory functions to create AltVector instances
template <std::size_t Capacity, typename InputIt>
AltVector<typename std::iterator_traits<InputIt>::value_type, Capacity>
makeAltVector(const InputIt first, const InputIt last)
{
  using T = typename std::iterator_traits<InputIt>::value_type;
  AltVector<T, Capacity> vec;
  vec.assign(first, last);
  return vec;
}

// Specify type and capacity
// makeAltVector<bool, 4>({})
template <typename T, std::size_t Capacity>
AltVector<T, Capacity> makeAltVector(const std::initializer_list<T> list)
{
  AltVector<T, Capacity> vec;
  vec.assign(list.begin(), list.end());
  return vec;
}

// Specify only capacity.
// makeAltVector<4>({true, false})
template <std::size_t Capacity, typename T>
AltVector<T, Capacity> makeAltVector(const std::initializer_list<T> list)
{
  return makeAltVector<T, Capacity>(list);
}

} // namespace types
} // namespace alt

#endif
