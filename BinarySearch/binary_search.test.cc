#include "binary_search.h"
#include <gtest/gtest.h>
#include <vector>

TEST(BinarySearchTest, TargetInMiddle) {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result = binarySearch(vec.begin(), vec.end(), 5);
  EXPECT_NE(result, vec.end());
  EXPECT_EQ(*result, 5);
}

TEST(BinarySearchTest, TargetAtBeginning) {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result = binarySearch(vec.begin(), vec.end(), 1);
  EXPECT_NE(result, vec.end());
  EXPECT_EQ(*result, 1);
}

TEST(BinarySearchTest, TargetAtEnd) {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result = binarySearch(vec.begin(), vec.end(), 10);
  EXPECT_NE(result, vec.end());
  EXPECT_EQ(*result, 10);
}

TEST(BinarySearchTest, TargetNotInList) {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result = binarySearch(vec.begin(), vec.end(), 11);
  EXPECT_EQ(result, vec.end());
}

TEST(BinarySearchTest, EmptyList) {
  std::vector<int> emptyVec;
  auto result = binarySearch(emptyVec.begin(), emptyVec.end(), 1);
  EXPECT_EQ(result, emptyVec.end());
}

TEST(UpperBoundTest, TargetInMiddle) {
  std::vector<int> vec = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result = upperBound(vec.begin(), vec.end(), 2);
  EXPECT_NE(result, vec.end());
  EXPECT_EQ(*result, 3);
}

TEST(UpperBoundTest, TargetAtBeginning) {
  std::vector<int> vec = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result = upperBound(vec.begin(), vec.end(), 1);
  EXPECT_NE(result, vec.end());
  EXPECT_EQ(*result, 2);
}

TEST(UpperBoundTest, TargetAtEnd) {
  std::vector<int> vec = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result = upperBound(vec.begin(), vec.end(), 10);
  EXPECT_EQ(result, vec.end());
}

TEST(UpperBoundTest, TargetNotInList) {
  std::vector<int> vec = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result = upperBound(vec.begin(), vec.end(), 11);
  EXPECT_EQ(result, vec.end());
}

TEST(UpperBoundTest, EmptyList) {
  std::vector<int> emptyVec;
  auto result = upperBound(emptyVec.begin(), emptyVec.end(), 1);
  EXPECT_EQ(result, emptyVec.end());
}

TEST(LowerBoundTest, TargetInMiddle) {
  std::vector<int> vec = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result = lowerBound(vec.begin(), vec.end(), 2);
  EXPECT_NE(result, vec.end());
  EXPECT_EQ(*result, 2);
}

TEST(LowerBoundTest, TargetAtBeginning) {
  std::vector<int> vec = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result = lowerBound(vec.begin(), vec.end(), 1);
  EXPECT_NE(result, vec.end());
  EXPECT_EQ(*result, 1);
}

TEST(LowerBoundTest, TargetAtEnd) {
  std::vector<int> vec = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result = lowerBound(vec.begin(), vec.end(), 10);
  EXPECT_NE(result, vec.end());
  EXPECT_EQ(*result, 10);
}

TEST(LowerBoundTest, TargetNotInList) {
  std::vector<int> vec = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto result = lowerBound(vec.begin(), vec.end(), 11);
  EXPECT_EQ(result, vec.end());
}

TEST(LowerBoundTest, EmptyList) {
  std::vector<int> emptyVec;
  auto result = lowerBound(emptyVec.begin(), emptyVec.end(), 1);
  EXPECT_EQ(result, emptyVec.end());
}
