#include "get_distinct_prime_number_factors_number.h"

size_t GetTheNumberOfDistinctPrimeNumberFactors(const std::uintmax_t number) {
  size_t number_of_factors = 0;
  auto current_number = number;
  for (std::uintmax_t i = 2; i <= current_number;i++) {
    if (current_number % i == 0) {
      number_of_factors++;
      while (current_number % i == 0) {
        current_number /= i;
      }
    }
  }

  return number_of_factors;
}
