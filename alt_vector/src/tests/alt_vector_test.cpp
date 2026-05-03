#include <catch2/catch_all.hpp>

#include <alt_vector/alt_vector.h>
#include <alt_vector/construct.h>

namespace {

using FourInt32s = alt::types::AltVector<std::int32_t, 4U>;

template <typename T>
using Span = tcb::span<T>;

FourInt32s makeFourInt32s(std::initializer_list<std::int32_t> list)
{
  return alt::types::makeAltVector<4>(list);
}

template <typename InputIt>
FourInt32s makeFourInt32s(const InputIt first, const InputIt last)
{
  return alt::types::makeAltVector<4>(first, last);
}

} // namespace

SCENARIO("compact vector is trivially copyable")
{
  static_assert(std::is_trivially_copyable<FourInt32s>::value,
                "compact vector is not trivially copyable");
  static_assert(std::is_standard_layout<FourInt32s>::value,
                "compact vector is not standard layout");
}

SCENARIO("compact vector default constructor")
{
  const auto vector = FourInt32s{};
  CHECK(vector.empty());
}

SCENARIO("compact vector initializer list factory function")
{
  const auto vector = makeFourInt32s({1, 0, 1});

  REQUIRE(vector.size() == 3U);
  CHECK(vector.at(0U) == 1);
  CHECK(vector.at(1U) == 0);
  CHECK(vector.at(2U) == 1);
}

SCENARIO("compact vector iterator factory function")
{
  const auto other_vector = makeFourInt32s({1, 0, 1});
  auto vector = makeFourInt32s(other_vector.begin(), other_vector.end());

  REQUIRE(vector.size() == 3);
  CHECK(vector.at(0U) == 1);
  CHECK(vector.at(1U) == 0);
  CHECK(vector.at(2U) == 1);

  const auto trimmed_vector = makeFourInt32s(other_vector.begin(), other_vector.begin() + 1);

  REQUIRE(trimmed_vector.size() == 1U);
  CHECK(trimmed_vector.at(0U) == 1);
}

SCENARIO("compact vector assign with same value")
{
  auto vector = FourInt32s{};
  vector.assign(3U, 1);

  REQUIRE(vector.size() == 3U);
  CHECK(vector.at(0U) == 1);
  CHECK(vector.at(1U) == 1);
  CHECK(vector.at(2U) == 1);

  vector.assign(1U, 0);

  REQUIRE(vector.size() == 1U);
  CHECK(vector.at(0U) == 0);

  CHECK_THROWS_AS(vector.assign(5U, 1), std::runtime_error);
}

SCENARIO("compact vector assign with iterators")
{
  auto other_vector = makeFourInt32s({1, 0, 1});
  auto vector = FourInt32s{};
  vector.assign(other_vector.begin(), other_vector.end());

  REQUIRE(vector.size() == 3U);
  CHECK(vector.at(0U) == 1);
  CHECK(vector.at(1U) == 0);
  CHECK(vector.at(2U) == 1);
  vector.clear();

  vector.assign(other_vector.cbegin(), other_vector.cend());

  REQUIRE(vector.size() == 3U);
  CHECK(vector.at(0U) == 1);
  CHECK(vector.at(1U) == 0);
  CHECK(vector.at(2U) == 1);

  vector.assign(other_vector.begin(), other_vector.begin() + 1);

  REQUIRE(vector.size() == 1U);
  CHECK(vector.at(0U) == 1);

  std::array<std::int32_t, 5U> too_big{0, 0, 0, 0, 0};
  CHECK_THROWS_AS(vector.assign(too_big.begin(), too_big.end()),
                  std::runtime_error);

  const auto const_too_big = too_big;
  CHECK_THROWS_AS(vector.assign(const_too_big.begin(), const_too_big.end()),
                  std::runtime_error);
}

SCENARIO("compact vector assign with initializer list")
{
  auto vector = FourInt32s{};
  vector.assign({1, 0, 1});

  REQUIRE(vector.size() == 3U);
  CHECK(vector.at(0U) == 1);
  CHECK(vector.at(1U) == 0);
  CHECK(vector.at(2U) == 1);

  vector.assign({1});
  REQUIRE(vector.size() == 1U);
  CHECK(vector.at(0U) == 1);

  CHECK_THROWS_AS(vector.assign({0, 0, 0, 0, 0}), std::runtime_error);
}

