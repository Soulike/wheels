#include "get_nth_element.h"

#include <algorithm>
#include <cstdint>
#include <random>
#include <vector>

#include <gtest/gtest.h>

TEST(GetNthElementTest, SingleElement) {
  std::vector<int> vec{42};
  auto it = GetNthElement(0, vec.begin(), vec.end());
  ASSERT_EQ(it, vec.begin());
  EXPECT_EQ(*it, 42);
}

TEST(GetNthElementTest, TwoElementsSorted) {
  std::vector<int> vec{1, 2};
  auto it0 = GetNthElement(0, vec.begin(), vec.end());
  EXPECT_EQ(it0, vec.begin());
  EXPECT_EQ(*it0, 1);

  auto it1 = GetNthElement(1, vec.begin(), vec.end());
  EXPECT_EQ(it1, vec.begin() + 1);
  EXPECT_EQ(*it1, 2);
}

TEST(GetNthElementTest, TwoElementsReversed) {
  std::vector<int> vec{2, 1};
  auto it0 = GetNthElement(0, vec.begin(), vec.end());
  EXPECT_EQ(it0, vec.begin());
  EXPECT_EQ(*it0, 1);

  auto it1 = GetNthElement(1, vec.begin(), vec.end());
  EXPECT_EQ(it1, vec.begin() + 1);
  EXPECT_EQ(*it1, 2);
}

TEST(GetNthElementTest, MultipleElements) {
  std::vector<int> vec{5, 3, 1, 4, 2};
  const std::uint64_t n = 2;
  auto it = GetNthElement(n, vec.begin(), vec.end());
  EXPECT_EQ(*it, 3);
  EXPECT_EQ(it, vec.begin() + n);

  // Check partitioning around the nth element
  for (auto i = vec.begin(); i != it; ++i) {
    ASSERT_LE(*i, *it);
  }
  for (auto i = it + 1; i != vec.end(); ++i) {
    ASSERT_GE(*i, *it);
  }
}

TEST(GetNthElementTest, WithDuplicates) {
  std::vector<int> vec{2, 3, 1, 2, 3};
  const std::uint64_t n = 2;
  auto it = GetNthElement(n, vec.begin(), vec.end());
  EXPECT_EQ(*it, 2);
  EXPECT_EQ(it, vec.begin() + n);
}

TEST(GetNthElementTest, AllElementsSame) {
  std::vector<int> vec{5, 5, 5, 5};
  const std::uint64_t n = 2;
  auto it = GetNthElement(n, vec.begin(), vec.end());
  EXPECT_EQ(*it, 5);
  EXPECT_EQ(it, vec.begin() + n);
}

TEST(GetNthElementTest, LargestElement) {
  std::vector<int> vec{1, 3, 5, 2, 4};
  const std::uint64_t n = 4;
  auto it = GetNthElement(n, vec.begin(), vec.end());
  EXPECT_EQ(*it, 5);
  EXPECT_EQ(it, vec.begin() + n);
}

TEST(GetNthElementTest, SmallestElement) {
  std::vector<int> vec{4, 2, 5, 1, 3};
  const std::uint64_t n = 0;
  auto it = GetNthElement(n, vec.begin(), vec.end());
  EXPECT_EQ(*it, 1);
  EXPECT_EQ(it, vec.begin() + n);
}

TEST(GetNthElementTest, LargeVector) {
  std::vector<int> vec;
  const int size = 1000;
  for (int i = 0; i < size; ++i) {
    vec.push_back(i);
  }
  std::shuffle(vec.begin(), vec.end(), std::mt19937{std::random_device{}()});
  const std::uint64_t n = 500;
  auto it = GetNthElement(n, vec.begin(), vec.end());
  EXPECT_EQ(*it, static_cast<int>(n));
  EXPECT_EQ(it, vec.begin() + n);
}

TEST(GetNthElementTest, CompareWithStdNthElement) {
  std::vector<int> vec{9, 3, 6, 2, 1, 7, 4, 8, 5};
  const std::uint64_t n = 4;
  std::vector<int> vec_std = vec;

  std::nth_element(vec_std.begin(), vec_std.begin() + n, vec_std.end());
  int expected_value = vec_std[n];

  auto it = GetNthElement(n, vec.begin(), vec.end());
  EXPECT_EQ(*it, expected_value);
  EXPECT_EQ(it, vec.begin() + n);
}
