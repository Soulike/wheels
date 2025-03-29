#include "get_distinct_prime_number_factors_number.h"

size_t GetTheNumberOfDistinctPrimeNumberFactors(const std::uintmax_t number) {
  size_t number_of_factors = 0;
  auto current_number = number;
  for (std::uintmax_t i = 2; i <= current_number; i++) {
    if (current_number % i == 0) {
      // `i` must be a prime here.
      // Because if `i` is not a prime, its factors should have been divided
      // before.
      // For example, if `i` is 6, then 2 and 3 must have been divided before
      // when `i` was 2 and 3. So it is impossible for `current_number` to be
      // still able to be divided by 6.
      number_of_factors++;
      while (current_number % i == 0) {
        current_number /= i;
      }
    }
  }

  return number_of_factors;
}