SCENARIO("compact vector at operators")
{
  auto vector = makeFourInt32s({1, 0});
  const auto& const_vector = vector;

  CHECK(vector.at(0U) == 1);
  CHECK(vector.at(1U) == 0);
  CHECK_THROWS_AS(vector.at(5U), std::runtime_error);

  CHECK(const_vector.at(0U) == 1);
  CHECK(const_vector.at(1U) == 0);
  CHECK_THROWS_AS(const_vector.at(5U), std::runtime_error);
}

SCENARIO("compact vector front/back")
{
  auto vector = makeFourInt32s({1, 0});
  const auto& const_vector = vector;

  CHECK(vector.front() == 1);
  CHECK(vector.back() == 0);

  CHECK(const_vector.front() == 1);
  CHECK(const_vector.back() == 0);
}

SCENARIO("compact vector data")
{
  auto vector = makeFourInt32s({1, 0});
  const auto& const_vector = vector;

  CHECK(*vector.data() == 1);
  CHECK(*(vector.data() + 1) == 0);

  CHECK(*const_vector.data() == 1);
  CHECK(*(const_vector.data() + 1) == 0);
}

SCENARIO("compact vector view")
{
  auto vector = makeFourInt32s({1, 0});
  const auto& const_vector = vector;

  Span<std::int32_t> span = vector.view();
  CHECK(span.size() == 2);
  CHECK(span[0] == 1);
  CHECK(span[1] == 0);

  Span<const std::int32_t> const_span = const_vector.view();
  CHECK(const_span.size() == 2);
  CHECK(const_span[0] == 1);
  CHECK(const_span[1] == 0);
}

SCENARIO("compact vector begin/end")
{
  auto vector = makeFourInt32s({1, 0});
  const auto& const_vector = vector;

  // Member functions
  CHECK(vector.begin() == vector.data());
  CHECK(const_vector.begin() == const_vector.data());
  CHECK(const_vector.cbegin() == const_vector.data());

  CHECK(vector.end() == vector.data() + 2U);
  CHECK(const_vector.end() == const_vector.begin() + 2U);
  CHECK(const_vector.cend() == const_vector.begin() + 2U);

  // Reverse iterators
  CHECK(*vector.rbegin() == 0);
  CHECK(*std::next(vector.rbegin()) == 1);
  CHECK(vector.rend() == std::next(vector.rbegin(), 2));

  CHECK(*const_vector.rbegin() == 0);
  CHECK(*std::next(const_vector.rbegin()) == 1);
  CHECK(const_vector.rend() == std::next(const_vector.rbegin(), 2));

  CHECK(*const_vector.crbegin() == 0);
  CHECK(*std::next(const_vector.crbegin()) == 1);
  CHECK(const_vector.crend() == std::next(const_vector.crbegin(), 2));
}

SCENARIO("compact vector capacity")
{
  const auto empty_vector = FourInt32s{};
  const auto vector = makeFourInt32s({1, 0});

  CHECK(empty_vector.empty());
  CHECK(!vector.empty());

  // NOLINTNEXTLINE(readability-container-size-empty):P0000
  CHECK(empty_vector.size() == 0U);
  CHECK(vector.size() == 2U);

  CHECK(vector.max_size() == 4U);
  CHECK(vector.capacity() == 4U);
}

SCENARIO("compact vector capacity modifiers")
{
  auto vector = makeFourInt32s({1, 0});

  // nothing happens
  vector.reserve(4U);
  CHECK_THROWS_AS(vector.reserve(5U), std::runtime_error);
}

SCENARIO("compact vector clear")
{
  auto vector = makeFourInt32s({1, 0});

  vector.clear();
  CHECK(vector.empty());
}

SCENARIO("compact vector push_back/emplace_back")
{
  auto vector = FourInt32s{};
  std::int32_t one = 1;

  // push_back with lvalue (copy)
  vector.push_back(one);

  // push_back with rvalue (move)
  vector.push_back(2);

  // emplace_back with constructor args
  vector.emplace_back(3);
  vector.emplace_back(std::int32_t{4});

  // At this point, vector has 4 elements: [1, 2, 3, 4]
  REQUIRE(vector.size() == 4U);
  CHECK(vector.at(0U) == 1);
  CHECK(vector.at(1U) == 2);
  CHECK(vector.at(2U) == 3);
  CHECK(vector.at(3U) == 4);

  // Test overflow behavior
  std::int32_t five = 1;
  CHECK_THROWS_AS(vector.push_back(five), std::runtime_error);
  CHECK_THROWS_AS(vector.push_back(6), std::runtime_error);
  CHECK_THROWS_AS(vector.emplace_back(7), std::runtime_error);
}

SCENARIO("compact vector pop_back")
{
  auto vector = makeFourInt32s({1});

  vector.pop_back();
  CHECK(vector.empty());

  // No throw when popping from an empty vector
  vector.pop_back();
}

