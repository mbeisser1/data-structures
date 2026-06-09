#include <catch2/catch_all.hpp>

#include "mystruct.h"

#include <set>
#include <utility>

TEST_CASE("MyStruct equality compares string and pointer values")
{
    const MyStruct a("abc", 1);
    const MyStruct b("abc", 1);
    const MyStruct c("abd", 1);

    CHECK(a == b);
    CHECK_FALSE(a == c);
}

TEST_CASE("MyStruct ordering is null-safe and lexicographic")
{
    const MyStruct with_value("x", 5);
    MyStruct emptied("y", 9);
    const MyStruct holder(std::move(emptied));

    CHECK(with_value < MyStruct("y", 5));
    CHECK(emptied < with_value);
    CHECK(holder == MyStruct("y", 9));
}

TEST_CASE("MyStruct works in ordered containers")
{
    std::set<MyStruct> values{
        MyStruct("b", 2),
        MyStruct("a", 1),
        MyStruct("a", 2),
    };

    CHECK(values.size() == 3);
    CHECK((*values.begin()) == MyStruct("a", 1));
}
