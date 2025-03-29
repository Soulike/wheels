#include "get_distinct_prime_number_factors_number.h"
#include <gtest/gtest.h>

TEST(GetTheNumberOfDistinctPrimeNumberFactorsTest, PrimeNumber) {
  EXPECT_EQ(GetTheNumberOfDistinctPrimeNumberFactors(7), 1);  // 7 is a prime number
}

TEST(GetTheNumberOfDistinctPrimeNumberFactorsTest, CompositeNumber) {
  EXPECT_EQ(GetTheNumberOfDistinctPrimeNumberFactors(300), 3);  // 300 = 2 * 3 * 5
}

TEST(GetTheNumberOfDistinctPrimeNumberFactorsTest, One) {
  EXPECT_EQ(GetTheNumberOfDistinctPrimeNumberFactors(1), 0);  // 1 has no prime factors
}

TEST(GetTheNumberOfDistinctPrimeNumberFactorsTest, Zero) {
  EXPECT_EQ(GetTheNumberOfDistinctPrimeNumberFactors(0), 0);  // 0 has no prime factors
}

TEST(GetTheNumberOfDistinctPrimeNumberFactorsTest, LargeNumber) {
  EXPECT_EQ(GetTheNumberOfDistinctPrimeNumberFactors(1000000), 2);  // 1000000 = 2^6 * 5^6
}

TEST(GetTheNumberOfDistinctPrimeNumberFactorsTest, SquareOfPrime) {
  EXPECT_EQ(GetTheNumberOfDistinctPrimeNumberFactors(49), 1);  // 49 = 7 * 7
}

TEST(GetTheNumberOfDistinctPrimeNumberFactorsTest, ProductOfTwoPrimes) {
  EXPECT_EQ(GetTheNumberOfDistinctPrimeNumberFactors(15), 2);  // 15 = 3 * 5
}

TEST(GetTheNumberOfDistinctPrimeNumberFactorsTest, ProductOfThreePrimes) {
  EXPECT_EQ(GetTheNumberOfDistinctPrimeNumberFactors(30), 3);  // 30 = 2 * 3 * 5
}