SCENARIO("compact vector resize")
{
  auto vector = makeFourInt32s({1, 0});

  vector.resize(3U);

  REQUIRE(vector.size() == 3U);
  CHECK(vector.at(0U) == 1);
  CHECK(vector.at(1U) == 0);
  CHECK(vector.at(2U) == 0);

  vector.resize(2U);
  CHECK(vector.size() == 2U);

  CHECK_THROWS_AS(vector.resize(5U), std::runtime_error);

  vector.resize(3U, 1);

  REQUIRE(vector.size() == 3U);
  CHECK(vector.at(0U) == 1);
  CHECK(vector.at(1U) == 0);
  CHECK(vector.at(2U) == 1);

  vector.resize(2U, 1);
  CHECK(vector.size() == 2U);

  CHECK_THROWS_AS(vector.resize(5U, 1), std::runtime_error);
}

SCENARIO("compact vector erase method")
{
  GIVEN("A AltVector with elements {1, 0, 1, 0}")
  {
    auto vector = makeFourInt32s({1, 0, 1, 0});

    REQUIRE(vector.size() == 4U);

    WHEN("erasing the first element")
    {
      vector.erase(vector.begin());

      THEN("the size decreases to 3")
      {
        REQUIRE(vector.size() == 3U);
      }

      THEN("the elements are shifted correctly")
      {
        CHECK(vector.at(0U) == 0);
        CHECK(vector.at(1U) == 1);
        CHECK(vector.at(2U) == 0);
      }
    }

    WHEN("erasing the middle element")
    {
      vector.erase(vector.begin() + 1);

      THEN("the size decreases to 3")
      {
        REQUIRE(vector.size() == 3U);
      }

      THEN("the elements are shifted correctly")
      {
        CHECK(vector.at(0U) == 1);
        CHECK(vector.at(1U) == 1);
        CHECK(vector.at(2U) == 0);
      }
    }

    WHEN("erasing the last element")
    {
      vector.erase(vector.end() - 1);

      THEN("the size decreases to 3")
      {
        REQUIRE(vector.size() == 3U);
      }

      THEN("the elements are correct")
      {
        CHECK(vector.at(0U) == 1);
        CHECK(vector.at(1U) == 0);
        CHECK(vector.at(2U) == 1);
      }
    }

    WHEN("erasing all elements one by one")
    {
      vector.erase(vector.begin());
      vector.erase(vector.begin());
      vector.erase(vector.begin());
      vector.erase(vector.begin());

      THEN("the vector is empty")
      {
        CHECK(vector.empty());
      }
    }

    WHEN("erasing an element with an invalid iterator")
    {
      THEN("an exception is thrown")
      {
        CHECK_THROWS_AS(vector.erase(vector.end()), std::runtime_error);
        CHECK_THROWS_AS(vector.erase(vector.begin() - 1), std::runtime_error);
      }
    }
  }
}

SCENARIO("compact vector equality operator with int32_t type")
{
  GIVEN("Two empty vectors")
  {
    auto vector1 = FourInt32s{};
    auto vector2 = FourInt32s{};

    THEN("They are equal")
    {
      REQUIRE(vector1 == vector2);
      REQUIRE_FALSE(vector1 != vector2);
    }
  }

  GIVEN("A vector compared with itself")
  {
    auto vector = makeFourInt32s({1, 0, 1});

    THEN("It is equal to itself")
    {
      REQUIRE(vector == vector);
      REQUIRE_FALSE(vector != vector);
    }
  }

  GIVEN("Two vectors of the same size and elements")
  {
    auto vector1 = makeFourInt32s({1, 0, 1});
    auto vector2 = makeFourInt32s({1, 0, 1});

    THEN("They are equal")
    {
      REQUIRE(vector1 == vector2);
      REQUIRE_FALSE(vector1 != vector2);
    }
  }

  GIVEN("Two vectors of different sizes")
  {
    auto vector1 = makeFourInt32s({1, 0, 1});
    auto vector2 = makeFourInt32s({1, 0, 1, 0});

    THEN("They are not equal")
    {
      REQUIRE_FALSE(vector1 == vector2);
      REQUIRE(vector1 != vector2);
    }
  }

  GIVEN("Two vectors of the same size but different elements")
  {
    auto vector1 = makeFourInt32s({1, 0, 1});
    auto vector2 = makeFourInt32s({1, 1, 0});

    THEN("They are not equal")
    {
      REQUIRE_FALSE(vector1 == vector2);
      REQUIRE(vector1 != vector2);
    }
  }
}
