#include "backpack_algorithm.h"
#include <gtest/gtest.h>
#include <vector>

class KnapsackTest : public ::testing::Test {};

// Basic test case with small inputs
TEST_F(KnapsackTest, BasicTest) {
  const std::vector<std::uint64_t> weights = {2, 3, 4, 5};
  const std::vector<std::uint64_t> values = {3, 4, 5, 6};
  constexpr std::uint64_t capacity = 5;
  constexpr std::uint64_t n = 4;

  const std::uint64_t result = Knapsack(capacity, n, weights, values);
  EXPECT_EQ(
      result,
      7);  // Expect max value of 7 (items with weights 2,3 and values 3,4)
}

// Test with zero capacity
TEST_F(KnapsackTest, ZeroCapacity) {
  const std::vector<std::uint64_t> weights = {1, 2, 3};
  const std::vector<std::uint64_t> values = {10, 20, 30};
  constexpr std::uint64_t capacity = 0;
  constexpr std::uint64_t n = 3;

  const std::uint64_t result = Knapsack(capacity, n, weights, values);
  EXPECT_EQ(result, 0);  // With zero capacity, can't pick any items
}

// Test with no items
TEST_F(KnapsackTest, NoItems) {
  const std::vector<std::uint64_t> weights = {};
  const std::vector<std::uint64_t> values = {};
  constexpr std::uint64_t capacity = 10;
  constexpr std::uint64_t n = 0;

  const std::uint64_t result = Knapsack(capacity, n, weights, values);
  EXPECT_EQ(result, 0);  // With no items, total value should be 0
}

// Test with a single item that fits
TEST_F(KnapsackTest, SingleItemFits) {
  const std::vector<std::uint64_t> weights = {5};
  const std::vector<std::uint64_t> values = {10};
  constexpr std::uint64_t capacity = 10;
  constexpr std::uint64_t n = 1;

  const std::uint64_t result = Knapsack(capacity, n, weights, values);
  EXPECT_EQ(result, 10);  // Single item fits, so its value should be returned
}

// Test with a single item that doesn't fit
TEST_F(KnapsackTest, SingleItemDoesNotFit) {
  const std::vector<std::uint64_t> weights = {15};
  const std::vector<std::uint64_t> values = {10};
  constexpr std::uint64_t capacity = 10;
  constexpr std::uint64_t n = 1;

  const std::uint64_t result = Knapsack(capacity, n, weights, values);
  EXPECT_EQ(result, 0);  // Item doesn't fit, so value should be 0
}

// Test with all items fitting exactly
TEST_F(KnapsackTest, AllItemsExactFit) {
  const std::vector<std::uint64_t> weights = {1, 2, 3, 4};
  const std::vector<std::uint64_t> values = {10, 20, 30, 40};
  constexpr std::uint64_t capacity = 10;  // Sum of all weights
  constexpr std::uint64_t n = 4;

  const std::uint64_t result = Knapsack(capacity, n, weights, values);
  EXPECT_EQ(result,
            100);  // All items should be selected for a total value of 100
}

// Test with equal weights but different values
TEST_F(KnapsackTest, EqualWeightsDifferentValues) {
  const std::vector<std::uint64_t> weights = {5, 5, 5, 5};
  const std::vector<std::uint64_t> values = {10, 40, 30, 20};
  constexpr std::uint64_t capacity = 10;
  constexpr std::uint64_t n = 4;

  const std::uint64_t result = Knapsack(capacity, n, weights, values);
  EXPECT_EQ(result, 70);  // Should select the items with values 40 and 30
}

// Test with different weights but equal values
TEST_F(KnapsackTest, DifferentWeightsEqualValues) {
  const std::vector<std::uint64_t> weights = {1, 2, 3, 4};
  const std::vector<std::uint64_t> values = {10, 10, 10, 10};
  constexpr std::uint64_t capacity = 7;
  constexpr std::uint64_t n = 4;

  const std::uint64_t result = Knapsack(capacity, n, weights, values);
  EXPECT_EQ(result, 30);  // Should select items with weights 1, 2, 3 (total
                          // weight=6, value=30)
}

// Test with large capacity
TEST_F(KnapsackTest, LargeCapacity) {
  const std::vector<std::uint64_t> weights = {1, 2, 3};
  const std::vector<std::uint64_t> values = {10, 20, 30};
  constexpr std::uint64_t capacity = 1000;
  constexpr std::uint64_t n = 3;

  const std::uint64_t result = Knapsack(capacity, n, weights, values);
  EXPECT_EQ(result, 60);  // All items should fit with room to spare
}

// Test with the classic knapsack example
TEST_F(KnapsackTest, ClassicExample) {
  const std::vector<std::uint64_t> weights = {1, 3, 4, 5};
  const std::vector<std::uint64_t> values = {1, 4, 5, 7};
  constexpr std::uint64_t capacity = 7;
  constexpr std::uint64_t n = 4;

  const std::uint64_t result = Knapsack(capacity, n, weights, values);
  EXPECT_EQ(result, 9);  // Optimal selection should yield value of 9
}

// Test with high value but high weight items
TEST_F(KnapsackTest, HighValueHighWeight) {
  const std::vector<std::uint64_t> weights = {10, 20, 30};
  const std::vector<std::uint64_t> values = {60, 100, 120};
  constexpr std::uint64_t capacity = 50;
  constexpr std::uint64_t n = 3;

  const std::uint64_t result = Knapsack(capacity, n, weights, values);
  EXPECT_EQ(result,
            220);  // Should select items with weights 20,30 and values 100,120
}

// Test with a large number of items
TEST_F(KnapsackTest, LargeNumberOfItems) {
  const std::vector<std::uint64_t> weights(100, 1);  // 100 items with weight 1
  const std::vector<std::uint64_t> values(100, 1);   // 100 items with value 1
  constexpr std::uint64_t capacity = 50;
  constexpr std::uint64_t n = 100;

  const std::uint64_t result = Knapsack(capacity, n, weights, values);
  EXPECT_EQ(result,
            50);  // Should be able to pick exactly 50 items with value 1 each
}
