#ifndef LONGEST_COMMON_SEQUENCE_H
#define LONGEST_COMMON_SEQUENCE_H

#include <algorithm>
#include <vector>

template <typename T>
size_t getLongestCommonSequenceLength(const std::vector<T>& arr1,
                                      const std::vector<T>& arr2) {
  const size_t arr1Size = arr1.size();
  const size_t arr2Size = arr2.size();

  // Definition
  // dp[i][j]: The LCS of arr1[0...i-1] and arr2[0...j-1]
  //
  // Base Case
  // dp[0][...] = 0
  // dp[...][0] = 0
  //
  // Formula
  // if arr1[i-1] == arr2[j-1], dp[i][j] = dp[i-1][j-1] + 1;
  // else, dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]).
  // Since dp[i-1][j-1] always smaller than the other ones, we can simplify
  // it into dp[i][j] = max(dp[i-1][j], dp[i][j-1]).
  //
  // Result
  // dp[arr1Size][arr2Size].
  std::vector<std::vector<size_t>> dp(arr1Size + 1,
                                      std::vector<size_t>(arr2Size + 1, 0));
  for (size_t i = 1; i <= arr1Size; i++) {
    for (size_t j = 1; j <= arr2Size; j++) {
      if (arr1[i - 1] == arr2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[arr1Size][arr2Size];
}

template <typename T>
std::vector<T> getLongestCommonSequence(const std::vector<T>& arr1,
                                        const std::vector<T>& arr2) {
  const size_t arr1Size = arr1.size();
  const size_t arr2Size = arr2.size();
  std::vector<std::vector<size_t>> dp(arr1Size + 1,
                                      std::vector<size_t>(arr2Size + 1, 0));
  for (size_t i = 1; i <= arr1Size; i++) {
    for (size_t j = 1; j <= arr2Size; j++) {
      if (arr1[i - 1] == arr2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  std::vector<T> lcs;
  lcs.reserve(dp[arr1Size][arr2Size]);
  size_t i = arr1Size;
  size_t j = arr2Size;
  while (i > 0 && j > 0) {
    if (arr1[i - 1] == arr2[j - 1]) {
      lcs.push_back(arr1[i - 1]);
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  std::reverse(lcs.begin(), lcs.end());
  return lcs;
}

#endif  // LONGEST_COMMON_SEQUENCE_H
