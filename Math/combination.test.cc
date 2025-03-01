#include "combination.h"
#include <gtest/gtest.h>

TEST(CombinationTest, ZeroSelection) {
  EXPECT_EQ(combination(5, 0), 1u);
  EXPECT_EQ(combination(0, 0), 1u);
  EXPECT_EQ(combination(100, 0), 1u);
}

TEST(CombinationTest, FullSelection) {
  EXPECT_EQ(combination(5, 5), 1u);
  EXPECT_EQ(combination(10, 10), 1u);
  EXPECT_EQ(combination(1, 1), 1u);
}

TEST(CombinationTest, SingleSelection) {
  EXPECT_EQ(combination(5, 1), 5u);
  EXPECT_EQ(combination(10, 1), 10u);
  EXPECT_EQ(combination(1, 1), 1u);
}

TEST(CombinationTest, RegularCases) {
  EXPECT_EQ(combination(5, 2), 10u);    // C(5,2) = 10
  EXPECT_EQ(combination(10, 3), 120u);  // C(10,3) = 120
  EXPECT_EQ(combination(6, 3), 20u);    // C(6,3) = 20
  EXPECT_EQ(combination(7, 4), 35u);    // C(7,4) = 35
}

TEST(CombinationTest, EdgeCases) {
  EXPECT_EQ(combination(0, 0), 1u);  // C(0,0) = 1
  EXPECT_EQ(combination(1, 0), 1u);  // C(1,0) = 1
}
