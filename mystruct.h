#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <tuple>

class MyStruct
{
    public:
    // not "my string", want a proper string
    explicit MyStruct(const std::string& s, int i)
        : s_{s}, i_raw_{new int(i)}, i_{std::make_unique<int>(i)}
    {
    }

    // destructor
    ~MyStruct() { delete i_raw_; }

    // copy constructor
    MyStruct(const MyStruct& other)
    {
        s_ = other.s_;

        if (other.i_raw_ == nullptr)
        {
            i_raw_ = nullptr;
        }
        else
        {
            i_raw_ = new int(*(other.i_raw_));
        }

        if (other.i_ == nullptr)
        {
            i_ = nullptr;
        }
        else
        {
            i_ = std::make_unique<int>(*(other.i_));
        }
    }

    // Move constructor
    MyStruct(MyStruct&& other) noexcept
        : s_{std::move(other.s_)}, i_raw_{other.i_raw_}, i_{std::move(other.i_)}
    {
        other.s_.clear();
        other.i_raw_ = nullptr;
        other.i_ = nullptr; // fixed bug
    }

    // Copy assignment
    MyStruct& operator=(MyStruct other)
    {
        // How to do?
        swap(*this, other);

        // if(this != &other)
        // {
        //     s_ = other.s_;

        //     delete i_raw_;
        //     i_raw_ = new int(*(other.i_raw_));

        //     i_ = std::make_unique<int>(*(other.i_));
        // }

        return *this;
    }

    bool operator==(const MyStruct& other) const
    {
        // We check all everytime but that's fine.
        auto ptr_eq = [](const int* a, const int* b) {
            return (a == b) || ((a != nullptr) && (b != nullptr) && (*a == *b));
        };
        auto uptr_eq = [](const std::unique_ptr<int>& a, const std::unique_ptr<int>& b) {
            return (a == b) || ((a != nullptr) && (b != nullptr) && (*a == *b));
        };
        bool is_s_eq = (s_ == other.s_);
        bool is_i_eq = ptr_eq(i_raw_, other.i_raw_);
        bool is_i_raw_eq = uptr_eq(i_, other.i_);
        return is_s_eq && is_i_eq && is_i_raw_eq;
    }

    bool operator!=(const MyStruct& other) const { return !(*this == other); }

    // a < b
    bool operator<(const MyStruct& other) const
    {
        // Moved-from objects may have null pointers — can't use *p blindly.
        // Compare (has value?, value): null → (false, 0), real 0 → (true, 0), so empty ≠ zero.
        auto int_key = [](const int* p) { return std::make_tuple(p != nullptr, p ? *p : 0); };
        auto uptr_key = [](const std::unique_ptr<int>& p) {
            return std::make_tuple(static_cast<bool>(p), p ? *p : 0);
        };
        // make_tuple, not tie: tie only binds lvalues; int_key/uptr_key return temporaries.
        return std::make_tuple(s_, int_key(i_raw_), uptr_key(i_)) <
               std::make_tuple(other.s_, int_key(other.i_raw_), uptr_key(other.i_));
    }

    // a > b ->reverse params
    bool operator>(const MyStruct& other) const { return other < *this; }

    // a <= b
    bool operator<=(const MyStruct& other) const { return !(*this > other); }

    // a >= b
    bool operator>=(const MyStruct& other) const { return !(*this < other); }

    friend void swap(MyStruct& a, MyStruct& b)
    {
        using std::swap;
        std::swap(a.s_, b.s_);
        std::swap(a.i_raw_, b.i_raw_);
        std::swap(a.i_, b.i_);
    }

    private:
    std::string s_{};
    int* i_raw_{nullptr};
    std::unique_ptr<int> i_{};
};
