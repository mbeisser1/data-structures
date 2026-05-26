#ifndef ALT_TYPES_ALT_VECTOR_ALT_VECTOR_H
#define ALT_TYPES_ALT_VECTOR_ALT_VECTOR_H

#include <array>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <type_traits>
#include <utility>

#include "exception/exception.h"
#include "span.h"

namespace alt {
namespace types {

/// @brief A fixed-capacity, vector-like container that conforms to the standard layout and
/// trivially copyable constraints.
///
/// AltVector provides a statically allocated buffer for up to @c MAX_SIZE elements of type
/// @c T , without default-initializing the entire storage on construction. Elements are only
/// constructed when explicitly added (i.e., via @c push_back() , @c assign() , etc.).
///
/// @tparam T The element type. Must be standard layout, trivially copyable and trivially
/// destructible.
/// @tparam MAX_SIZE The maximum number of elements the container can hold.
template <typename T,
          std::size_t MAX_SIZE,
          std::enable_if_t<(MAX_SIZE > 0U), bool> = true,
          std::enable_if_t<std::is_standard_layout<T>::value, bool> = true,
          std::enable_if_t<std::is_trivially_copyable<T>::value, bool> = true>
class AltVector
{
    public:
    template <typename U, std::size_t MAX_CAPACITY>
    struct AlignedStorage
    {
        using value_type = U;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using iterator = pointer;
        using const_iterator = const_pointer;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

        alignas(value_type) std::uint8_t data_[sizeof(value_type) * MAX_CAPACITY];

        pointer data() noexcept { return reinterpret_cast<pointer>(&data_[0]); }
        const_pointer data() const noexcept { return reinterpret_cast<const_pointer>(&data_[0]); }

        reference front() noexcept { return *data(); }
        const_reference front() const noexcept { return *data(); }

        iterator begin() noexcept { return data(); }
        const_iterator begin() const noexcept { return data(); }
    };

    using StorageType = AlignedStorage<T, MAX_SIZE>;

    using value_type = typename StorageType::value_type;
    using size_type = typename StorageType::size_type;
    using difference_type = typename StorageType::difference_type;
    using reference = typename StorageType::reference;
    using const_reference = typename StorageType::const_reference;
    using pointer = typename StorageType::pointer;
    using const_pointer = typename StorageType::const_pointer;
    using iterator = typename StorageType::iterator;
    using const_iterator = typename StorageType::const_iterator;
    using reverse_iterator = typename StorageType::reverse_iterator;
    using const_reverse_iterator = typename StorageType::const_reverse_iterator;

    // not part of the standard, but useful for rvalue references
    using rvalue_reference = value_type&&;

    // clang-format off
    static constexpr auto IS_RI_NOEXCEPT  = std::is_nothrow_constructible<reverse_iterator, iterator>::value;
    static constexpr auto IS_CRI_NOEXCEPT = std::is_nothrow_constructible<const_reverse_iterator, const_iterator>::value;
    // clang-format on

    /// Sole constructor that does not zero-initialize memory.
    // NOLINTNEXTLINE(hicpp-use-equals-default,modernize-use-equals-default)
    constexpr explicit AltVector() noexcept {}

    /////////////////////////////////////////////////////////////////////////////////////////////////
    // Runtime assignment
    void assign(const size_type count, const value_type& value)
    {
        if (count > MAX_SIZE)
        {
            throw ContainerOverflow{"alt_vector::assign", static_cast<std::uint64_t>(MAX_SIZE),
                                    static_cast<std::uint64_t>(count)};
        }
        clear();
        for (size_type i{0U}; i < count; ++i)
        {
            appendUnsafe(value);
        }
    }

    template <class InputIt>
    void assign(const InputIt first, const InputIt last)
    {
        const auto dist = std::distance(first, last);
        if (dist > static_cast<difference_type>(MAX_SIZE))
        {
            throw ContainerOverflow{"alt_vector::assign", static_cast<std::uint64_t>(MAX_SIZE),
                                    static_cast<std::uint64_t>(dist)};
        }
        clear();
        for (InputIt it = first; it != last; ++it)
        {
            appendUnsafe(*it);
        }
    }

