#ifndef GET_DISTINCT_PRIME_NUMBER_FACTORS_NUMBER_H
#define GET_DISTINCT_PRIME_NUMBER_FACTORS_NUMBER_H

#include <cinttypes>
#include <cstddef>

/**
 * @returns The number of prime numbers whose product is `number`.
 * For example, 300 = 2 x 2 x 3 x 5 x 5, so the return value for 300 is 3 (2, 3,
 * 5).
 */
size_t GetTheNumberOfDistinctPrimeNumberFactors(std::uintmax_t number);

#endif  // GET_DISTINCT_PRIME_NUMBER_FACTORS_NUMBER_H
