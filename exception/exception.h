#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstring>
#include <string>
#include <exception>

class BaseException : public std::exception
{
  public:
    static constexpr auto MAX_SIZE = std::size_t{511U};

    explicit BaseException(const char* msg)
    {
        if (msg != nullptr)
        {
            const auto len = std::min(std::strlen(msg), MAX_SIZE);
            std::copy_n(msg, len, message_.begin());
            message_[len] = '\0';
        }
        else
        {
            message_[0] = '\0';
        }
    }

    explicit BaseException(const std::string& msg) : BaseException(msg.c_str())
    {
      
    }

    const char* what() const noexcept final { return message_.data(); }

  private:
    std::array<char, MAX_SIZE + 1U> message_;
};

class ContainerOverflow : public BaseException
{
  public:
    ContainerOverflow(const char* msg, std::uint64_t max_size, std::uint64_t count)
        : BaseException(msg), max_size_(max_size), count_(count)
    {
    }

    std::uint64_t getMaxSize() const {return max_size_;}
    std::uint64_t getCount() const {return count_;}

  private:
    std::uint64_t max_size_;
    std::uint64_t count_;
};