    void assign(std::initializer_list<value_type> ilist)
    {
        if (ilist.size() > MAX_SIZE)
        {
            throw ContainerOverflow{"alt_vector::assign", static_cast<std::uint64_t>(MAX_SIZE),
                                    static_cast<std::uint64_t>(ilist.size())};
        }
        clear();
        for (auto&& value : ilist)
        {
            appendUnsafe(value);
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    // pointer access
    pointer data() noexcept { return data_.data(); }
    const_pointer data() const noexcept { return data_.data(); }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    // pointer like access
    tcb::span<value_type> view() noexcept { return tcb::span<value_type>(data_.data(), size_); }

    tcb::span<const value_type> view() const noexcept
    {
        return tcb::span<const value_type>(data_.data(), size_);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    // Checked indexing
    reference at(const size_type pos)
    {
        if (pos >= size_)
        {
            throw ContainerOverflow{"alt_vector::at", static_cast<std::uint64_t>(MAX_SIZE),
                                    static_cast<std::uint64_t>(pos + 1U)};
        }

        return *std::next(begin(), static_cast<difference_type>(pos));
    }

    const_reference at(const size_type pos) const
    {
        if (pos >= size_)
        {
            throw ContainerOverflow{"alt_vector::at const", static_cast<std::uint64_t>(MAX_SIZE),
                                    static_cast<std::uint64_t>(pos + 1U)};
        }

        return *std::next(begin(), static_cast<difference_type>(pos));
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    // clang-format off
  reference front() { return data_.front(); }
  const_reference front() const { return data_.front(); }

  reference back() { return *rbegin(); }
  const_reference back() const { return *rbegin(); }

  iterator begin() noexcept { return data_.begin(); }
  const_iterator begin() const noexcept { return data_.begin(); }
  const_iterator cbegin() const noexcept { return begin(); }

  iterator
  end() noexcept(noexcept(std::next(std::declval<iterator>(), std::declval<difference_type>())))
  {
    return std::next(data_.begin(), static_cast<difference_type>(size_));
  }
  const_iterator
  end() const noexcept(noexcept(std::next(std::declval<const_iterator>(), std::declval<difference_type>())))
  {
    return std::next(data_.begin(), static_cast<difference_type>(size_));
  }
  const_iterator
  cend() const noexcept(noexcept(end()))
  {
    return end();
  }

  reverse_iterator rbegin() noexcept(IS_RI_NOEXCEPT) { return reverse_iterator{end()}; }
  const_reverse_iterator rbegin() const noexcept(IS_CRI_NOEXCEPT) { return const_reverse_iterator{end()}; }
  const_reverse_iterator crbegin() const noexcept(IS_CRI_NOEXCEPT) { return rbegin(); }

  reverse_iterator rend() noexcept(IS_RI_NOEXCEPT) { return reverse_iterator{begin()}; }
  const_reverse_iterator rend() const noexcept(IS_CRI_NOEXCEPT) { return const_reverse_iterator{begin()}; }
  const_reverse_iterator crend() const noexcept(IS_RI_NOEXCEPT) { return rend(); }
    // clang-format on

    /////////////////////////////////////////////////////////////////////////////////////////////////
    // NOLINTNEXTLINE(readability-identifier-naming):P0003
    static constexpr size_type max_size() noexcept { return MAX_SIZE; }
    static constexpr size_type capacity() noexcept { return MAX_SIZE; }

    bool empty() const noexcept { return size_ == 0U; }

    size_type size() const noexcept { return size_; }

    void reserve(const size_type new_cap)
    {
        if (new_cap > MAX_SIZE)
        {
            throw ContainerOverflow{"alt_vector::reserve", static_cast<std::uint64_t>(MAX_SIZE),
                                    static_cast<std::uint64_t>(new_cap)};
        }
        // No-op since we already have the maximum capacity reserved
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    void clear() noexcept
    {
        static_assert(std::is_trivially_destructible<value_type>::value,
                      "value_type must be trivially destructible");
        size_ = 0U;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    void resize(const size_type count)
    {
        if (count > MAX_SIZE)
        {
            throw ContainerOverflow{"alt_vector::resize", static_cast<std::uint64_t>(MAX_SIZE),
                                    static_cast<std::uint64_t>(count)};
        }

        // If count is less than the current size, destroy the extra elements
        while (size_ > count)
        {
            pop_back();
        }

        // If count is more than the current size, default construct the new elements
        while (size_ < count)
        {
            appendUnsafe(value_type{});
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    void resize(const size_type count, const_reference value)
    {
        if (count > MAX_SIZE)
        {
            throw ContainerOverflow{"alt_vector::resize", static_cast<std::uint64_t>(MAX_SIZE),
                                    static_cast<std::uint64_t>(count)};
        }

        // If count is less than the current size, destroy the extra elements
        while (size_ > count)
        {
            pop_back();
        }

        // If count is more than the current size, copy construct the new elements with the given
        // value
        while (size_ < count)
        {
            push_back(value);
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    // NOLINTNEXTLINE(readability-identifier-naming):P0003
    void push_back(const_reference value)
    {
        if (size_ == MAX_SIZE)
        {
            throw ContainerOverflow{"alt_vector::push_back", static_cast<std::uint64_t>(MAX_SIZE),
                                    static_cast<std::uint64_t>(MAX_SIZE + 1U)};
        }
        appendUnsafe(value);
    }

    // NOLINTNEXTLINE(readability-identifier-naming):P0003
    void push_back(rvalue_reference value)
    {
        if (size_ == MAX_SIZE)
        {
            throw ContainerOverflow{"alt_vector::push_back(T&&)", static_cast<std::uint64_t>(MAX_SIZE),
                                    static_cast<std::uint64_t>(MAX_SIZE + 1U)};
        }
        appendUnsafe(std::move(value));
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    template <class... Args>
    // NOLINTNEXTLINE(readability-identifier-naming):P0003
    void emplace_back(Args&&... args)
    {
        if (size_ == MAX_SIZE)
        {
            throw ContainerOverflow{"alt_vector::emplace_back", static_cast<std::uint64_t>(MAX_SIZE),
                                    static_cast<std::uint64_t>(MAX_SIZE + 1U)};
        }

        // Variadic template required to forwards arguments to the constructor of value_type
        appendUnsafe(std::forward<Args>(args)...);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    // NOLINTNEXTLINE(readability-identifier-naming):P0003
    void pop_back() noexcept
    {
        static_assert(std::is_trivially_destructible<value_type>::value,
                      "value_type must be trivially destructible");
        if (size_ > 0U)
        {
            --size_;
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    void erase(iterator const pos)
    {
        const auto is_invalid_beginning = std::less<iterator>()(pos, begin());
        const auto is_invalid_end = !std::less<iterator>()(pos, end());

        if (is_invalid_beginning || is_invalid_end)
        {
            const auto distance = std::distance(begin(), pos);
            throw BaseException{"alt_vector::erase: distance out of range"};
        }

        std::ignore = std::move(std::next(pos, 1), end(), pos);

        // Destroy the now-invalid last element
        pop_back();
    }

    bool isEqual(const AltVector& other) const noexcept
    {
        if (this == &other)
        {
            return true;
        }

        if (size_ != other.size_)
        {
            return false;
        }

        for (size_type i{0U}; i < size_; ++i)
        {
            if (data_.data()[i] != other.data_.data()[i])
            {
                return false;
            }
        }

        return true;
    }

    private:
    void appendUnsafe(const_reference value) noexcept(false)
    {
        (void)new (end()) value_type{value};
        ++size_;
    }

    void appendUnsafe(rvalue_reference value) noexcept(false)
    {
        (void)new (end()) value_type{value};
        ++size_;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////
    size_type size_{0U};
    StorageType data_;
};

///////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, std::size_t MAX_SIZE>
bool operator==(const AltVector<T, MAX_SIZE>& lhs, const AltVector<T, MAX_SIZE>& rhs) noexcept
{
    return lhs.isEqual(rhs);
}

template <typename T, std::size_t MAX_SIZE>
bool operator!=(const AltVector<T, MAX_SIZE>& lhs, const AltVector<T, MAX_SIZE>& rhs) noexcept
{
    return !(lhs == rhs);
}

} // namespace types
} // namespace alt

#endif
