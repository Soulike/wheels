#include "find_majority_element.h"
#include <gtest/gtest.h>
#include <algorithm>
#include <list>
#include <optional>
#include <random>
#include <string>
#include <vector>

class FindMajorityElementTest : public ::testing::Test {};

// Test with integer vectors
TEST_F(FindMajorityElementTest, IntegerVectorWithMajority) {
  std::vector<int> nums = {3, 2, 3, 2, 3, 3, 2};
  auto result = FindMajorityElement(nums.begin(), nums.end());
  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(result.value(), 3);
}

TEST_F(FindMajorityElementTest, IntegerVectorWithoutMajority) {
  std::vector<int> nums = {3, 2, 3, 2};
  auto result = FindMajorityElement(nums.begin(), nums.end());
  EXPECT_FALSE(result.has_value());
}

TEST_F(FindMajorityElementTest, EmptyVector) {
  std::vector<int> nums;
  auto result = FindMajorityElement(nums.begin(), nums.end());
  EXPECT_FALSE(result.has_value());
}

TEST_F(FindMajorityElementTest, SingleElementVector) {
  std::vector<int> nums = {42};
  auto result = FindMajorityElement(nums.begin(), nums.end());
  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(result.value(), 42);
}

// Test with other STL containers
TEST_F(FindMajorityElementTest, ListContainer) {
  std::list<int> nums = {1, 2, 1, 1, 2, 1};
  auto result = FindMajorityElement(nums.begin(), nums.end());
  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(result.value(), 1);
}

// Test with string type
TEST_F(FindMajorityElementTest, StringVector) {
  std::vector<std::string> strs = {"apple", "banana", "apple", "apple"};
  auto result = FindMajorityElement(strs.begin(), strs.end());
  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(result.value(), "apple");
}

// Test with custom type
struct Person {
  std::string name;
  int age;

  bool operator==(const Person& other) const {
    return name == other.name && age == other.age;
  }
};

TEST_F(FindMajorityElementTest, CustomTypeVector) {
  std::vector<Person> people = {
      {"Alice", 30}, {"Bob", 25}, {"Alice", 30}, {"Alice", 30}};

  auto result = FindMajorityElement(people.begin(), people.end());
  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(result.value().name, "Alice");
  EXPECT_EQ(result.value().age, 30);
}

// Test with partial ranges
TEST_F(FindMajorityElementTest, PartialRangeWithMajority) {
  std::vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
  // Only consider elements from index 2 to 8, which would be {4, 2, 4, 4, 2, 4,
  // 4}
  auto result = FindMajorityElement(nums.begin() + 2, nums.end());
  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(result.value(), 4);
}

// Test with large dataset
TEST_F(FindMajorityElementTest, LargeDataset) {
  std::vector<int> nums(10000, 5);  // 10000 elements all equal to 5

  // Add 5000 different elements (still less than the majority)
  for (int i = 0; i < 5000; i++) {
    nums.push_back(i);
  }

  // Shuffle the vector
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(nums.begin(), nums.end(), g);

  auto result = FindMajorityElement(nums.begin(), nums.end());
  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(result.value(), 5);
}

// Edge cases
TEST_F(FindMajorityElementTest, ExactlyHalf) {
  std::vector<int> nums = {1, 2, 1, 2};  // No majority element - exactly 50%
  auto result = FindMajorityElement(nums.begin(), nums.end());
  EXPECT_FALSE(result.has_value());
}

TEST_F(FindMajorityElementTest, JustOverHalf) {
  std::vector<int> nums = {1, 2, 1, 2, 1};  // 3/5 elements are 1
  auto result = FindMajorityElement(nums.begin(), nums.end());
  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(result.value(), 1);
}
