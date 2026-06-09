#include <iostream>
#include <map>
#include <chrono>
#include <cmath>
// #include <bits/stdc++.h> 
#include <algorithm>
#include <queue>
#include <functional>
#include <type_traits>
#include <memory>
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <bitset>
// read iterator
// write iterator
// forward iterator
// bidirectional iterator
// random access iterator
// contiguous iterator???

// User-defined literal: 42u8i → std::uint8_t (not a type alias).
constexpr std::uint8_t operator""_u8i(unsigned long long value)
{
    if (value > std::numeric_limits<std::uint8_t>::max())
    {
        throw std::out_of_range("u8i literal out of range");
    }
    return static_cast<std::uint8_t>(value);
}

constexpr std::uint8_t operator""_u8(unsigned long long value)
{
    if(value > std::numeric_limits<std::uint8_t>::max())
    {
        throw std::out_of_range("u8 literal out of range :(");
    }

    return static_cast<std::uint8_t>(value);
}

namespace foo::bar::baz{

template<typename T>
void measureInsertTime(T& c)
{
    auto start = std::chrono::high_resolution_clock::now();
    for(int i =0; i < 10'000; ++i)
    {
        c.insert(c.end(), i);        
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto diff = (end - start).count();
    std::cout << "Time taken: " << diff << " seconds\n";
}

using cb = std::function<void>(int a, int b);

// typedef void (*p)(int,int);

using fp = void(*)(int, int);
using f = void(int, int);

void zoo()
{
    fp lambda = [](int a, int b){};
    f* lambda2 = [](int a, int b){};
}

struct Counter
{
    bool operator()(int n) const
    {
        return n == 1;
    }
};


// void printV(const auto& v)
// {
//     for(auto i : v)
//     {
//          std::cout << i << " ";
//     }
//     std::cout << "\n";
// }


struct Edge
{
    int v1_, v2_;
    Edge(int v1, int v2) : v1_(v1), v2_(v2){};
    
    double length() const
    {
        return std::sqrt((v1_ * v1_) + (v2_ * v2_));
    }

    double length_sq() const
    {
        return (v1_ * v1_) + (v2_ * v2_);
    }

    // template<typename T,
    // std::enable_if_t<std::is_arithmetic_v<T>
    // >
    explicit operator double() const
    {
        return length();
    }

    bool operator<(const Edge& e) const
    {
        return length_sq() < e.length_sq();
    }

    bool operator>(const Edge& e) const
    {
        return !(*this < e);
    }

    bool operator==(const Edge& e) const
    {
        return (v1_ == e.v1_ && v2_ == e.v2_);
    }    

    bool operator!=(const Edge& e) const
    {
        return !(*this == e);
    }

    bool operator>=(const Edge& e) const
    {
        //return (*this == e || *this > e);
        return !(*this < e);
    }

    bool operator<=(const Edge& e) const
    {
        // return (*this == e || *this < e);
        return !(*this > e);
    }    

    bool operator()(const Edge& e1, const Edge& e2) const
    {
        return e1 < e2;
    }

    friend std::ostream& operator<<(std::ostream& os, const Edge& e)
    {
        return os << "(" << e.v1_ << ", " << e.v2_ << ")";
    }
};

template<typename T>
void printPQ(std::priority_queue<T> pq)
{
    std::cout << "ordering: ";
    while(!pq.empty())
    {
        auto t = pq.top();
        std::cout << t << " ";
        pq.pop();
    }
    std::cout << "\n";
}
}
using namespace foo::bar::baz;



struct POD
{
    int x;
    float y;
};

template<typename T,
    typename = std::enable_if_t<std::is_arithmetic_v<T>>,
    typename = std::enable_if_t<std::is_default_constructible_v<T>>
    >
struct Number
{

};


int main()
{
    auto n = Number<int>{};

    static_assert(std::is_trivial_v<POD>, "Not trivial");
    
    auto f = [](int i){};
    std::invoke(f, 1);

    std::bitset<8> bs = {10};
    std::vector<int> v{};
    auto it = std::begin(v);
    // std::unique_ptr<std::initializer_list<int>> f = std::make_unique<std::initializer_list<int>({1,2,3,4});

    // auto start = std::begin(f);
 
    // auto m = std::map<int,std::string>{};

    // for(const auto& [k,v] : m)
    // {

    // }

    // for(auto i : f)
    // {
    //     std::cout << i << " ";
    // }

    auto pq2 = std::priority_queue<Edge>{};
    pq2.emplace(Edge{1,2});
    pq2.emplace(Edge{2,4});

    printPQ(pq2);

    auto e1 = Edge{1,1};
    auto b = (5 < static_cast<double>(e1));

    // auto pq = std::priority_queue<int>{};
    // pq.push(1);
    // pq.push(33);
    // pq.push(32);
    // pq.push(4);
    // pq.push(31);


    auto m = std::map<int, std::string>{};
    // auto result = m.insert({1, "one"});
    // std::cout << "inserted = " << result.second << "\n";
    // std::cout << "value = " << result.first->second << "\n";

    decltype(m)::iterator it{};
    bool inserted;

    std::tie(it, inserted) = m.insert({1, "one"});
    std::cout << std::boolalpha << "inserted = " << inserted << "\n";
    std::cout << "value = " << it->second << "\n";

    constexpr std::uint8_t byte = 255_u8;
    static_assert(std::is_same_v<decltype(byte), const std::uint8_t>);
    std::cout << "byte = " << static_cast<unsigned>(byte) << "\n";

    return 0;
}