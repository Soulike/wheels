#include "longest_common_sequence.h"
#include <gtest/gtest.h>

#include <algorithm>  // for std::find
#include <vector>

template <typename T>
bool isSubsequence(const std::vector<T>& sequence, const std::vector<T>& arr) {
  auto it = arr.begin();
  for (const auto& elem : sequence) {
    it = std::find(it, arr.end(), elem);
    if (it == arr.end())
      return false;
    ++it;
  }
  return true;
}

TEST(LongestCommonSequenceTest, EmptyArrays) {
  constexpr std::vector<int> arr1;
  constexpr std::vector<int> arr2;
  EXPECT_EQ(0, getLongestCommonSequenceLength(arr1, arr2));
  EXPECT_TRUE(getLongestCommonSequence(arr1, arr2).empty());
}

TEST(LongestCommonSequenceTest, OneEmptyArray) {
  const std::vector<int> arr1 = {1, 2, 3};
  constexpr std::vector<int> arr2;
  EXPECT_EQ(0, getLongestCommonSequenceLength(arr1, arr2));
  EXPECT_TRUE(getLongestCommonSequence(arr1, arr2).empty());
}

TEST(LongestCommonSequenceTest, IdenticalArrays) {
  const std::vector<int> arr1 = {1, 2, 3};
  const std::vector<int> arr2 = {1, 2, 3};
  EXPECT_EQ(3, getLongestCommonSequenceLength(arr1, arr2));
  EXPECT_EQ(arr1, getLongestCommonSequence(arr1, arr2));
}

TEST(LongestCommonSequenceTest, NoCommonSequence) {
  const std::vector<int> arr1 = {1, 2, 3};
  const std::vector<int> arr2 = {4, 5, 6};
  EXPECT_EQ(0, getLongestCommonSequenceLength(arr1, arr2));
  EXPECT_TRUE(getLongestCommonSequence(arr1, arr2).empty());
}

TEST(LongestCommonSequenceTest, PartialMatch) {
  const std::vector<int> arr1 = {1, 2, 3, 4};
  const std::vector<int> arr2 = {2, 3, 5};
  const std::vector<int> expected = {2, 3};
  EXPECT_EQ(2, getLongestCommonSequenceLength(arr1, arr2));
  EXPECT_EQ(expected, getLongestCommonSequence(arr1, arr2));
}

TEST(LongestCommonSequenceTest, DifferentOrder) {
  const std::vector<int> arr1 = {1, 2, 3};
  const std::vector<int> arr2 = {3, 2, 1};
  const auto length = getLongestCommonSequenceLength(arr1, arr2);
  const std::vector<int> lcs = getLongestCommonSequence(arr1, arr2);
  EXPECT_EQ(1, length);
  EXPECT_TRUE(isSubsequence(lcs, arr1));
  EXPECT_TRUE(isSubsequence(lcs, arr2));
}

TEST(LongestCommonSequenceTest, RepeatedElements) {
  const std::vector<int> arr1 = {1, 2, 2, 3};
  const std::vector<int> arr2 = {2, 2, 2};
  const std::vector<int> expected = {2, 2};
  EXPECT_EQ(2, getLongestCommonSequenceLength(arr1, arr2));
  EXPECT_EQ(expected, getLongestCommonSequence(arr1, arr2));
}

TEST(LongestCommonSequenceTest, StringType) {
  const std::vector<std::string> arr1 = {"apple", "banana", "cherry"};
  const std::vector<std::string> arr2 = {"banana", "cherry", "date"};
  const std::vector<std::string> expected = {"banana", "cherry"};
  EXPECT_EQ(2, getLongestCommonSequenceLength(arr1, arr2));
  EXPECT_EQ(expected, getLongestCommonSequence(arr1, arr2));
}

TEST(LongestCommonSequenceTest, CharType) {
  const std::vector<char> arr1 = {'a', 'b', 'c', 'd', 'e'};
  const std::vector<char> arr2 = {'a', 'f', 'b', 'd', 'e'};
  const std::vector<char> expected = {'a', 'b', 'd', 'e'};
  EXPECT_EQ(4, getLongestCommonSequenceLength(arr1, arr2));
  EXPECT_EQ(expected, getLongestCommonSequence(arr1, arr2));
}

TEST(LongestCommonSequenceTest, SwappedArrays) {
  const std::vector<int> arr1 = {1, 2, 3, 4, 5};
  const std::vector<int> arr2 = {3, 4, 5, 6, 7};
  const auto length1 = getLongestCommonSequenceLength(arr1, arr2);
  const std::vector<int> lcs1 = getLongestCommonSequence(arr1, arr2);
  const auto length2 = getLongestCommonSequenceLength(arr2, arr1);
  const std::vector<int> lcs2 = getLongestCommonSequence(arr2, arr1);
  EXPECT_EQ(length1, length2);
  EXPECT_EQ(lcs1, lcs2);
}

TEST(LongestCommonSequenceTest, MultiplePossibleLCS) {
  const std::vector<int> arr1 = {1, 3, 5, 4, 6};
  const std::vector<int> arr2 = {1, 5, 3, 6, 4};
  const auto length = getLongestCommonSequenceLength(arr1, arr2);
  const std::vector<int> lcs = getLongestCommonSequence(arr1, arr2);
  EXPECT_TRUE(isSubsequence(lcs, arr1));
  EXPECT_TRUE(isSubsequence(lcs, arr2));
  EXPECT_EQ(length, lcs.size());
}
