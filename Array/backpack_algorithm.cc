#include "backpack_algorithm.h"

std::uint64_t Knapsack(const std::uint64_t capacity,
                       const std::uint64_t n,
                       const std::vector<std::uint64_t>& weights,
                       const std::vector<std::uint64_t>& values) {
  std::vector<std::vector<std::uint64_t>> dp(
      2, std::vector<std::uint64_t>(capacity + 1, 0));
  for (std::uint64_t i = 1; i <= n; i++) {
    for (std::uint64_t c = 1; c <= capacity; c++) {
      dp[i % 2][c] = dp[(i - 1) % 2][c];
      if (weights[i - 1] <= c) {
        dp[i % 2][c] = std::max(
            dp[i % 2][c], dp[(i - 1) % 2][c - weights[i - 1]] + values[i - 1]);
      }
    }
  }

  return dp[n % 2][capacity];
}
